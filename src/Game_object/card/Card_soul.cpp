#include <glm/glm.hpp>

#include "Game_object/card/Card_soul.hpp"
#include "Game_object/effect/Card_trail_effect.hpp"
#include "Game_object/effect/Effect_pool.hpp"
#include "Game_object/effect/Effect_group.hpp"
#include "RUtil/Some_Math.hpp"
#include "RUtil/Random.hpp"

namespace Card
{
Card_soul::Card_soul(){
    ctl_idx=ctl_len=0;
    ctl_pts.resize(10);
    vfx_timer=0.015F;
    is_flying=false;
    is_shuffling=false;
}
void Card_soul::discard(){
    //here just do discard move, but not really add the card to card_group.
    this->end_x=DISCARD_X;
    this->end_y=DISCARD_Y;
    //angle: angle+360.0F -> end_angle  //angle+360.0F is [270.0F,450.0F]
    //            counterclockwise      //end_angle is [270.0F,360.0F]
    this->target_angle+=360.0F;
    this->is_clockwise=false;
    prepare_to_fly();
    this->current_speed=START_VELOCITY*RUtil::Random::GetRandomFloat(1.0F,4.0F);
}
void Card_soul::shuffle(bool shuffle_invisible){
    this->is_shuffling=true;
    this->shuffle_invisible=shuffle_invisible;
    this->current_x=DISCARD_X;
    this->current_y=DISCARD_Y;
    this->end_x=DRAW_PILE_X;
    this->end_y=DRAW_PILE_Y;
    prepare_to_fly();
    this->current_speed=START_VELOCITY*RUtil::Random::GetRandomFloat(2.0F,5.0F);
    this->target_angle=RUtil::Random::GetRandomFloat(-10.0F,40.0F);//[-10.0F,-40.0F] -> end_angle(about 90.0F)
    this->is_clockwise=true;
    this->start_wait_timer=RUtil::Random::GetRandomFloat(0.0F,0.12F);
}
void Card_soul::prepare_to_fly(){
    this->rotate_rate=ROTATION_RATE*RUtil::Random::GetRandomFloat(1.0F,2.0F);
    this->current_speed=START_VELOCITY*RUtil::Random::GetRandomFloat(0.2F,1.0F);
    this->end_timer=MAX_FLYING_TIME;
    this->is_flying=true;
    this->is_done=false;
    this->ctl_len=0;
    this->stop_rotate=false;
}
void Card_soul::update_flying(Effect::Effect_group &effs,const Uint32 PlayerTrailColor_RGB){
    if(!is_flying) return;

    if(0.0F<start_wait_timer){
        start_wait_timer-=DT;
        return;
    }

    if(!stop_rotate)
        this->rotate_update();

    this->movement_update();
    
    this->vfx_update(effs,PlayerTrailColor_RGB);
    
    
    //update end_timer
    end_timer-=DT;
    if(end_timer<0.0F) is_done=true;

    //done
    if(is_done){
        is_flying=false;
        target_x=current_x;
        target_y=current_y;
        is_shuffling=false;
    }
}

void Card_soul::vfx_update(Effect::Effect_group &effs,const Uint32 PlayerTrailColor_RGB){
    //create effect trail
    vfx_timer-=DT;
    if(vfx_timer<0.0F){
        vfx_timer=0.015F;
        
        if(ctl_len<CTL_MAX_LEN){
            ctl_pts[RUtil::Math::SimpleRangeChange(ctl_idx+ctl_len,CTL_MAX_LEN)]=glm::vec2{current_x,current_y};
            ctl_len++;
        }else{
            ctl_pts[ctl_idx]=glm::vec2{current_x,current_y};//remove oldest.
            ctl_idx=RUtil::Math::SimpleRangeChange(ctl_idx+1,CTL_MAX_LEN);
        }

        const float step=1.0F/19.0F;
        if(ctl_len>3){
            for(int i=0;i<20;i++){
                effs.AddTop(
                    Effect::Effect_pool<Effect::Card_trail_effect>::GetEffect(
                        RUtil::Math::CatmullRomSpline(ctl_pts, (float)i*step, ctl_len, ctl_idx),
                        PlayerTrailColor_RGB
                    )
                );
            }
        }
    }
}

void Card_soul::movement_update(){
    //let current pos closer to end_pos
    const float target_rad=glm::radians(target_angle+90.0F);//+90.0F to align movement with the the card's visual facing direction.
    glm::vec2 unit_dir_vec={glm::cos(target_rad), glm::sin(target_rad)};
    unit_dir_vec*=DT*this->current_speed;//to translation_vec
    current_x+=unit_dir_vec.x;
    current_y+=unit_dir_vec.y;
    if(stop_rotate&&end_timer<MAX_FLYING_TIME)//end_timer<MAX_FLYING_TIME prevents the card from getting boosted immediately after launch.
        this->current_speed+=DT*VELOCITY_RAMP_RATE*3.0F;
    else
        this->current_speed+=DT*VELOCITY_RAMP_RATE*1.5F;

    if(current_speed>MAX_VELOCITY) current_speed=MAX_VELOCITY;

    if((end_x<(float)Setting::WINDOW_WIDTH/2.0F&&current_x<0.0F)||(end_x>(float)Setting::WINDOW_WIDTH/2.0F&&current_x>(float)Setting::WINDOW_WIDTH)){
        this->is_done=true;
    }else if(glm::length(glm::vec2{current_x-end_x,current_y-end_y})<DST_THRESHOLD){
        this->is_done=true;
    }
}

void Card_soul::rotate_update(){
    //let target angle closer to end_angle. //The card's angle 0.0F is corresponds to facing upward.
    rotate_rate+=DT*800.0F;
    if(is_clockwise){
        target_angle+=DT*rotate_rate;
        if(target_angle>=360.0F) target_angle-=360.0F;
    }else{
        target_angle-=DT*rotate_rate;
        if(target_angle<0.0F) target_angle+=360.0F;
    }

    const glm::vec2 dir_vec{end_x-current_x,end_y-current_y};
    const float end_angle=RUtil::Math::GetDegress(dir_vec)+270.0F;//+270.0F to match card's facing direction.
    if(glm::length(dir_vec)<HOME_IN_THRESHOLD || std::abs(target_angle-end_angle)<DT*rotate_rate){
        target_angle=end_angle;
        stop_rotate=true;
    }
}
} // namespace Card
