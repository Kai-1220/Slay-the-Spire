#pragma once

#include <memory>
#include <vector>
#include <glm/vec2.hpp>//vec2
#include <SDL_stdinc.h>//Uint32

#include "RUtil/Game_Input.hpp"//delta_time
#include "WindowSize.hpp"//SCALE

//fwd decl
namespace Effect{
    class Effect_group;
}

namespace Card{
//control group flying logic
class Card_soul
{
public:
    virtual ~Card_soul()=default;
    void discard();
    void shuffle(bool shuffle_invisible);
    bool is_fly()const{return is_flying;}
protected:
    bool is_flying,is_shuffling;
    bool shuffle_invisible;// If true, this card will not be rendered during shuffling.
    void update_flying(Effect::Effect_group &effs,const Uint32 PlayerTrailColor_RGB);
    Card_soul();
    float current_x,current_y,target_x,target_y,target_angle,start_wait_timer,end_timer;
private:
    const float & DT=RUtil::Game_Input::delta_time();
    bool stop_rotate,is_clockwise,is_done;
    float rotate_rate,end_x,end_y,current_speed,vfx_timer;
    
    std::vector<glm::vec2> ctl_pts;
    int ctl_idx,ctl_len;

    void prepare_to_fly();
    void rotate_update();
    void movement_update();
    void vfx_update(Effect::Effect_group &effs,const Uint32 PlayerTrailColor_RGB);

    static constexpr float HOME_IN_THRESHOLD = 72.0F * Setting::SCALE,
                           VELOCITY_RAMP_RATE = 3000.0F * Setting::SCALE,
                           MAX_VELOCITY = 6000.0F * Setting::SCALE,
                           DST_THRESHOLD = 36.0F * Setting::SCALE,
                           ROTATION_RATE = 150.0F * Setting::SCALE,
                           START_VELOCITY = 200.0F * Setting::SCALE,
                           MAX_FLYING_TIME = 1.5F;
    static constexpr int CTL_MAX_LEN=10;
public:
    static constexpr float  DISCARD_X = (float)Setting::WINDOW_WIDTH * 0.96F,
                            DISCARD_Y = (float)Setting::WINDOW_HEIGHT * 0.06F,
                            DRAW_PILE_X = (float)Setting::WINDOW_WIDTH * 0.04F,
                            DRAW_PILE_Y = (float)Setting::WINDOW_HEIGHT * 0.06F;
};
}