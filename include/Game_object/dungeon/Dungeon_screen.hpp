#ifndef GAME_OBJECT_DUNGEON_DUNGEON_SCREEN
#define GAME_OBJECT_DUNGEON_DUNGEON_SCREEN
#include "Game_object/dungeon/Dungeon_map.hpp"
#include "Draw/Draw_2D.hpp"
namespace Object{
class Dungeon_screen
{
public:
    Dungeon_screen();
    ~Dungeon_screen()=default;
    void render(std::shared_ptr<Draw::Draw_2D> r2);
    void update();
private:
    std::shared_ptr<Object::Dungeon_map> the_map;
    float offsetY;
};
}
#endif