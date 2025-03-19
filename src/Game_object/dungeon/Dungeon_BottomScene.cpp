#include "Game_object/dungeon/Dungeon_BottomScene.hpp"
Object::Dungeon_BottomScene::Dungeon_BottomScene()
{
    Background=std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/image/bottomScene/scene.jpg"),2,50,1920,1136-50);
    mods.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/image/bottomScene/scene2.png"),2,402,745,572));
}
void Object::Dungeon_BottomScene::render(std::shared_ptr<Draw::Draw_2D> r2){
    r2->draw(Background, 0.0F, 0.0F, 1920*Setting::SCALE, 1180*Setting::SCALE);
    r2->draw(mods[0], mods_pos[0].x, mods_pos[0].y, mods_size[0].x, mods_size[0].y);
}