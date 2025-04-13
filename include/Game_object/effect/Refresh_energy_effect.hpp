#pragma once

#include "Game_object/effect/Effects.hpp"

//fwd decl
namespace Draw{
    class Atlas_Region;
}

namespace Effect{
class Refresh_energy_effect final:public Effects
{
public:
    Refresh_energy_effect(const float &panel_x,const float &panel_y);
    ~Refresh_energy_effect()override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update() override;
private:
    const float &panel_x,&panel_y;
    static const std::shared_ptr<Draw::Atlas_Region> &white_ring;
};
} // namespace Effect