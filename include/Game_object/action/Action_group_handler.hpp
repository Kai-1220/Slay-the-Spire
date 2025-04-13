#ifndef GAME_OBJECT_ACTION_GROUP_HANDLER
#define GAME_OBJECT_ACTION_GROUP_HANDLER
#include "Game_object/card/Card_item.hpp"
#include "Game_object/action/Action_group.hpp"
#include "RUtil/Random_package.hpp"
namespace Action{
class Action_group_handler
{
public:
    Action_group_handler()=default;
    ~Action_group_handler()=default;
    void AddActionTop(std::shared_ptr<Actions>&&action);
    void AddActionBot(std::shared_ptr<Actions>&&action);
    void AddActionTop(const std::shared_ptr<Actions>&action);
    void AddActionBot(const std::shared_ptr<Actions>&action);
    void AddCardQueue(Card::Card_item &&card_item);
    void AddCardQueue(const Card::Card_item &card_item);
    void update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,const RUtil::Random_package &random_package);
    bool is_nothing_to_do()const{return this->current_action==nullptr&&action_box.empty();}
    void prepare_for_battle();
private:
    void get_next_action(const std::shared_ptr<Card::Card_group_handler>&card_group_handler);
    Action_group action_box,pre_action_box;
    std::list<Card::Card_item> card_queue;
    bool is_wating_player=false;
    std::shared_ptr<Actions> current_action;
};
}
#endif