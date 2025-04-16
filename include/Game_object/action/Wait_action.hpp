#ifndef GAME_OBJECT_ACTION_WAIT_ACTION
#define GAME_OBJECT_ACTION_WAIT_ACTION
#include "Game_object/action/Actions.hpp"
namespace Action{
class Wait_action final:public Actions
{
public:
    Wait_action(float dur);
    ~Wait_action()override=default;
    void update(Card::Card_group_handler &card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package)override;
};
}
#endif