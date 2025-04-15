#include "Game_object/effect/Auto_release_pool_manager.hpp"
#include "RUtil/Game_Input.hpp"
namespace Effect
{
    void Auto_release_pool_manager::update(){
        timer-=RUtil::Game_Input::delta_time();
        if(timer<0.0F){
            timer=CHECK_TIME;
            for(const auto&it:check_box) it();
        }
    }
    float Auto_release_pool_manager::timer=Auto_release_pool_manager::CHECK_TIME;
    std::vector<void(*)()> Auto_release_pool_manager::check_box;
} // namespace Effect
