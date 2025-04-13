#include "Game_object/map/Map_edge.hpp"
#include "Game_object/map/Map_node.hpp"
#include "Draw/Draw_2D.hpp"
#include "RUtil/Some_Math.hpp"

namespace Map{
Map_edge::Map_edge(int from_x,int from_y,int to_x,int to_y,
        float from_offset_x,float from_offset_y,
        float to_offset_x,float to_offset_y,bool is_boss)
        :from_x(from_x),from_y(from_y),to_x(to_x),to_y(to_y){
    color=DISABLED_COLOR;
    float src_x=(float)from_x * SPACE_X + Map_node::OFFSET_X +from_offset_x,
            dst_x=(float)to_x   * SPACE_X + Map_node::OFFSET_X +to_offset_x,
            src_y=(float)from_y * Map_node::MAP_DST_Y + from_offset_y,
            dst_y=(float)to_y   * Map_node::MAP_DST_Y + to_offset_y;
    glm::vec2 line_vec{dst_x-src_x,dst_y-src_y};
    float line_length=glm::length(line_vec),
            line_rotate_red=RUtil::Math::GetRadian(line_vec),
            line_rotate_deg=glm::degrees(line_rotate_red),
            START=SPACING * RUtil::Random::GetRandomFloat(0.0F,1.0F) / 2.0F,
            end_r=ICON_DST_RADIUS;
    if(is_boss)end_r=164.0F * Setting::SCALE;
    for(float i=START+ICON_SRC_RADIUS;i<line_length-end_r;i+=SPACING){
        bool is_jitter=true;
        if(i!=START+ICON_SRC_RADIUS&&i<=line_length-ICON_DST_RADIUS-SPACING)//check not first and not last
            is_jitter=false;
        this->dots.emplace_back(src_x + i*glm::cos(line_rotate_red),src_y + i*glm::sin(line_rotate_red),line_rotate_deg,is_jitter);
    }
}
void Map_edge::render(const std::shared_ptr<Draw::Draw_2D> &r2,float screen_offset)const{
    r2->SetColor_RGBA(color);
    for(const Map_dot &it:dots){
        it.render(r2,screen_offset);
    }
}
void Map_edge::MarkTaken(const bool is_taken){this->color=is_taken?Map_node::AVAILABLE_COLOR:Map_node::NOT_TAKEN_COLOR;}
}