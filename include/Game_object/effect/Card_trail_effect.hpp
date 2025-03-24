#ifndef GAME_OBJECT_EFFECT_CARD_TRAIL_EFFECT
#define GAME_OBJECT_EFFECT_CARD_TRAIL_EFFECT
#include "Game_object/effect/Effects.hpp"
#include "RUtil/Atlas_shared.hpp"
#include "WindowSize.hpp"
namespace Effect{
class Card_trail_effect final:public Effects
{
public:
    Card_trail_effect(glm::vec2 pos,Uint32 RGB_color);
    ~Card_trail_effect() override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update() override;
private:
static std::shared_ptr<Draw::Atlas_Region> IMG;
float duration,scale,color_a;
const glm::vec2 pos;
const Uint32 color;
static constexpr float SCALE_MULTI = Setting::SCALE * 22.0F;
};
}
#endif