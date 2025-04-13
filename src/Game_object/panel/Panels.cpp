#include "Game_object/panel/Panels.hpp"
#include "RUtil/Some_Math.hpp"

namespace Panel{
    Panels::Panels(float show_x,float show_y,float hide_x,float hide_y,bool is_hidden):show_x(show_x),show_y(show_y),hide_x(hide_x),hide_y(hide_y){
        current_x=target_x=is_hidden?hide_x:show_x;
        current_y=target_y=is_hidden?hide_y:show_y;
    }
    void Panels::show(){
        target_x=show_x;
        target_y=show_y;
    }
    void Panels::hide(){
        target_x=hide_x;
        target_y=hide_y;
    }
    void Panels::update_position(){
        current_x=RUtil::Math::varlerp(current_x,target_x,7.0F,0.5F);
        current_y=RUtil::Math::varlerp(current_y,target_y,7.0F,0.5F);
    }
}