#include "RUtil/Game_Input.hpp"
#include "Game_object/dungeon/Dungeon_screen.hpp"
namespace Dungeon
{
    Dungeon_screen::Dungeon_screen():the_map(offsetY,on_top){
        offsetY = -100.0F * Setting::SCALE;
        target_offsetY=offsetY;
        scroll_wait_timer=0.0F;
        grabbed=false;
        on_top=true;
    }
    void Dungeon_screen::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        the_map.render(r2);
        if(display_map!=nullptr){
            for(const auto&it:*display_map)
                for(const auto&it2:it)
                    if(it2!=nullptr)it2->render(r2,offsetY);
        }else{
            LOG_ERROR("Forget to set the dispaly_map.");
        }
    }
    void Dungeon_screen::update(const Lazy_package &lazy_package){
        the_map.update();
        bool pause_offset_y_update=false;
        if(display_map!=nullptr){
            for(const auto&it:*display_map)
                for(const auto&it2:it)
                    if(it2!=nullptr){
                        it2->update(offsetY,true,on_top,lazy_package.top_effs);
                        if(it2->IsMakingCircle()){
                            pause_offset_y_update=true;
                        }
                    }
        }else{
            LOG_ERROR("Forget to set the dispaly_map.");
        }

        if(!pause_offset_y_update) this->updateOffsetY();
    }
    void Dungeon_screen::updateOffsetY(){
        if(grabbed){
            if(RUtil::Game_Input::is_down()){
                target_offsetY=(float)RUtil::Game_Input::getY()-grab_startY;
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
                grab_startY = (float)RUtil::Game_Input::getY() - target_offsetY;
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
    
    void Dungeon_screen::set_display_map(const std::vector<std::vector<std::shared_ptr<Map::Map_node>>>&map){
        for(const auto&it:map)
            for(const auto&it2:it)
                if(it2!=nullptr)it2->BindLegend(this->the_map.GetLegend());
        display_map=&map;
    }
    Interface::Screen Dungeon_screen::where_want_to_go(){
        return Interface::Screen::On_map;
    }
} // namespace Dungeon
