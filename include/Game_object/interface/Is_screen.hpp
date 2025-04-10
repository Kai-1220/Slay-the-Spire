#ifndef GAME_OBJECT_DUNGEON_IS_SCREEN
#define GAME_OBJECT_DUNGEON_IS_SCREEN
#include "Draw/Draw_2D.hpp"
#include "Game_object/Lazy_package.hpp"
namespace Interface{
enum class Screen{
    On_map,
    On_battle
};
class Is_screen
{
public:  
    virtual ~Is_screen()=default;
    virtual void update(const Lazy_package &lazy_package)=0;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    virtual Screen where_want_to_go()=0;
    void set_on_top(bool value){on_top=value;}
protected:
    bool on_top=false;
};
}
#endif