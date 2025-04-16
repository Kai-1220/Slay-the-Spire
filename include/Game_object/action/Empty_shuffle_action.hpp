#ifndef GAME_OBJECT_ACTION_EMPTY_SHUFFLE_ACTION
#define GAME_OBJECT_ACTION_EMPTY_SHUFFLE_ACTION
#include "Game_object/action/Actions.hpp"
namespace Action{
class Empty_shuffle_action final:public Actions
{
public:
    Empty_shuffle_action(const int discard_pile_size);
    ~Empty_shuffle_action()override=default;
    void update(Card::Card_group_handler &card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package)override;
private:
    const int amount;
    int cnt;
    bool first_time;
    static constexpr float OEN_CARD_SHUFFLE_TIME=1.0F/60.0F;
};
}
#endif