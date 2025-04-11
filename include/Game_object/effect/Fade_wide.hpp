#ifndef GAME_OBJECT_EFFECT_FADE_WIDE
#define GAME_OBJECT_EFFECT_FADE_WIDE
#include "Game_object/effect/Effects.hpp"
#include "RUtil/All_Image.hpp"
namespace Effect{
class Fade_wide final:public Effects
{
public:
    Fade_wide(Uint32 dungeon_fade_color);
    ~Fade_wide()override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update() override;
private:
    float y;
    static const std::shared_ptr<Draw::Atlas_Region> &IMG;
public:
    static const std::shared_ptr<Draw::ReTexture> &white_square;
};
}
#endif