#include "Game_object/dungeon/Dungeon_screen.hpp"
namespace Object
{
    Dungeon_screen::Dungeon_screen(){
        the_map=std::make_shared<Dungeon_map>();
        offsetY = -100.0F * Setting::SCALE;
    }
    void Dungeon_screen::render(std::shared_ptr<Draw::Draw_2D> r2){
        the_map->render(r2,offsetY);
    }
    void Dungeon_screen::update(){

    }
} // namespace Object
