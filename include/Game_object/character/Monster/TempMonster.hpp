#ifndef GAME_OBJECT_CHARACTER_MONSTER_TEMPMONSTER
#define GAME_OBJECT_CHARACTER_MONSTER_TEMPMONSTER
#include "Game_object/character/Monster/Monsters.hpp"
namespace Monster{
class TempMonster final:public Monsters
{
public:
    TempMonster();
    ~TempMonster()override=default;
    void apply(const std::shared_ptr<Action::Action_group> &action_group)const override;
private:

};
}
#endif