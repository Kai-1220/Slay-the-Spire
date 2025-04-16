#include "Game_object/dungeon/Overlay.hpp"
namespace Dungeon{
    void Overlay::update(){
        energy_panel.update();
    }
    void Overlay::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        energy_panel.render(r2);
    }
    void Overlay::hide_combat_panel(){
        energy_panel.hide();
    };
    void Overlay::show_combat_panel(){
        energy_panel.show();
    };
    
}