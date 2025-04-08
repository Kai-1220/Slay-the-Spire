#ifndef GAME_OBJECT_ACTION_DRAW_CARD_ACTION
#define GAME_OBJECT_ACTION_DRAW_CARD_ACTION
#include "Game_object/action/Actions.hpp"
namespace Action{
class Draw_card_action final:public Actions
{
public:
    Draw_card_action(int amount);
    ~Draw_card_action()override=default;
    void update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package)override;
private:
    bool first_time;
    int amount;
};
}
#endif