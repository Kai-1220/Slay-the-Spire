#include "Game_object/dungeon/Dungeon_manager.hpp"
#include "Util/Logger.hpp"
namespace Object{
    Dungeon_manager::Dungeon_manager(){
        Current_screen=Interface::Screen::On_map;
        m_dungeon_screen=std::make_shared<Object::Dungeon_screen>();
    }
    void Dungeon_manager::update(){
        switch (Current_screen) {
            case Interface::Screen::On_map:
                m_dungeon_screen->update(Current_screen);
                break;
            default:
                LOG_ERROR("Something wrong when switch screen");
                break;
        }
    }
    void Dungeon_manager::render(std::shared_ptr<Draw::Draw_2D> r2){
        switch (Current_screen) {
            case Interface::Screen::On_map:
                m_dungeon_screen->render(r2);
                break;
            default:
                LOG_ERROR("Something wrong when switch screen");
                break;
        }
    }
}