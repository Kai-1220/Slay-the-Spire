#ifndef GAME_OBJECT_ACTION_CARD_USE_ACTION
#define GAME_OBJECT_ACTION_CARD_USE_ACTION
#include "Game_object/action/Actions.hpp"
namespace Action{
class Card_use_action final:public Actions
{
public:
    Card_use_action(const std::shared_ptr<Card::Cards> &card,const std::shared_ptr<Character::Characters> &target);
    ~Card_use_action() override=default;
    void update(const std::shared_ptr<Card::Card_group_handler>&c_handler,const Action_group* action_group)override;
private:
    std::shared_ptr<Card::Cards> card;
    std::shared_ptr<Character::Characters> target;
};
}
#endif