#include "Game_object/dungeon/Dungeon_manager.hpp"
#include "Util/Logger.hpp"
namespace Dungeon{
    Dungeon_manager::Dungeon_manager(){
        m_dungeon_screen=std::make_shared<Dungeon::Dungeon_screen>();
        Current_screen=m_dungeon_screen;
    }
    void Dungeon_manager::update(const Lazy_package &lazy_package){
        Current_screen->update(lazy_package);
    }
    void Dungeon_manager::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        Current_screen->render(r2);
    }
}