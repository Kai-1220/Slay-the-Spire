#pragma once

#include <memory>

#include "Game_object/panel/Energy_panel.hpp"
//fwd decl
namespace Character{
    class Player;
}

namespace Dungeon{
class Overlay
{
public:
    Overlay()=default;
    ~Overlay()=default;

    void update();
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void hide_combat_panel();
    void show_combat_panel();
    void set_player_to_energy_panel(const std::shared_ptr<Character::Player>&player){energy_panel.set_player(player);}
private:
    Panel::Energy_panel energy_panel;
};
}