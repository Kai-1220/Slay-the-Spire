#ifndef GAME_OBJECT_DUNGEON_DUNGEON_MANAGER
#define GAME_OBJECT_DUNGEON_DUNGEON_MANAGER

#include "Game_object/dungeon/Dungeon_screen.hpp"
#include "Game_object/map/Map_node.hpp"

namespace Dungeon{
    //This class will auto change where need to update or render.
    class Dungeon_manager
    {
    public:
        Dungeon_manager();
        ~Dungeon_manager()=default;
        void update(Dungeon_shared &dungeon_shared);
        void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
        void set_display_map(const std::vector<std::vector<std::shared_ptr<Map::Map_node>>>&map)const{m_dungeon_screen->set_display_map(map);}
        void set_current_on_top(bool value){Current_screen->set_on_top(value);}
        void hide_dungeon_screen_instantly()const{m_dungeon_screen->hide_instantly();}
    private:
        std::shared_ptr<Interface::Is_screen> Current_screen;
        std::shared_ptr<Dungeon::Dungeon_screen> m_dungeon_screen;
    };
}
#endif