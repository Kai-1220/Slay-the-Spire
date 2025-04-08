#include "Game_object/card/Card_soul.hpp"
#include "RUtil/Some_Math.hpp"
#include "Game_object/effect/Card_trail_effect.hpp"
#include "RUtil/Random.hpp"
namespace Card
{
Card_soul::Card_soul(){
    is_flying=false;
    ctl_idx=ctl_len=0;
    ctl_pts.resize(10);
    vfx_timer=0.015F;
}
void Card_soul::discard(){
    //here just do discard move, but not really add the card to card_group.
    this->end_x=DISCARD_X;
    this->end_y=DISCARD_Y;
    this->is_clockwise=false;
    prepare_to_fly();
}
void Card_soul::shuffle(bool shuffle_invisible){
    this->is_shuffling=true;
    this->shuffle_invisible=shuffle_invisible;
    this->current_x=DISCARD_X;
    this->current_y=DISCARD_Y;
    this->end_x=DRAW_PILE_X;
    this->end_y=DRAW_PILE_Y;
    this->is_clockwise=true;
    prepare_to_fly();
    this->current_speed=START_VELOCITY*RUtil::Random::GetRandomFloat(2.0F,5.0F);
    this->target_angle=RUtil::Random::GetRandomFloat(0.0F,360.0F);
    this->start_wait_timer=RUtil::Random::GetRandomFloat(0.0F,0.12F);
}
void Card_soul::prepare_to_fly(){
    this->rotate_rate=ROTATION_RATE*RUtil::Random::GetRandomFloat(1.0F,2.0F);
    this->current_speed=START_VELOCITY*RUtil::Random::GetRandomFloat(0.2F,1.0F);
    this->end_timer=1.5F;
    this->is_flying=true;
    this->is_done=false;
    this->ctl_len=0;
    this->stop_rotate=false;
}
void Card_soul::update_flying(const std::shared_ptr<Effect::Effect_group> &effs,const Uint32 PlayerColor_RGB){
    if(is_flying){
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
                if(ctl_len==0||ctl_pts[ctl_idx]!=glm::vec2{current_x,current_y}){
                    ctl_pts[RUtil::Math::SimpleRangeChange(ctl_idx+ctl_len,10)]=glm::vec2{current_x,current_y};
                    ctl_len++;
                }
                if(ctl_len>3){
                    for(int i=0;i<20;i++){
                        effs->AddTop(std::make_shared<Effect::Card_trail_effect>(RUtil::Math::CatmullRomSpline(ctl_pts,i/19.0F,ctl_len,ctl_idx),PlayerColor_RGB));
                    }
                }
                if(ctl_len>=10){
                    ctl_len--;
                    ctl_idx=RUtil::Math::SimpleRangeChange(ctl_idx+1,10);
                }
            }
            //update end_timer
            end_timer-=DT;
            if(end_timer<0.0F) is_done=true;
        }
        //done
        if(is_done){
            is_flying=false;
            target_x=current_x;
            target_y=current_y;
            is_shuffling=false;
        }
    }
}
} // namespace Card
