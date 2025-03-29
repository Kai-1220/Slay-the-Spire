#include "Game_object/action/Actions.hpp"
namespace Action{
    void Actions::TimeGo(){
        duration-=DT;
        if(duration<0.0F)
            is_done=true;
    }
}