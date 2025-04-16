#include "Game_object/button/End_turn_button.hpp"
#include "Game_object/effect/End_turn_button_glow.hpp"
#include "Game_object/effect/Effect_pool.hpp"
#include "RUtil/Game_Input.hpp"

namespace Button
{
    End_turn_button::End_turn_button():Buttons(0.0F,0.0F,230.0F*Setting::SCALE,110.0F*Setting::SCALE){
        this->current_x=HIDE_X;
        this->current_y=SHOW_Y;
        this->is_hidden=true;
        this->is_glowing=false;
        this->is_enabled=false;
        this->glow_timer=0.0F;
    }
    void End_turn_button::update(){
        //glow update
        if(is_glowing&&!is_hidden){
            glow_timer-=RUtil::Game_Input::delta_time();
            if(glow_timer<0.0F){
                glow_timer=1.2F;
                glow_list.AddTop(Effect::Effect_pool<Effect::End_turn_button_glow>::GetEffect(this->current_x,this->current_y));
            }
        }
        glow_list.update();
        
        //lerp
        if(this->current_x!=this->target_x)
            this->current_x=RUtil::Math::varlerp(this->current_x,this->target_x,9.0F,Setting::SCALE);
        this->hb.move(current_x,current_y);

        // if(this->is_enabled){

        // }
    }
    void End_turn_button::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        // if(this->is_enabled){

        // }
        // if(this->is_glowing)
    }
} // namespace Button
