#include "Game_object/action/Discard_all_action.hpp"
namespace Action
{
    Discard_all_action::Discard_all_action(){
        duration=ACTION_DUR_XFAST;
    }
    void Discard_all_action::update(const std::shared_ptr<Card::Card_group_handler>&c_handler,Action_group_handler*const action_group_handler){
        if(duration==ACTION_DUR_XFAST)
            c_handler->discard_all();
        TimeGo();
    }
} // namespace Action
