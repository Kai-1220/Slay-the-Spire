#include "Game_object/action/Wait_action.hpp"
namespace Action{
    Wait_action::Wait_action(float dur){
        this->duration=dur;
    }
    void Wait_action::update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package){
        TimeGo();
    }
}