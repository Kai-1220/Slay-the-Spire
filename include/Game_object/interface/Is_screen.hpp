#ifndef GAME_OBJECT_DUNGEON_IS_SCREEN
#define GAME_OBJECT_DUNGEON_IS_SCREEN
#include "Draw/Draw_2D.hpp"
namespace Interface{
enum class Screen{
    On_map,
    On_battle
};
class Is_screen
{
public:  
    virtual ~Is_screen()=default;
    virtual void update(Screen Now_screen)=0;
    virtual void render(std::shared_ptr<Draw::Draw_2D> r2)=0;
    virtual Screen Where_want_to_go()=0;
};
}
#endif