#pragma once

#include "Game_object/effect/Effects.hpp"

//fwd decl
namespace Draw{
    class Atlas_Region;
    class ReTexture;
}

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