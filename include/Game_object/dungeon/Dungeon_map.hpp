#ifndef GAME_OBJECT_DUNGEON_DUNGEON_MAP
#define GAME_OBJECT_DUNGEON_DUNGEON_MAP
#include "pch.hpp"
#include "WindowSize.hpp"
#include "RUtil/Image_book.hpp"
#include "Draw/Draw_2D.hpp"
namespace Object{
class Dungeon_map
{
public:
    Dungeon_map();
    ~Dungeon_map()=default;
    void render(std::shared_ptr<Draw::Draw_2D> r2,float screen_offsetY);
    void show();
    void hide();
    void update();
private:
    std::shared_ptr<Draw::ReTexture> map_top,map_mid,map_bottom,map_blend;
    static constexpr float H = 1020.0F * Setting::SCALE;
    static constexpr float BLEND_H = 512.0F * Setting::SCALE;
    static constexpr float MAP_Y=150.0F*Setting::SCALE;
    float map_a,map_offsetY,map_target_a,map_mid_pos;
};
}
#endif