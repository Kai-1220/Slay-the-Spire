#include"Game_object/action/Damage_action.hpp"
namespace Action{
    Damage_action::Damage_action(int num,const std::shared_ptr<Character::Characters> &target):num(num),target(target){
        duration=ACTION_DUR_XFAST;
    }
    void Damage_action::update(const std::shared_ptr<Card::Card_group_handler>&c_handler,Action_group_handler*const action_group_handler){
        TimeGo();
        if(is_done){
            target->damage(num);
        }
    }
}