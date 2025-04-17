#include "Game_object/character/Monster/TempMonster.hpp"
namespace Monster
{
    TempMonster::TempMonster():Monsters(Setting::WINDOW_WIDTH*0.5F, Setting::WINDOW_HEIGHT*0.5F, 0, 0){
        m_damage=5;
    }
    void TempMonster::render(const std::shared_ptr<Draw::Draw_2D> &r2) const {

    }
    // void TempMonster::apply(const std::shared_ptr<Action::Action_group> &action_group)const{
        
    // }
} // namespace Monster