#ifndef GAME_OBJECT_ACTION_CARD_USE_ACTION
#define GAME_OBJECT_ACTION_CARD_USE_ACTION
#include "Game_object/action/Actions.hpp"
#include "Game_object/card/Card_item.hpp"
namespace Action{
class Card_use_action final:public Actions
{
public:
    Card_use_action(const Card::Card_item &card_item);
    ~Card_use_action() override=default;
    void update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package)override;
private:
    Card::Card_item m_card_itme;
};
}
#endif