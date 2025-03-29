#include "Game_object/character/Monster/TempMonster.hpp"
namespace Monster
{
    TempMonster::TempMonster(){
        m_damage=5;
    }
    void TempMonster::apply(const std::shared_ptr<Action::Action_group> &action_group)const{
        
    }
} // namespace Monster