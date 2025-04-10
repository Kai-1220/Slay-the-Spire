#ifndef GAME_OBJECT_DUNGEON_DUNGEON_MANAGER
#define GAME_OBJECT_DUNGEON_DUNGEON_MANAGER
#include "Game_object/dungeon/Dungeon_screen.hpp"
namespace Dungeon{
    //This class will auto change where need to update or render.
    class Dungeon_manager
    {
    public:
        Dungeon_manager();
        ~Dungeon_manager()=default;
        void update(const Lazy_package &lazy_package);
        void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
        void set_display_map(const std::vector<std::vector<std::shared_ptr<Map::Map_node>>>&map)const{m_dungeon_screen->set_display_map(map);}
    private:
        Interface::Screen Current_screen;
        std::shared_ptr<Dungeon::Dungeon_screen> m_dungeon_screen;
    };
}
#endif