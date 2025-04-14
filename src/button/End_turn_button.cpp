#include "Game_object/button/End_turn_button.hpp"
#include "RUtil/Game_Input.hpp"

namespace Button
{
    End_turn_button::End_turn_button():Buttons(0.0F,0.0F,230.0F*Setting::SCALE,110.0F*Setting::SCALE){
        this->current_x=HIDE_X;
        this->current_y=SHOW_Y;
        this->is_hidden=true;
        this->is_glowing=false;
        this->glow_timer=0.0F;
    }
    void End_turn_button::update(){
        //glow update
        if(is_glowing){
            glow_timer-=RUtil::Game_Input::delta_time();
            if(glow_timer<0.0F){
                glow_timer=1.2F;
                
            }
        }
    }
    void End_turn_button::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{

    }
} // namespace Button
