#ifndef GAME_OBJECT_CHARACTER_MONSTER_MONSTERS
#define GAME_OBJECT_CHARACTER_MONSTER_MONSTERS
#include "Game_object/action/Action_group.hpp"
#include "Game_object/character/Characters.hpp"
namespace Monster{
enum class MonsterID{
    None,
    TempMonster
};
class Monsters:public Character::Characters
{
public:
    virtual ~Monsters()=default;
    // virtual void apply(const std::shared_ptr<Action::Action_group> &action_group)const=0;
    void damage(int num)override;
protected:
    int m_damage;
};
}
#endif