#include "Game_object/action/Action_group_handler.hpp"
namespace Action
{
    void Action_group_handler::update(){
        if(is_wating_player){

        }
    }
    void Action_group_handler::get_next_action(){
        if(!action_box.empty()){
            current_action=action_box.PopTop();
            is_wating_player=false;
        }else if(!pre_action_box.empty()){

            is_wating_player=false;
        }else if(!card_queue.empty()){

        }
    }
} // namespace Action
