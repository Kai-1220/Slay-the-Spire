#include "Game_object/map/Map_node.hpp"
#include "Game_object/map/Map_edge.hpp"
#include "Game_object/room/Rooms.hpp"
#include "Game_object/effect/Map_circle_effect.hpp"
#include "Game_object/effect/Effect_group.hpp"
#include "RUtil/ColorValuesOnly.hpp"
#include "RUtil/Image_book.hpp"

#include "Util/Logger.hpp"

namespace Map{
//mikannsei
Map_node::Map_node(int x,int y):x(x),y(y),hb(64.0F*Setting::SCALE,64.0F*Setting::SCALE){
    this->offset_x=(float)((int)RUtil::Random::GetRandomFloat(-JITTER_X, JITTER_X));
    this->offset_y=(float)((int)RUtil::Random::GetRandomFloat(-JITTER_Y, JITTER_Y));
    color=NOT_TAKEN_COLOR;
    m_scale=0.5F;
    color_a=1.0F;
    m_angle=RUtil::Random::GetRandomFloat(0.0F,360.0F);
    oscillate_timer=RUtil::Random::GetRandomFloat(0.0F,2.0F*glm::pi<float>());
    taken=right=left=middle=to_boss=is_ready_to_connect=highlight=making_circle=made_circle=false;
    anim_wait_timer=0.0F;
}
void Map_node::update(const float screen_offset,const bool is_dungeon_now_room_complete,const bool on_top,Effect::Effect_group &top_effs){
    hb.move((float)this->x*SPACING_X+OFFSET_X+this->offset_x, (float)this->y*MAP_DST_Y+OFFSET_Y+this->offset_y+screen_offset);
    hb.update();
    if(0.0F < anim_wait_timer){
        anim_wait_timer-=RUtil::Game_Input::delta_time();
        highlight=hb.Hovered();
        oscillate();
        if(anim_wait_timer <= 0.0F){
            making_circle=false;
            highlight=false;
            color_a=1.0F;
        }
        return;
    }
    if(made_circle){
        if(*legend_hovered) m_scale=0.68F;
        else if(hb.Hovered()) m_scale=1.0F;
        else m_scale=RUtil::Math::varlerp(m_scale,0.5F,8.0F,0.003F);
        return;
    }
    highlight=false;
    color=Map_node::AVAILABLE_COLOR;
    color_a=1.0F;
    if(*legend_hovered){
        m_scale=0.68F;
    }else if(is_ready_to_connect&&is_dungeon_now_room_complete){
        if(hb.Clicked()&&on_top){
            //node be selected
            top_effs.AddTop(std::make_shared<Effect::Map_circle_effect>((float)this->x*SPACING_X+OFFSET_X+this->offset_x,(float)this->y*MAP_DST_Y+OFFSET_Y+screen_offset+this->offset_y,this->m_angle));
            making_circle=true;
            made_circle=true;
            anim_wait_timer=0.25F;
        }else if(hb.Hovered()){
            highlight=true;
        }
        oscillate();
    }else if(hb.Hovered()){
        m_scale=1.0F;
    }else{
        m_scale=RUtil::Math::varlerp(m_scale,0.5F,8.0F,0.003F);
        color=Map_node::NOT_TAKEN_COLOR;
    }
}
void Map_node::oscillate(){
    oscillate_timer+=RUtil::Game_Input::delta_time()*5.0F;
    color_a=0.66F+(glm::cos(oscillate_timer)+1.0F)/6.0F;
    m_scale=0.25F+color_a;
}
void Map_node::render(const std::shared_ptr<Draw::Draw_2D> &r2,const float screen_offset,const float map_a)const{
    for(const std::shared_ptr<Map_edge> &it:edges){
        it->render(r2,screen_offset);
    }
    if(*legend_hovered){
        r2->SetColor(RUtil::Colors::LIGHT_GRAY,map_a);
    }else if(this->highlight)
        r2->SetColor(0.9F,0.9F,0.9F,map_a);
    else
        r2->SetColor(OUTLINE_COLOR,map_a);
    r2->draw(this->m_room->GetOutlineTexture(), (float)this->x * SPACING_X + OFFSET_X - 64.0F + this->offset_x, (float)this->y * MAP_DST_Y + OFFSET_Y + screen_offset - 64.0F + this->offset_y, 128.0F, 128.0F, 0.0F, 64.0F, 64.0F, this->m_scale * Setting::SCALE, this->m_scale * Setting::SCALE);
    
    r2->SetColor(this->color,this->color_a*map_a);
    r2->draw(this->m_room->GetTexture(), (float)this->x * SPACING_X + OFFSET_X - 64.0F + this->offset_x, (float)this->y * MAP_DST_Y + OFFSET_Y + screen_offset - 64.0F + this->offset_y, 128.0F, 128.0F, 0.0F, 64.0F, 64.0F, this->m_scale * Setting::SCALE, this->m_scale * Setting::SCALE);
    
    if(taken)
        r2->draw(s_circle, (float)this->x * SPACING_X + OFFSET_X - 96.0F + this->offset_x, (float)this->y * MAP_DST_Y + OFFSET_Y + screen_offset - 96.0F + this->offset_y, 192.0F, 192.0F, this->m_angle, 96.0F, 96.0F, (this->m_scale * 0.95F + 0.2F) * Setting::SCALE, (this->m_scale * 0.95F + 0.2F) * Setting::SCALE);
}
std::shared_ptr<Map_edge>Map_node::GetConnectedEdge(const std::shared_ptr<Map_node> &node){
    for(const auto&it:edges){
        if(it->to_y==node->y && it->to_x==node->x)
            return it;
    }
    LOG_ERROR("Can't get connected edge.");
    return nullptr;
}
void Map_node::MarkAllEdge(const bool is_taken)const{
    for(const auto&it:edges) it->MarkTaken(is_taken);
}
void Map_node::add_edge(const std::shared_ptr<Map_edge> &edge){edges.emplace_back(edge);}
void Map_node::SetRight(bool x){right=x;}
void Map_node::SetLeft(bool x){left=x;}
void Map_node::SetMiddle(bool x){middle=x;}
void Map_node::SetToBoss(bool x){to_boss=x;}
void Map_node::SetRoom(const std::shared_ptr<Room::Rooms> &room){this->m_room=room;}
const std::shared_ptr<Draw::ReTexture> &Map_node::s_circle=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/circle5.png");
}