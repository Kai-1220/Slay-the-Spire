#include "Game_object/action/Card_use_action.hpp"
#include "Game_object/action/Wait_action.hpp"
namespace Action{
    Card_use_action::Card_use_action(const Card::Card_item &card_item):m_card_itme(card_item){
        this->duration=0.15F;
    }
    void Card_use_action::update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package){
        if(this->duration==0.15F){
            if(m_card_itme.card->type==Card::Type::power){
                action_group_handler->AddActionTop(std::make_shared<Wait_action>(0.7F));
                LOG_DEBUG("POWER_CARD_USE");
                is_done=true;
                return;
            }

            card_group_handler->discard(m_card_itme.card);
        }
        TimeGo();
    }
}