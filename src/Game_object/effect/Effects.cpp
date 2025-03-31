#include "Game_object/effect/Effects.hpp"
#include "RUtil/Game_Input.hpp"
namespace Effect{
    void Effects::TimeGo(){
        duration-=DT;
        if(duration<0.0F)
            is_done=true;
    }
    const float &Effects::DT=RUtil::Game_Input::delta_time();
}