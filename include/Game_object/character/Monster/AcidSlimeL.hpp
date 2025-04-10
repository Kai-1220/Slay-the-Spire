#ifndef GAME_OBJECT_CHARACTER_MONSTER_ACIDSLIMEL
#define GAME_OBJECT_CHARACTER_MONSTER_ACIDSLIMEL
#include "Game_object/character/Monster/Monsters.hpp"

namespace Monster{
enum class AcidSlimeLAction
{
    CorrosiveSpit,
    Lick,
    Tackle,
    Split
};
class AcidSlimeL final:public Monsters
{
public:
    AcidSlimeL();
    ~AcidSlimeL()override=default;
    void Action(AcidSlimeLAction action_type, int damage, int block, int heal, int hp, int max_hp, int max_block, int max_damage);
    // void apply(const std::shared_ptr<Action::Action_group> &action_group)const override;
private:
    

};
}
#endif