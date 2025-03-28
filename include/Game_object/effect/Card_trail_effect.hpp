#ifndef GAME_OBJECT_EFFECT_CARD_TRAIL_EFFECT
#define GAME_OBJECT_EFFECT_CARD_TRAIL_EFFECT
#include "Game_object/effect/Effects.hpp"
#include "RUtil/All_Image.hpp"
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
const std::shared_ptr<Draw::Atlas_Region> &IMG=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::_combat_blurDot2);
const glm::vec2 pos;
static constexpr float SCALE_MULTI = Setting::SCALE * 22.0F;
};
}
#endif