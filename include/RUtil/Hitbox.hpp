#ifndef RUTIL_HITBOX_HPP
#define RUTIL_HITBOX_HPP
#include "RUtil/Game_Input.hpp"
namespace RUtil{
class Hitbox{
public:
    Hitbox(float x,float y,float height,float width);
    ~Hitbox()=default;
    const bool&JustHovered()const {return just_hovered;}
    const bool&Hovered()const {return hovered;}
    const bool&ClickStared()const{return click_stared;}
    const bool&Clicked()const{return clicked;}
    void update();
    void move(float center_x,float center_y);
private:
    static const int &nx,&ny;
    const bool &just_clicked=RUtil::Game_Input::just_clicked(),&just_released=RUtil::Game_Input::just_released();
    float x,y,height,width,cx,cy;
    bool just_hovered,hovered,click_stared,clicked;
};
}
#endif