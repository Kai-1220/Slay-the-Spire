#include "Game_object/action/Draw_card_action.hpp"
#include "Game_object/action/Empty_shuffle_action.hpp"
namespace Action
{
    Draw_card_action::Draw_card_action(int amount):amount(amount){
        this->duration=ACTION_DUR_FASTER;
        first_time=true;
    }
    void Draw_card_action::update(Card::Card_group_handler &card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package){
        const int draw_size=card_group_handler.draw_pile_size(),
                  discard_size=card_group_handler.discard_pile_size();
        if(draw_size+discard_size==0){
            is_done=true;
            return;
        }
        if(card_group_handler.is_someone_flying())
            return;
        if(first_time){
            first_time=false;
            if(amount+card_group_handler.hand_cards_size()>10){
                amount=10-card_group_handler.hand_cards_size();
            }
            if(amount>draw_size){
                action_group_handler->AddActionTop(std::make_shared<Action::Draw_card_action>(amount-draw_size));
                action_group_handler->AddActionTop(std::make_shared<Action::Empty_shuffle_action>(discard_size));
                if(draw_size!=0)
                    action_group_handler->AddActionTop(std::make_shared<Action::Draw_card_action>(draw_size));
                is_done=true;
                return;
            }
        }
        duration-=DT;
        while(0<amount&&duration<0.0F){
            amount--;
            duration+=ACTION_DUR_FASTER;
            card_group_handler.draw();
        }
        if(amount==0)
            is_done=true;
    }

} // namespace Action
