#include "Game_object/action/Actions.hpp"
namespace Action{
    void Actions::TimeGo(){
        duration-=DT;
        if(duration<0.0F)
            is_done=true;
    }
    const float &Actions::DT=RUtil::Game_Input::delta_time();
}