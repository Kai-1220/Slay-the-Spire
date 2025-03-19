#include "Game_object/dungeon/Dungeon_BottomScene.hpp"
Object::Dungeon_BottomScene::Dungeon_BottomScene()
{
    Background=std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/image/bottomScene/scene.jpg"),2,50,1920,1136-50);
    mods.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/image/bottomScene/scene2.png"),2,402,745,572));
    mods.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/image/bottomScene/scene.png"),2,500,1920,771));
}
void Object::Dungeon_BottomScene::render(std::shared_ptr<Draw::Draw_2D> r2){
    r2->draw(Background, 0.0F, 0.0F, 1920*Setting::SCALE, 1180*Setting::SCALE);
    for(int i=0;i<mods.size();i++){
        r2->draw(mods[i], mods_pos[i].x, mods_pos[i].y, mods_size[i].x, mods_size[i].y);
    }
}