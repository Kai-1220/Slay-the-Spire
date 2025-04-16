#pragma once

namespace RUtil{
class Hitbox{
public:
    Hitbox(float x,float y,float width,float height,bool isCenter=false);
    Hitbox(float width,float height);
    ~Hitbox()=default;
    const bool&JustHovered()const {return just_hovered;}
    const bool&Hovered()const {return hovered;}
    const bool&ClickStarted()const{return click_stared;}
    const bool&Clicked()const{return clicked;}
    void update();
    void resize(float w,float h){
        this->width=w;
        this->height=h;
    }
    void move(float center_x,float center_y){
        this->x=center_x-this->width/2.0F;
        this->y=center_y-this->height/2.0F;
    }
    void UnHovered(){hovered=false;}
private:
    static const int &nx,&ny;
    static const bool &just_clicked,&just_released;
    float x,y,width,height;
    bool just_hovered,hovered,click_stared,clicked;
};
}