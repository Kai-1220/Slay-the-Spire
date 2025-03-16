#include "Game_object/map/Map_node.hpp"
#include "RUtil/Some_Math.hpp"
namespace Map{
//mikannsei
Map_node::Map_node(int x,int y):x(x),y(y){
    this->offset_x=(float)((int)RUtil::Math::GetRandomFloat(-JITTER_X, JITTER_X));
    this->offset_y=(float)((int)RUtil::Math::GetRandomFloat(-JITTER_Y, JITTER_Y));
    color=NOT_TAKEN_COLOR;
    m_scale=0.5F;
    m_angle=RUtil::Math::GetRandomFloat(0.0F,360.0F);

}
void Map_node::add_edge(const std::shared_ptr<Map_edge> &edge){edges.emplace_back(edge);}
void Map_node::SetRight(bool x){right=x;}
void Map_node::SetLeft(bool x){left=x;}
void Map_node::SetMiddle(bool x){middle=x;}
void Map_node::SetToBoss(bool x){to_boss=x;}
}