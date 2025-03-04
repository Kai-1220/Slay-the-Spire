#ifndef DRAW_DRAW_2D_HPP
#define DRAW_DRAW_2D_HPP
#include "pch.hpp"
#include "Core\Program.hpp"
#include "Util\Color.hpp"
namespace Draw {
// 
/**
 * @class Draw_2D
 * @brief Easier drawing
 * 
 * Reference from java gdx spritebatch
 * 
 * VAO + VBO + EBO
 * 
 * x y color u v
 */
class Draw_2D
{
public:
    Draw_2D(const int size=1000,const std::shared_ptr<Core::Program> &program=nullptr);
    ~Draw_2D();
    Draw_2D(const Draw_2D &) = delete;
    Draw_2D(Draw_2D &&) = delete;
    Draw_2D &operator=(const Draw_2D &) = delete;
    Draw_2D &operator=(Draw_2D &&)=delete;

    void SetColor(int r,int g,int b,int a=255);
    void SetColor(Util::Colors color);
    void SetColor(Uint32 color);

    // void begin();
private:
    GLuint  m_EBO_BufferId,//only have one EBO. 
            m_ArrayId,//one VAO.
            m_VBO_BufferId;//one VBO.
            //VAO VBO EBO will die after draw_2d die.
    std::shared_ptr<Core::Program> DefaultProgram=std::make_shared<Core::Program>(
                                                RESOURCE_DIR "/shader/java/default/default.vert",
                                                RESOURCE_DIR "/shader/java/default/default.frag");
    std::shared_ptr<Core::Program> NowProgram;
    
    GLuint LastTexture=0;
    int idx=0,max_len;
    GLfloat color;
    // glm::mat4 m_Projection(1.0F),m_Transform(1.0F),u_Combine(1.0F);
    bool drawing=false;

};
}
#endif