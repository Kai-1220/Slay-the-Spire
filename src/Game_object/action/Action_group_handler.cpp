#include "Game_object/action/Action_group_handler.hpp"
#include "Game_object/action/Card_use_action.hpp"
#include "Game_object/action/Wait_action.hpp"

#include "Util/Logger.hpp"

namespace Action
{
    void Action_group_handler::update(Card::Card_group_handler &card_group_handler,const RUtil::Random_package &random_package){
        if(is_wating_player){
            get_next_action();
        }else{
            if(current_action!=nullptr){
                current_action->update(card_group_handler,this,random_package);
                if(current_action->IsDone()) current_action=nullptr;
            }else{
                get_next_action();
                if(current_action==nullptr){
                    card_group_handler.refresh_hand_layout();
                    is_wating_player=true;
                }
            }
        }
    }
    void Action_group_handler::get_next_action(){
        if(!action_box.empty()){
            current_action=action_box.PopTop();
            is_wating_player=false;
        }else if(!pre_action_box.empty()){
            current_action=pre_action_box.PopTop();
            is_wating_player=false;
        }else if(!card_queue.empty()){
            //remember check if card can't use
            action_box.AddBot(std::make_shared<Card_use_action>(card_queue.front()));
            card_queue.front().card->SetTargetX((float)Setting::WINDOW_WIDTH/2.0F);
            card_queue.front().card->SetTargetY((float)Setting::WINDOW_HEIGHT/2.0F);
            //reduce energy
            card_queue.pop_front();
        }
    }
    void Action_group_handler::prepare_for_battle(){
        if(!action_box.empty()){
            LOG_ERROR("There are some remain action in box.");
            action_box.Clear();
        }
        action_box.AddTop(std::make_shared<Action::Wait_action>(1.0F));
    }
    void Action_group_handler::AddActionTop(std::shared_ptr<Actions>&&action){action_box.AddTop(std::move(action));}
    void Action_group_handler::AddActionBot(std::shared_ptr<Actions>&&action){action_box.AddBot(std::move(action));}
    void Action_group_handler::AddActionTop(const std::shared_ptr<Actions>&action){action_box.AddTop(action);}
    void Action_group_handler::AddActionBot(const std::shared_ptr<Actions>&action){action_box.AddBot(action);}
    void Action_group_handler::AddCardQueue(Card::Card_item &&card_item){card_queue.emplace_back(std::move(card_item));}
    void Action_group_handler::AddCardQueue(const Card::Card_item &card_item){card_queue.emplace_back(card_item);}
} // namespace Action
