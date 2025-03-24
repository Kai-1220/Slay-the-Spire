#ifndef GAME_OBJECT_CARD_CARD_SOUL
#define GAME_OBJECT_CARD_CARD_SOUL
#include "WindowSize.hpp"
#include "Game_object/effect/Effect_group.hpp"
namespace Card{
//control group flying logic
class Card_soul
{
public:
    virtual ~Card_soul()=default;
    void discard();
    void shuffle();
    bool is_fly()const{return is_flying;}
protected:
    void update_flying(const std::shared_ptr<Effect::Effect_group> &effs,const Uint32 PlayerColor_RGB);
    Card_soul();
    float current_x,current_y,target_x,target_y,target_angle,start_wait_timer,end_timer;
private:
    void prepare_to_fly();
    bool is_flying,stop_rotate,is_clockwise,is_done;
    float rotate_rate,end_x,end_y,current_speed,vfx_timer;
    static constexpr float HOME_IN_THRESHOLD=72.0F*Setting::SCALE,VELOCITY_RAMP_RATE=3000.0F*Setting::SCALE, MAX_VELOCITY=6000.0F*Setting::SCALE, DST_THRESHOLD=36.0F*Setting::SCALE,ROTATION_RATE = 150.0F * Setting::SCALE,START_VELOCITY = 200.0F * Setting::SCALE;
    std::vector<glm::vec2> ctl_pts;
    int ctl_idx,ctl_len;
    static constexpr float  DISCARD_X = (float)WINDOW_WIDTH * 0.96F,
                            DISCARD_Y = (float)WINDOW_HEIGHT * 0.06F,
                            DRAW_PILE_X = (float)WINDOW_WIDTH * 0.04F,
                            DRAW_PILE_Y = (float)WINDOW_HEIGHT * 0.06F;
};
}
#endif