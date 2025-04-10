#include "Game_object/dungeon/Dungeon_manager.hpp"
#include "Util/Logger.hpp"
namespace Dungeon{
    Dungeon_manager::Dungeon_manager(){
        Current_screen=Interface::Screen::On_map;
        m_dungeon_screen=std::make_shared<Dungeon::Dungeon_screen>();
    }
    void Dungeon_manager::update(const Lazy_package &lazy_package){
        switch (Current_screen) {
            case Interface::Screen::On_map:
                m_dungeon_screen->update(lazy_package);
                break;
            default:
                LOG_ERROR("Something wrong when switch screen");
                break;
        }
    }
    void Dungeon_manager::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
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