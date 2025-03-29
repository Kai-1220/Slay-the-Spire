#ifndef GAME_OBJECT_ACTION_DISCARD_ALL_ACTION
#define GAME_OBJECT_ACTION_DISCARD_ALL_ACTION
#include "Game_object/action/Actions.hpp"
namespace Action{
class Discard_all_action final:public Actions
{
public:
    Discard_all_action();
    ~Discard_all_action()override=default;
    void update(const std::shared_ptr<Card::Card_group_handler>&c_handler,const Action_group* action_group)override;
private:
};
}
#endif