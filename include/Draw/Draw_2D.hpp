#pragma once

#include <memory>
#include <vector>
#include <SDL_stdinc.h>
#include <glm/mat4x4.hpp>

//fwd decl
namespace Util{
enum class Colors : Uint32;
} 
namespace Core{
    class Program;
}
namespace Draw{
    class ReTexture;
    class Image_Region;
}

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

    void SetColor(float r,float g,float b,float a=1.0F);
    void SetColor(int r,int g,int b,int a=255);
    void SetColor(Util::Colors color);
    void SetColor(Util::Colors color,int a);
    void SetColor(Util::Colors color,float a);
    void SetColor(Uint32 color,float a);
    void SetColor(Uint32 color);
    void SetColor_RGBA(Uint32 color);
    void SetProjection(const glm::mat4&projection);
    void SetTransform(const glm::mat4&transform);
    void DisableBlending();
    void EnableBlending();
    void SetBlendFunc(int src,int dst);
    void begin();
    void end();
    /**
     * @brief Draw the texture on the window.
     * @param x the pos.x of the texture on window(0 is on the left)
     * @param y the pos.y of the texture on window(0 is on the down)
     * @param w the width of the texture on window
     * @param h the height of the texture on window
    */
    void draw(  const std::shared_ptr<ReTexture> &texture, 
                const float x,const float y);
    void draw(  const std::shared_ptr<ReTexture> &texture, 
                const float x,const float y,
                const float w,const float h);
    void draw(  const std::shared_ptr<ReTexture> &texture, 
        const float x,const float y,
        const float w,const float h,
        const float rotate,const float origin_x,const float origin_y,
        const float scale_x=1.0F,const float scale_y=1.0F);
    
    void draw(  const std::shared_ptr<Image_Region> &RegionTexture, 
        const float x,const float y);
    void draw(  const std::shared_ptr<Image_Region> &RegionTexture, 
        const float x,const float y,
        const float w,const float h);
    void draw(const std::shared_ptr<Image_Region> &RegionTexture, 
        const float x,const float y,
        const float w,const float h,
        const float rotate,const float origin_x,const float origin_y,
        const float scale_x=1.0F,const float scale_y=1.0F);
private:
    void SwitchTexture(const std::shared_ptr<ReTexture> &texture);
    void flush();
    void SetCombine();
    void SetVert(const float x,const float y,const float x2,const float y2,
                 const float u,const float v,const float u2,const float v2);
    unsigned int  m_EBO_BufferId,//only have one EBO. 
            m_ArrayId,//one VAO.
            m_VBO_BufferId;//one VBO.
            //VAO VBO EBO will die after draw_2d die.

    std::shared_ptr<Core::Program> NowProgram;
    
    std::shared_ptr<ReTexture> LastTexture=nullptr;
    int idx=0,max_len;
    std::vector<float> vertices;
    float color;
    glm::mat4 m_Projection,m_Transform,u_Combine;
    bool drawing;
    int CombineMatrixPos,Sampler2DPos;
    static constexpr int SLOTPOS=0;
    bool blending_diabled;
    int blendSrc,blendDst;
};
}