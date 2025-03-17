#ifndef GAME_OBJECT_DUNGEON_DUNGEON_SCREEN
#define GAME_OBJECT_DUNGEON_DUNGEON_SCREEN
#include "Game_object/map/Dungeon_map.hpp"
#include "Game_object/interface/Is_screen.hpp"
namespace Object{
class Dungeon_screen:public Interface::Is_screen
{
public:
    Dungeon_screen();
    ~Dungeon_screen()=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update(Interface::Screen Now_screen) override;
    Interface::Screen Where_want_to_go() override;
private:
    void updateOffsetY();
    void reset_scroll();
    void update_animation();
    std::shared_ptr<Map::Dungeon_map> the_map;
    float offsetY,target_offsetY,scroll_wait_timer,grab_startY;
    bool grabbed;
    static constexpr float SCROLL_SPEED=75.0F*Setting::SCALE;
    static constexpr float MAP_UPPER_SCROLL_NORMAL=-2300.0F * Setting::SCALE;
    static constexpr float MAP_SCROLL_LOWER = 190.0F * Setting::SCALE;
};
}
#endif