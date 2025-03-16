#ifndef GAME_OBJECT_MAP_MAP_NODE
#define GAME_OBJECT_MAP_MAP_NODE
#include "pch.hpp"
#include "Game_object/map/Map_edge.hpp"
#include "WindowSize.hpp"
namespace Map{
class Map_node
{
public:
    Map_node(int x,int y);
    ~Map_node()=default;
    bool CanMoveRight()const{return right;}
    bool CanMoveMiddle()const{return middle;}
    bool CanMoveLeft()const{return left;}
    bool CanToBoss()const {return to_boss;}
    int GetX()const{return x;}
    int GetY()const{return y;}
    float GetOffsetX()const{return offset_x;}
    float GetOffsetY()const{return offset_y;}
    void add_edge(const std::shared_ptr<Map_edge> &edge);
    void SetRight(bool x);
    void SetLeft(bool x);
    void SetMiddle(bool x);
    void SetToBoss(bool x);
private:
    int x,y;
    float offset_x,offset_y,m_scale,m_angle;
    bool right,middle,left,to_boss;
    Uint32 color;
    //the edges only point to future.
    std::vector<std::shared_ptr<Map_edge>> edges;

    static constexpr float JITTER_X=27.0F * Setting::SCALE,
                           JITTER_Y=37.0F * Setting::SCALE;
    static constexpr Uint32 OUTLINE_COLOR=0x8c8c80ff;
public:
    static constexpr float OFFSET_X= 560.0F * Setting::SCALE;
    static constexpr Uint32 AVAILABLE_COLOR = 371272703U,
                            NOT_TAKEN_COLOR = 1448498943U;
};
}
#endif