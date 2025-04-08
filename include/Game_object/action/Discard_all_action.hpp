#ifndef GAME_OBJECT_ACTION_DISCARD_ALL_ACTION
#define GAME_OBJECT_ACTION_DISCARD_ALL_ACTION
#include "Game_object/action/Actions.hpp"
namespace Action{
class Discard_all_action final:public Actions
{
public:
    Discard_all_action();
    ~Discard_all_action()override=default;
    void update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package)override;
private:
};
}
#endif