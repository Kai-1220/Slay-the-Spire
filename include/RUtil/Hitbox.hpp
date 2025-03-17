#ifndef RUTIL_HITBOX_HPP
#define RUTIL_HITBOX_HPP
namespace RUtil{
class Hitbox{
public:
    Hitbox(float x,float y,float height,float width);
    ~Hitbox()=default;
    bool JustHovered()const {return just_hovered;}
    bool Hovered()const {return hovered;}
    bool ClickStared()const{return click_stared;}
    bool Clicked()const{return clicked;}
    void update();
    void move(float center_x,float center_y);
private:
    float x,y,height,width,cx,cy;
    bool just_hovered,hovered,click_stared,clicked;
};
}
#endif