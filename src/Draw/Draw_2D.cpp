#include "Draw/Draw_2D.hpp"
#include "Util/Logger.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "config.hpp"
namespace Draw {
    Draw_2D::Draw_2D(const int size,const std::shared_ptr<Core::Program> &program){
        int len;
        if(size>4095){
            LOG_WARN("Size is bigger than 4095, so set to 4095");
            len=4095*6;
            max_len=4095*20;
        }else{
            len=size*6;
            max_len=size*20;
        }
        //4 pos.x 4 pos.y 4 color 4 u 4 v
        //total 20
        //Init member
        NowProgram=program==nullptr?DefaultProgram:program;
        SetColor(Util::Colors::WHITE);
        m_Transform=u_Combine=glm::mat4(1.0F);
        m_Projection=glm::ortho<float>(0.0F,(float)WINDOW_WIDTH,0.0F,(float)WINDOW_HEIGHT,0.0F,1.0F);
        NowProgram->Bind();//test if not bind
        CombineMatrixPos=glGetUniformLocation(NowProgram->GetId(),"u_projTrans");//Note:Here should be wrapped, if have time.
        Sampler2DPos=glGetUniformLocation(NowProgram->GetId(),"u_texture");
        vertices.reserve(max_len);
        //set idx
        std::vector<GLushort> Indices(len);
        GLushort j=0;
        //0 1 2
        //2 3 0
        for(int i=0;i<len;i+=6,j+=(GLushort)4){
            Indices[i]=j;
            Indices[i+1]=j+(GLushort)1;
            Indices[i+2]=j+(GLushort)2;
            Indices[i+3]=j+(GLushort)2;
            Indices[i+4]=j+(GLushort)3;
            Indices[i+5]=j;
        }
        //gen all
        glGenBuffers(1, &m_EBO_BufferId);
        glGenBuffers(1, &m_VBO_BufferId);
        glGenVertexArrays(1, &m_ArrayId);
        //bind all
        glBindVertexArray(m_ArrayId);
        glBindBuffer(GL_ARRAY_BUFFER,m_VBO_BufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO_BufferId);
        //set indices
        //just need set once
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(Indices.size() * sizeof(GLushort)), Indices.data(), GL_STATIC_DRAW);
        //set vbo size
        glBufferData(GL_ARRAY_BUFFER,max_len*sizeof(GLfloat),NULL,GL_DYNAMIC_DRAW);
        //set vao, also jsut need once
        // x(float) y(float) color(float) u(float) v(float)
        //set pos
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        //set color
        //normalize//note:test what happend if not do this.//note:test what different between unsigned_byte and byte.
        glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, 5 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat)*2));
        glEnableVertexAttribArray(1);
        //set uv
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat)*3));
        glEnableVertexAttribArray(2);
        //unbind vao
        glBindVertexArray(0);
    }
    Draw_2D::~Draw_2D(){
        glDeleteVertexArrays(1, &m_ArrayId);
        glDeleteBuffers(1, &m_EBO_BufferId);
        glDeleteBuffers(1, &m_VBO_BufferId);
    }

    void Draw_2D::SetColor(int r,int g,int b,int a){SetColor(Uint32(r<<24|g<<16|b<<8|a));}
    void Draw_2D::SetColor(Util::Colors color){SetColor(Uint32(color)<<8|255);}
    void Draw_2D::SetColor(Uint32 color){
        memcpy(&this->color,&color,sizeof(Uint32));
    }
    void Draw_2D::SetProjection(const glm::mat4&projection){
        this->m_Projection=projection;
        SetCombine();
    }
    void Draw_2D::SetTransform(const glm::mat4&transform){
        this->m_Transform=transform;
        SetCombine();
    }

    void Draw_2D::begin(){
        if(drawing){
            LOG_ERROR("end must be called before begin");
        }else{
            drawing=true;
            SetCombine();
        }
    }
    void Draw_2D::end(){
        if(!drawing){
            LOG_ERROR("begin must be called before end");
        }else{
            if(idx>0) this->flush();
            drawing=false;
            NowProgram->Unbind();
        }
    }
    void Draw_2D::SetCombine(){
        this->u_Combine=m_Projection*m_Transform;
        this->NowProgram->Bind();
        glUniformMatrix4fv(CombineMatrixPos,1,GL_FALSE,glm::value_ptr(u_Combine));
        glUniform1i(Sampler2DPos,SLOTPOS);//slot 0
        glActiveTexture(GL_TEXTURE0);//set now using slot
    }
    void Draw_2D::flush(){
        if(idx>0){
            int IndicesLen=idx/20*6;
            LastTexture->Bind();//flush is private, make sure here is not nullptr
            glBindBuffer(GL_ARRAY_BUFFER,m_VBO_BufferId);
            glBufferSubData(GL_ARRAY_BUFFER, 0, static_cast<GLsizeiptr>(idx * sizeof(GLfloat)), vertices.data());
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO_BufferId);
            glBindVertexArray(m_ArrayId);
            glDrawElements(GL_TRIANGLES, IndicesLen, GL_UNSIGNED_SHORT, 0);
            glBindVertexArray(0);
            idx=0;
        }
    }
    void Draw_2D::SwitchTexture(const std::shared_ptr<ReTexture> &texture){
        flush();
        this->LastTexture=texture;
    }
    /*ここからはdrawの関数です*/
    void Draw_2D::draw(  const std::shared_ptr<ReTexture> &texture, 
                const float x,const float y,
                const float w,const float h){
        if(!drawing){
            LOG_ERROR("Please call begin() before draw()");
        }else{
            if(texture!=LastTexture)
                SwitchTexture(texture);
            else if(idx==max_len) 
                flush();
            
            //x y color u v
            //now using:
            //(0,0) (1,0)
            //(0,1) (1,1)
            //opengl using:
            //(0,1) (1,1)
            //(0,0) (1,0)
            //u=1-u;
            vertices[idx]=x;
            vertices[idx+1]=y;
            vertices[idx+2]=color;
            vertices[idx+3]=0.0F;
            vertices[idx+4]=1.0F;
            vertices[idx+5]=x;
            vertices[idx+6]=y+h;
            vertices[idx+7]=color;
            vertices[idx+8]=0.0F;
            vertices[idx+9]=0.0F;
            vertices[idx+10]=x+w;
            vertices[idx+11]=y+h;
            vertices[idx+12]=color;
            vertices[idx+13]=1.0F;
            vertices[idx+14]=0.0F;
            vertices[idx+15]=x+w;
            vertices[idx+16]=y;
            vertices[idx+17]=color;
            vertices[idx+18]=1.0F;
            vertices[idx+19]=1.0F;
            idx+=20;
        }
    }
}