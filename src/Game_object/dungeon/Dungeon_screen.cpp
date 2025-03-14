#include "RUtil/Game_Input.hpp"
#include "Game_object/dungeon/Dungeon_screen.hpp"
#include "RUtil/Some_Math.hpp"
#include <iostream>
namespace Object
{
    Dungeon_screen::Dungeon_screen(){
        the_map=std::make_shared<Dungeon_map>();
        offsetY = -100.0F * Setting::SCALE;
        target_offsetY=offsetY;
        scroll_wait_timer=0.0F;
        grabbed=false;
    }
    void Dungeon_screen::render(std::shared_ptr<Draw::Draw_2D> r2){
        the_map->render(r2,offsetY);
    }
    void Dungeon_screen::update(Interface::Screen Now_screen){
        // if (AbstractDungeon.screen == CurrentScreen.MAP) {
            this->updateOffsetY();
        //  }
    }
    void Dungeon_screen::updateOffsetY(){
        if(grabbed){
            if(RUtil::Game_Input::is_down()){
                target_offsetY=(float)RUtil::Game_Input::getYv()-grab_startY;
            }

            else{
                grabbed=false;
            }
                
        }else if(scroll_wait_timer<0.0F){
            if(RUtil::Game_Input::is_scroll_down()){
                // printf("down");
                target_offsetY+=this->SCROLL_SPEED;
            }
            
            else if(RUtil::Game_Input::is_scroll_up()){
                // printf("up");
                target_offsetY-=this->SCROLL_SPEED;

            }
            if (RUtil::Game_Input::just_clicked()) {
                grabbed = true;
                grab_startY = (float)RUtil::Game_Input::getYv() - target_offsetY;
            }
        }
        reset_scroll();
        update_animation();
    }
    void Dungeon_screen::reset_scroll(){
        if(target_offsetY<MAP_UPPER_SCROLL_NORMAL)
            target_offsetY=RUtil::Math::scrolllerp(target_offsetY,MAP_UPPER_SCROLL_NORMAL);
        else if(target_offsetY>MAP_SCROLL_LOWER)
            target_offsetY=RUtil::Math::scrolllerp(target_offsetY,MAP_SCROLL_LOWER);
    }
    void Dungeon_screen::update_animation(){
        if(scroll_wait_timer>-10.0F)//prevent overflow,although I think it's impossible.
            scroll_wait_timer-=RUtil::Game_Input::delta_time();
        if(scroll_wait_timer<0.0F)
            offsetY=RUtil::Math::fadelerp(offsetY,target_offsetY);
        else if(scroll_wait_timer<3.0F)
            offsetY = RUtil::Math::interpolation_exp10(MAP_SCROLL_LOWER,MAP_UPPER_SCROLL_NORMAL, scroll_wait_timer / 3.0F);
    }
    Interface::Screen Dungeon_screen::Where_want_to_go(){
        return Interface::Screen::On_map;
    }
} // namespace Object
