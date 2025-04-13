#pragma once

#include <memory>

#include "WindowSize.hpp"
//fwd decl
namespace Draw{
    class Draw_2D;
    class ReTexture;
}

namespace Map{
class Map_dot{
public:
    //x,y are texture center
    Map_dot(float x,float y,float rotation,bool jitter);
    ~Map_dot()=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2,const float screen_offset)const;
private:
    static const std::shared_ptr<Draw::ReTexture> &dot_texture;
    float x,y,rotation;
    static constexpr float DIST_JITTER = 4.0F * Setting::SCALE;
    static constexpr float OFFSET_Y = 172.0F * Setting::SCALE;
};
}