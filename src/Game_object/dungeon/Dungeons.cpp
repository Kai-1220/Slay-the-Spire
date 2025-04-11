#include "Game_object/dungeon/Dungeons.hpp"
#include "Game_object/scene/Bottom_scene.hpp"
#include "Game_object/effect/Fade_wide.hpp"
namespace Dungeon{
    Dungeons::Dungeons(){
        effs=std::make_shared<Effect::Effect_group>();
        top_effs=std::make_shared<Effect::Effect_group>();
        scene=std::make_shared<Scene::Bottom_scene>();
        scene->next_room();
        map_rng=std::make_shared<RUtil::Random>(time(0));
        m_map=Map::Map_generator::Get_Map(15,7,6,map_rng);
        m_dungeon_manager.set_display_map(m_map);
        m_current_node=nullptr;
        set_next_node_oscillate_and_edge(true);
        is_fade_in=is_fade_out=false;
        fade_color_a=0.0F;
    }
    void Dungeons::update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,const std::shared_ptr<Action::Action_group_handler>&action_group_handler,const RUtil::Random_package &random_package){
        effs->update();
        top_effs->update();
        if(m_current_node!=nullptr) m_current_node->GetRoom()->update(action_group_handler,card_group_handler,random_package);
        m_dungeon_manager.update({card_group_handler,action_group_handler,effs,top_effs});
        if(!is_fade_in&&!is_fade_out){
            if(!next_node_is_making_circle){
                if(check_next_node_making_circle()){
                    //this function should only be triggered only when the node just starting to make a circle effect.
                    next_node_is_making_circle=true;
                    top_effs->AddTop(std::make_shared<Effect::Fade_wide>(fade_color));
                }
            }else{
                if(!check_next_node_making_circle()){
                    fade_out();
                }
            }
        }else{
            update_fading();
            if(fade_timer==0.0F){//finished fading.
                if(next_node_is_making_circle){//if fading is cause by node.
                    next_node_is_making_circle=false;
                    set_next_node_oscillate_and_edge(false);
                    change_current_node_to_next();
                    set_next_node_oscillate_and_edge(true);
                    fade_in();
                }
            }
        }
        
    }
    void Dungeons::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        scene->render(r2);
        if(m_current_node!=nullptr) m_current_node->GetRoom()->render(r2);
        effs->render(r2);
        m_dungeon_manager.render(r2);
        top_effs->render(r2);
        r2->SetColor(fade_color,fade_color_a);
        r2->draw(Effect::Fade_wide::white_square, 0.0F, 0.0F, WINDOW_WIDTH, WINDOW_HEIGHT);
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
    bool Dungeons::check_next_node_making_circle()const{
        if(m_current_node==nullptr){
            for(const auto&it:m_map[0])
                if(it!=nullptr&&it->IsMakingCircle()) return true;
        }else{
            if( (m_current_node->CanMoveRight() && m_map[m_current_node->y+1][m_current_node->x+1]->IsMakingCircle())||
                (m_current_node->CanMoveMiddle() && m_map[m_current_node->y+1][m_current_node->x]->IsMakingCircle())||
                (m_current_node->CanMoveLeft() && m_map[m_current_node->y+1][m_current_node->x-1]->IsMakingCircle())) return true;
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
            fade_color_a = RUtil::Math::interpolation_fade(1.0F,0.0F,fade_timer/0.8F);
            if(fade_timer<0.0F){
                fade_timer=0.0F;
                fade_color_a=0.0F;
                is_fade_in=false;
            }
        }else if(is_fade_out){
            fade_color_a = RUtil::Math::interpolation_fade(0.0F,1.0F,fade_timer/0.8F);
            if(fade_timer<0.0F){
                fade_timer=0.0F;
                fade_color_a=1.0F;
                is_fade_out=false;
            }
        }else LOG_ERROR("Not fading but the update_fading() be called.");
    }
    void Dungeons::change_current_node_to_next(){
        if(m_current_node==nullptr){
            bool error_flag=true;
            for(const auto&it:m_map[0])
                if(it!=nullptr&&it->GetTaken()){
                    error_flag=false;
                    m_current_node=it;
                    break;
                }
            if(error_flag)LOG_ERROR("Error when change current node.");
        }else{
            if(m_current_node->CanMoveRight()&&m_map[m_current_node->y+1][m_current_node->x+1]->GetTaken()){
                m_current_node->GetConnectedEdge(m_map[m_current_node->y+1][m_current_node->x+1])->MarkTaken(true);
                m_current_node=m_map[m_current_node->y+1][m_current_node->x+1];
            }else if(m_current_node->CanMoveMiddle()&&m_map[m_current_node->y+1][m_current_node->x]->GetTaken()){
                m_current_node->GetConnectedEdge(m_map[m_current_node->y+1][m_current_node->x])->MarkTaken(true);
                m_current_node=m_map[m_current_node->y+1][m_current_node->x];
            }else if(m_current_node->CanMoveLeft()&&m_map[m_current_node->y+1][m_current_node->x-1]->GetTaken()){
                m_current_node->GetConnectedEdge(m_map[m_current_node->y+1][m_current_node->x-1])->MarkTaken(true);
                m_current_node=m_map[m_current_node->y+1][m_current_node->x-1];
            }else LOG_ERROR("Error when change current node.");
        }
    }
}