#include "RUtil/Hitbox.hpp"
#include "RUtil/Game_Input.hpp"
namespace RUtil{
Hitbox::Hitbox(float x,float y,float height,float width)
                    :x(x),y(y),height(height),width(width){
    this->cx=x+width/2.0F;
    this->cy=y+height/2.0F;
    this->just_hovered=this->click_stared=this->clicked=this->hovered=false;
}
void Hitbox::update(){
    just_hovered=false;
    float n_x=(float)RUtil::Game_Input::getX(),n_y=(float)RUtil::Game_Input::getY();
    if(!hovered) just_hovered=true;
    hovered=x<=n_x&&n_x<=x+width&&y<=n_y&&n_y<=y+height;
    if(!hovered) just_hovered=false;

}
void Hitbox::move(float center_x,float center_y){
    this->cx=center_x;
    this->cy=center_y;
    this->x=this->cx-this->width/2.0F;
    this->y=this->cy-this->height/2.0F;
}
}