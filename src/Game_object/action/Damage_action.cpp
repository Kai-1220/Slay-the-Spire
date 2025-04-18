#include"Game_object/action/Damage_action.hpp"
namespace Action{
    Damage_action::Damage_action(int num,const std::shared_ptr<Character::Characters> &target):num(num),target(target){
        duration=ACTION_DUR_XFAST;
    }
    void Damage_action::update(Card::Card_group_handler &card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package){
        TimeGo();
        if(is_done){
            target->damage(num);
        }
    }
}