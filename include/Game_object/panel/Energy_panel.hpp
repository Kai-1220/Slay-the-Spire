#pragma once

#include <memory>

#include "Game_object/panel/Panels.hpp"
#include "RUtil/Some_Math.hpp"
#include "Draw/NumberDrawer.hpp"

//fwd decl
namespace EnergyOrb{
    class Energy_orb;
}
namespace Effect{
    class Effect_group;
}
namespace  Character{
    class Player;
}

namespace Panel{
class Energy_panel final:public Panels
{
public:
    Energy_panel();
    ~Energy_panel()override=default;
    void update()override;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void on_add_energy(const std::shared_ptr<Effect::Effect_group>&effs);
    void on_use_energy();
    void set_player(const std::shared_ptr<Character::Player> &player);
private:
    const int *current_energy,*max_energy;
    float vfx_angle,vfx_scale,vfx_color_a,vfx_timer,font_scale;
    std::shared_ptr<EnergyOrb::Energy_orb> energy_orb=nullptr;
    std::weak_ptr<Character::Player>m_player;//Default constructor of weak_ptr automatically sets it to nullptr.
    std::shared_ptr<Draw::ReTexture> vfx_img;
    Draw::NumberDrawer m_font;
    void update_vfx();
    void render_vfx(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    static constexpr int FONTSIZE=36;
    static constexpr Uint32 TEXTCOLOR=RUtil::Math::GetColorUint32_RGB(1.0F,1.0F,0.86F);
};
}