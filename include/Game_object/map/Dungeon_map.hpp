#ifndef GAME_OBJECT_MAP_DUNGEON_MAP
#define GAME_OBJECT_MAP_DUNGEON_MAP
#include "Game_object/map/Legend.hpp"
namespace Map{
class Dungeon_map
{
public:
    Dungeon_map(const float &screen_offsetY,const bool &on_top);
    ~Dungeon_map()=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    // void show();
    // void hide();
    void hide_instantly();
    void update();
    float get_alpha()const{return map_a;}
    const auto &GetLegend()const{return legend;}
private:
    float map_a,map_offsetY,map_target_a,map_mid_pos;
    Legend legend;
    RUtil::Hitbox boss_hitbox;
    bool at_boss;
    Uint32 boss_node_color_rgb;
    const float &screen_offsetY;
    const bool &on_top;
    static constexpr float H = 1020.0F * Setting::SCALE;
    static constexpr float BLEND_H = 512.0F * Setting::SCALE;
    static constexpr float MAP_Y = 150.0F * Setting::SCALE;
    static constexpr float BOSS_L = 512.0F * Setting::SCALE;
    static constexpr float BOSS_OFFSET_Y = 1416.0F * Setting::SCALE;
    static const std::shared_ptr<Draw::ReTexture> &map_top,&map_mid,&map_bottom,&map_blend;

};
}
#endif