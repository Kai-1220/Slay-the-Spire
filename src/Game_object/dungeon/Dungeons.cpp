#include "Game_object/dungeon/Dungeons.hpp"
#include "Game_object/dungeon/Dungeon_shared.hpp"
#include "Game_object/scene/Bottom_scene.hpp"
#include "Game_object/effect/Fade_wide.hpp"
#include "Game_object/map/Map_node.hpp"
#include "Game_object/map/Map_edge.hpp"

#include "Util/Logger.hpp"

namespace Dungeon{
    Dungeons::Dungeons(Dungeon_shared &dungeon_shared,RUtil::Random_package &random_package,unsigned long long int random_seed):m_dungeon_shared(dungeon_shared),m_random_package(random_package),random_seed(random_seed){
        scene=std::make_shared<Scene::Bottom_scene>();
        player=std::make_shared<Character::Player>();
        m_overlay.set_player_to_energy_panel(player);
        scene->next_room();
        m_map=Map::Map_generator::Get_Map(15,7,6,m_random_package.map_rng);
        m_dungeon_manager.set_display_map(m_map);
        m_current_node=nullptr;
        set_next_node_oscillate_and_edge(true);
        is_fade_in=is_fade_out=false;
        fade_color_a=0.0F;
    }
    void Dungeons::update(){
        m_dungeon_shared.effs.update();
        m_dungeon_shared.top_effs.update();
        if(m_current_node!=nullptr) m_current_node->GetRoom()->update(m_dungeon_shared.action_group_handler,m_dungeon_shared.card_group_handler,m_overlay,m_random_package);
        m_dungeon_shared.card_group_handler.update_hand_cards(m_dungeon_shared.effs,player->GetCardTrailColor());
        m_overlay.update();
        m_dungeon_manager.update(m_dungeon_shared);
        if(!is_fade_in&&!is_fade_out){
            if(!next_node_is_making_circle){
                if(check_and_set_next_node_making_circle()){
                    //this function should only be triggered only when the node just starting to make a circle effect.
                    next_node_is_making_circle=true;
                    m_dungeon_manager.set_current_on_top(false);
                    m_dungeon_shared.top_effs.AddTop(std::make_shared<Effect::Fade_wide>(fade_color));
                }
            }else{
                if(!check_and_set_next_node_making_circle()){
                    fade_out();
                }
            }
        }else{
            update_fading();
            if(fade_timer==0.0F){//finished fading.
                if(next_node_is_making_circle){//if fading is cause by node.
                    next_node_is_making_circle=false;
                    entering_next_room();
                }
            }
        }
        
    }
    void Dungeons::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        scene->render(r2);
        if(m_current_node!=nullptr) m_current_node->GetRoom()->render(r2);
        m_dungeon_shared.card_group_handler.render_hand(r2,player->GetCardRenderColor());
        m_overlay.render(r2);
        m_dungeon_shared.effs.render(r2);
        m_dungeon_manager.render(r2);
        m_dungeon_shared.top_effs.render(r2);
        r2->SetColor(fade_color,fade_color_a);
        r2->draw(Effect::Fade_wide::white_square, 0.0F, 0.0F, Setting::WINDOW_WIDTH, Setting::WINDOW_HEIGHT);
    }
    void Dungeons::set_next_node_oscillate_and_edge(const bool value)const{
        if(m_current_node==nullptr){
            for(const auto&it:m_map[0])
                if(it!=nullptr) it->SetReadyToConnect(value);
        }else{
            m_current_node->MarkAllEdge(value);
            if(m_current_node->CanMoveRight())
                m_map[m_current_node->y+1][m_current_node->x+1]->SetReadyToConnect(value);
            if(m_current_node->CanMoveMiddle())
                m_map[m_current_node->y+1][m_current_node->x]->SetReadyToConnect(value);
            if(m_current_node->CanMoveLeft())
                m_map[m_current_node->y+1][m_current_node->x-1]->SetReadyToConnect(value);
        }
    }
    bool Dungeons::check_and_set_next_node_making_circle(){
        if(m_current_node==nullptr){
            for(const auto&it:m_map[0])
                if(it!=nullptr&&it->IsMakingCircle()){
                    m_next_node=it;
                    return true;
                }
        }else{
            if(m_current_node->CanMoveRight() && m_map[m_current_node->y+1][m_current_node->x+1]->IsMakingCircle()){
                m_next_node=m_map[m_current_node->y+1][m_current_node->x+1];
                return true;
            }else if(m_current_node->CanMoveMiddle() && m_map[m_current_node->y+1][m_current_node->x]->IsMakingCircle()){
                m_next_node=m_map[m_current_node->y+1][m_current_node->x];
                return true;
            }else if(m_current_node->CanMoveLeft() && m_map[m_current_node->y+1][m_current_node->x-1]->IsMakingCircle()){
                m_next_node=m_map[m_current_node->y+1][m_current_node->x-1];
                return true;
            }
        }
        return false;
    }
    void Dungeons::fade_in(){
        if(is_fade_out) LOG_ERROR("Dungeon fade_in() be triggered when fade_out() is not finished.");
        is_fade_in=true;
        fade_timer=0.8F;
    }
    void Dungeons::fade_out(){
        if(is_fade_in) LOG_ERROR("Dungeon fade_out() be triggered when fade_in() is not finished.");
        is_fade_out=true;
        fade_timer=0.8F;
    }
    void Dungeons::update_fading(){
        fade_timer-=RUtil::Game_Input::delta_time();
        if(is_fade_in){
            fade_color_a = RUtil::Math::interpolation_fade(0.0F,1.0F,fade_timer/0.8F);
            if(fade_timer<0.0F){
                fade_timer=0.0F;
                fade_color_a=0.0F;
                is_fade_in=false;
            }
        }else if(is_fade_out){
            fade_color_a = RUtil::Math::interpolation_fade(1.0F,0.0F,fade_timer/0.8F);
            if(fade_timer<0.0F){
                fade_timer=0.0F;
                fade_color_a=1.0F;
                is_fade_out=false;
            }
        }else LOG_ERROR("Not fading but the update_fading() be called.");
    }
    void Dungeons::change_current_node_to_next(){
        if(m_next_node==nullptr){
            LOG_ERROR("Error when change current node.");
            return;
        }
        if(m_current_node!=nullptr){
            m_current_node->GetConnectedEdge(m_next_node)->MarkTaken(true);
        }
        m_current_node=m_next_node;
        m_current_node->MarkTaken();
        m_next_node=nullptr;
    }
    void Dungeons::entering_next_room(){
        set_next_node_oscillate_and_edge(false);
        change_current_node_to_next();
        set_next_node_oscillate_and_edge(true);
        fade_in();
        m_dungeon_shared.effs.Clear();
        m_dungeon_shared.top_effs.Clear();
        m_current_node->GetRoom()->init_room();
        m_random_package.ResetRoomRNGs(this->random_seed+m_current_node->y);
        m_dungeon_manager.hide_dungeon_screen_instantly();
        m_dungeon_shared.card_group_handler.prepare_for_battle(m_random_package.card_shuffle_rng);
        m_dungeon_shared.action_group_handler.prepare_for_battle();
        scene->next_room();

    }
}