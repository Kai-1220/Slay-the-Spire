#ifndef GAME_OBJECT_CARD_CARD_SOUL
#define GAME_OBJECT_CARD_CARD_SOUL
#include "WindowSize.hpp"
namespace Card{
//control group flying logic
class Card_soul
{
public:
    virtual ~Card_soul()=default;
protected:
    void update_flying();
    Card_soul();
    float current_x,current_y,target_x,target_y,target_angle,start_wait_timer,end_timer;
private:
    bool is_flying,stop_rotate,is_clockwise,is_done;
    float rotate_rate,end_x,end_y,current_speed,vfx_timer;
    static constexpr float HOME_IN_THRESHOLD=72.0F*Setting::SCALE,VELOCITY_RAMP_RATE=3000.0F*Setting::SCALE, MAX_VELOCITY=6000.0F*Setting::SCALE, DST_THRESHOLD=36.0F*Setting::SCALE;
};
}
#endif