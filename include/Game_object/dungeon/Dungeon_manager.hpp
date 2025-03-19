#ifndef GAME_OBJECT_DUNGEON_DUNGEON_MANAGER
#define GAME_OBJECT_DUNGEON_DUNGEON_MANAGER
#include "Game_object/dungeon/Dungeon_screen.hpp"
#include "Game_object/interface/Is_screen.hpp"
namespace Object{
    //This class will auto update
    class Dungeon_manager
    {
    public:
        Dungeon_manager();
        ~Dungeon_manager()=default;
        void update();
        void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    private:
        Interface::Screen Current_screen;
        std::shared_ptr<Object::Dungeon_screen> m_dungeon_screen;
    };
}
#endif