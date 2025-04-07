#include "Game_object/map/Map_node.hpp"
#include "RUtil/Image_book.hpp"
namespace Map{
//mikannsei
Map_node::Map_node(int x,int y):x(x),y(y){
    this->offset_x=(float)((int)RUtil::Random::GetRandomFloat(-JITTER_X, JITTER_X));
    this->offset_y=(float)((int)RUtil::Random::GetRandomFloat(-JITTER_Y, JITTER_Y));
    color=NOT_TAKEN_COLOR;
    m_scale=0.5F;
    m_angle=RUtil::Random::GetRandomFloat(0.0F,360.0F);
    taken=right=left=middle=to_boss=false;
}
void Map_node::render(const std::shared_ptr<Draw::Draw_2D> &r2,float screen_offset)const{
    for(const std::shared_ptr<Map_edge> &it:edges){
        it->render(r2,screen_offset);
    }
    r2->SetColor_RGBA(OUTLINE_COLOR);//highlight
    r2->draw(this->m_room->GetOutlineTexture(), (float)this->x * SPACING_X + OFFSET_X - 64.0F + this->offset_x, (float)this->y * MAP_DST_Y + OFFSET_Y + screen_offset - 64.0F + this->offset_y, 128.0F, 128.0F, 0.0F, 64.0F, 64.0F, this->m_scale * Setting::SCALE * 2.0F, this->m_scale * Setting::SCALE * 2.0F);
    if(this->taken)
        r2->SetColor_RGBA(AVAILABLE_COLOR);
    else
        r2->SetColor_RGBA(this->color);
    r2->draw(this->m_room->GetTexture(), (float)this->x * SPACING_X + OFFSET_X - 64.0F + this->offset_x, (float)this->y * MAP_DST_Y + OFFSET_Y + screen_offset - 64.0F + this->offset_y, 128.0F, 128.0F, 0.0F, 64.0F, 64.0F, this->m_scale * Setting::SCALE, this->m_scale * Setting::SCALE);
    
    if(taken){//need more check
        r2->SetColor_RGBA(AVAILABLE_COLOR);
        r2->draw(s_circle, (float)this->x * SPACING_X + OFFSET_X - 96.0F + this->offset_x, (float)this->y * MAP_DST_Y + OFFSET_Y + screen_offset - 96.0F + this->offset_y, 192.0F, 192.0F, this->m_angle, 96.0F, 96.0F, (this->m_scale * 0.95F + 0.2F) * Setting::SCALE, (this->m_scale * 0.95F + 0.2F) * Setting::SCALE);
    }
}
void Map_node::add_edge(const std::shared_ptr<Map_edge> &edge){edges.emplace_back(edge);}
void Map_node::SetRight(bool x){right=x;}
void Map_node::SetLeft(bool x){left=x;}
void Map_node::SetMiddle(bool x){middle=x;}
void Map_node::SetToBoss(bool x){to_boss=x;}
void Map_node::SetRoom(const std::shared_ptr<Room::Rooms> &room){this->m_room=room;}
const std::shared_ptr<Draw::ReTexture> &Map_node::s_circle=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/circle5.png");
}