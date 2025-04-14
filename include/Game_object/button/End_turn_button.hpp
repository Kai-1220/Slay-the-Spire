#pragma once

#include "Game_object/button/Buttons.hpp"
#include "RUtil/Some_Math.hpp"
#include "WindowSize.hpp"

namespace Button{
class End_turn_button final:public Buttons
{
public:
    End_turn_button();
    ~End_turn_button()override=default;
    void update() override;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
private:
    float current_x,current_y,target_x,target_y;
    bool is_hidden,is_glowing;
    float glow_timer;
    
    static constexpr float SHOW_X = 1640.0F * Setting::SCALE,
                           SHOW_Y = 210.0F * Setting::SCALE;
    static constexpr float HIDE_X = SHOW_X + 500.0F * Setting::SCALE;
    static constexpr auto DISABLED_COLOR = RUtil::Math::GetColorUint32_RGB(0.7F, 0.7F, 0.7F);
};
}