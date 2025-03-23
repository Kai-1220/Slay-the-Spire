#include "Game_object/card/Card_soul.hpp"
#include "RUtil/Game_Input.hpp"
#include "RUtil/Some_Math.hpp"
namespace Card
{
Card_soul::Card_soul(){
    is_flying=false;
}
void Card_soul::update_flying(){
    if(is_flying){
        const float DT=RUtil::Game_Input::delta_time();
        if(start_wait_timer>0.0F) start_wait_timer-=DT;
        else{
            const glm::vec2 dir_vec{end_x-current_x,end_y-current_y};
            //let target angle closer to end_angle
            if(!stop_rotate){
                const float end_angle=glm::degrees(RUtil::Math::GetRadian(dir_vec));
                rotate_rate+=DT*800.0F;
                if(is_clockwise){
                    target_angle+=DT*rotate_rate;
                    if(target_angle>=360.0F) target_angle-=360.0F;
                }else{
                    target_angle-=DT*rotate_rate;
                    if(target_angle<0.0F) target_angle+=360.0F;
                }

                if(glm::length(dir_vec)<HOME_IN_THRESHOLD || std::abs(target_angle-end_angle)<DT*rotate_rate){
                    target_angle=end_angle;
                    stop_rotate=true;
                }
            }
            //let current pos closer to end_pos
            const float target_rad=glm::radians(target_angle);
            glm::vec2 unit_dir_vec={glm::cos(target_rad), glm::sin(target_rad)};
            unit_dir_vec*=DT*this->current_speed;//to translation_vec
            current_x+=unit_dir_vec.x;
            current_y+=unit_dir_vec.y;
            if(stop_rotate&&end_timer<1.3499999F)
                this->current_speed+=DT*VELOCITY_RAMP_RATE*3.0F;
            else
                this->current_speed+=DT*VELOCITY_RAMP_RATE*1.5F;

            if(current_speed>MAX_VELOCITY) current_speed=MAX_VELOCITY;
            if((end_x<(float)WINDOW_WIDTH/2.0F&&current_x<0.0F)||(end_x>(float)WINDOW_WIDTH/2.0F&&current_x>(float)WINDOW_WIDTH)){
                this->is_done=true;
            }else if(glm::length(glm::vec2{current_x-end_x,current_y-end_y})<DST_THRESHOLD){
                this->is_done=true;
            }
            //create effect trail
            vfx_timer-=DT;
            if(!is_done&&vfx_timer<0.0F){
                vfx_timer=0.015F;
                
            }
        }
    }
}
} // namespace Card
