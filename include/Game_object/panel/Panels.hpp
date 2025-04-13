#pragma once

#include "Draw/Draw_2D.hpp"

namespace Panel{
class Panels
{
public:
    Panels(float show_x,float show_y,float hide_x,float hide_y,bool is_hidden);
    virtual ~Panels()=default;
    virtual void update()=0;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    void show();
    void hide();   
protected:
    void update_position();
    float current_x,current_y;
private:
    float target_x,target_y;
    const float show_x,show_y,hide_x,hide_y;
};
}