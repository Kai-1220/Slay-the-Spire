#pragma once

#include <memory>

#include "RUtil/Hitbox.hpp"

//fwd decl
namespace Draw{
    class Draw_2D;
}

namespace Button
{
//This class only provides the hitbox.
class Buttons
{
public:
    Buttons(const float hb_x,const float hb_y,const float hb_w,const float hb_h):hb(hb_x,hb_y,hb_w,hb_h){};
    virtual ~Buttons()=default;
    virtual void update()=0;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    bool Clicked()const{return hb.Clicked();}
protected:
    RUtil::Hitbox hb;
};
} // namespace Button
