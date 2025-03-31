#include "RUtil/Hitbox.hpp"

namespace RUtil{
Hitbox::Hitbox(float x,float y,float height,float width)
                    :x(x),y(y),height(height),width(width){
    this->cx=x+width/2.0F;
    this->cy=y+height/2.0F;
    this->just_hovered=this->click_stared=this->clicked=this->hovered=false;
}
void Hitbox::update(){
    //hover check
    just_hovered=false;
    if(!hovered) just_hovered=true;
    hovered = x<=nx&&nx<=x+width&&y<=ny&&ny<=y+height;
    if(!hovered) just_hovered=false;
    //click check
    if(hovered&&just_clicked)
        this->click_stared=true;
    else if(clicked){
        clicked=false;
    }else if(click_stared&&just_released){
        click_stared=false;
        if(hovered) clicked=true;
    }
}
void Hitbox::move(float center_x,float center_y){
    this->cx=center_x;
    this->cy=center_y;
    this->x=this->cx-this->width/2.0F;
    this->y=this->cy-this->height/2.0F;
}
const int &Hitbox::nx=RUtil::Game_Input::getX(),&Hitbox::ny=RUtil::Game_Input::getY();   
}