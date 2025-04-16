#ifndef GAME_OBJECT_ACTION_DISCARD_ACTION
#define GAME_OBJECT_ACTION_DISCARD_ACTION
#include "Game_object/action/Actions.hpp"
namespace Action{
class Discard_action final:public Actions
{
public:
    Discard_action();
    ~Discard_action() override=default;
    void update(Card::Card_group_handler &card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package)override;
private:
};
}
#endif