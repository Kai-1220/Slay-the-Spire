#pragma once

#include <vector>
#include <SDL_stdinc.h>//uint

#include "Game_object/map/Map_dot.hpp"
#include "WindowSize.hpp"

//fwd decl
namespace Draw{
    class Draw_2D;
}

namespace Map{
class Map_edge{
public:
    Map_edge(int from_x,int from_y,int to_x,int to_y,
            float from_offset_x,float from_offset_y,
            float to_offset_x,float to_offset_y,bool is_boss);
    ~Map_edge()=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2,float screen_offset)const;
    void MarkTaken(const bool is_taken);
    const int from_x,from_y,to_x,to_y; 
private:
    std::vector<Map_dot> dots;
    Uint32 color;
    static constexpr Uint32 DISABLED_COLOR=0x00000040;
    static constexpr float SPACE_X=128.0F*Setting::SCALE,
                           SPACING=17.0F*Setting::SCALE,
                           ICON_SRC_RADIUS = 29.0F * Setting::SCALE,
                           ICON_DST_RADIUS = 20.0F * Setting::SCALE;
                           
};
}