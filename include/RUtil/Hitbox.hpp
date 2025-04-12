#ifndef RUTIL_HITBOX_HPP
#define RUTIL_HITBOX_HPP
#include "RUtil/Game_Input.hpp"
namespace RUtil{
class Hitbox{
public:
    Hitbox(float x,float y,float width,float height,bool isCenter=false);
    Hitbox(float width,float height);
    ~Hitbox()=default;
    const bool&JustHovered()const {return just_hovered;}
    const bool&Hovered()const {return hovered;}
    const bool&ClickStared()const{return click_stared;}
    const bool&Clicked()const{return clicked;}
    void update();
    void move(float center_x,float center_y);
    void UnHovered(){hovered=false;}
private:
    static const int &nx,&ny;
    static const bool &just_clicked,&just_released;
    float x,y,width,height,cx,cy;
    bool just_hovered,hovered,click_stared,clicked;
};
}
#endif