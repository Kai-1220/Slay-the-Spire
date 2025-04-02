#ifndef GAME_OBJECT_ACTION_GROUP_HANDLER
#define GAME_OBJECT_ACTION_GROUP_HANDLER
#include "Game_object/card/Card_item.hpp"
#include "Game_object/action/Action_group.hpp"
namespace Action{
class Action_group_handler
{
public:
    Action_group_handler()=default;
    ~Action_group_handler()=default;
    void update();
private:
    Action_group action_box,pre_action_box;
    std::list<Card::Card_item> card_queue;
    
};
}
#endif