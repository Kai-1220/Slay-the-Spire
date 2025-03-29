#include "Game_object/action/Card_use_action.hpp"
namespace Action{
    Card_use_action::Card_use_action(const std::shared_ptr<Card::Cards> &card,const std::shared_ptr<Character::Characters> &target):card(card),target(target){
        this->duration=0.15F;
    }
    void Card_use_action::update(const std::shared_ptr<Card::Card_group_handler>&c_handler,const Action_group* action_group){
        
    }
}