#pragma once

#include "Game_object/effect/Effects.hpp"
#include "WindowSize.hpp"

//fwd decl
namespace Draw{
    class Atlas_Region;
}

namespace Effect{
class Card_trail_effect final:public Effects
{
public:
    Card_trail_effect(glm::vec2 pos,Uint32 RGB_color);
    ~Card_trail_effect() override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update() override;
private:
static const std::shared_ptr<Draw::Atlas_Region> &IMG;
const glm::vec2 pos;
static constexpr float SCALE_MULTI = Setting::SCALE * 22.0F;
};
}