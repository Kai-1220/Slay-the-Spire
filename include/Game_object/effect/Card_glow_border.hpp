#ifndef GAME_OBJECT_EFFECT_CARD_GLOW_BORDER
#define GAME_OBJECT_EFFECT_CARD_GLOW_BORDER
#include "Game_object/effect/Effects.hpp"
#include "RUtil/Some_Math.hpp"
#include "Draw/Atlas_Region.hpp"
namespace Effect{
class Card_glow_border final:public Effects
{
public:
    Card_glow_border(const std::shared_ptr<Draw::Atlas_Region>&silhouette,const int &card_x,const int &card_y,const float &card_angle,const float &card_scale);
    ~Card_glow_border()override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update() override;
private:
    const int&card_x,&card_y;
    const float&card_angle,&card_scale;
    const std::shared_ptr<Draw::Atlas_Region> &img;
    static constexpr Uint32 DFAULT_COLOR=0x30c8dc00;
};
}
#endif