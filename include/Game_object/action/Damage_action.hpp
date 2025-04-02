#ifndef GAME_OBJECT_ACTION_DAMAGE_ACTION
#define GAME_OBJECT_ACTION_DAMAGE_ACTION
#include "Game_object/action/Actions.hpp"
namespace Action{
class Damage_action final:public Actions
{
public:
    Damage_action(int num);
    Damage_action(int num,const std::shared_ptr<Character::Characters> &target);
    ~Damage_action() override=default;
    void update(const std::shared_ptr<Card::Card_group_handler>&c_handler,Action_group_handler*const action_group_handler)override;
private:
    int num;
    std::shared_ptr<Character::Characters> target;
};
}
#endif