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
    Action_group_handler(const Action_group_handler &) = delete;
    Action_group_handler(Action_group_handler &&) = delete;
    Action_group_handler &operator=(const Action_group_handler &) = delete;
    Action_group_handler &operator=(Action_group_handler &&)=delete;
    
    void update(Card::Card_group_handler &card_group_handler,const RUtil::Random_package &random_package);
    bool is_nothing_to_do()const{return this->current_action==nullptr&&action_box.empty();}
    void prepare_for_battle();
    
    void AddActionTop(std::shared_ptr<Actions>&&action){action_box.AddTop(std::move(action));}
    void AddActionBot(std::shared_ptr<Actions>&&action){action_box.AddBot(std::move(action));}
    void AddActionTop(const std::shared_ptr<Actions>&action){action_box.AddTop(action);}
    void AddActionBot(const std::shared_ptr<Actions>&action){action_box.AddBot(action);}
    void AddCardQueue(Card::Card_item &&card_item){card_queue.emplace_back(std::move(card_item));}
    void AddCardQueue(const Card::Card_item &card_item){card_queue.emplace_back(card_item);}
private:
    void get_next_action();
    Action_group action_box,pre_action_box;
    std::list<Card::Card_item> card_queue;
    bool is_wating_player=false;
    std::shared_ptr<Actions> current_action;
};
}
#endif