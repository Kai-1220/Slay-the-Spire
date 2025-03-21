#include "Game_object/dungeon/Dungeon_BottomScene.hpp"
Object::Dungeon_BottomScene::Dungeon_BottomScene()
{
    Background=std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/bottomScene/scene.jpg"),2,50,1920,1136-50);
    mods.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/bottomScene/scene2.png"),2,402,745,572));
    mods.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/bottomScene/scene.png"),2,500,1920,771));
    mods.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/bottomScene/scene.png"),2,1273,1920,278));
    deckButton=std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/deckButton/base.png"));
    discardButton=std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/discardButton/base.png"));
    buttonL=std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/endTurnButton.png"));
    for(int i=1;i<7;i++){
        layers.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(std::string(RESOURCE_DIR "/Image/topPanel/red/layer") + std::to_string(i) + ".png"),2,2,128,128));
    }   
    for(int i=1;i<6;i++){
        layersd.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(std::string(RESOURCE_DIR "/Image/topPanel/red/layer") + std::to_string(i) + "d.png"),2,2,128,128));
    }
    layersd.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR "/Image/topPanel/red/layer6.png"),2,2,128,128));
}
void Object::Dungeon_BottomScene::render(std::shared_ptr<Draw::Draw_2D> r2){
    r2->draw(Background, 0.0F, 0.0F, 1920*Setting::SCALE, 1180*Setting::SCALE);
    for(int i=0;i<mods.size();i++){
        r2->draw(mods[i], mods_pos[i].x, mods_pos[i].y, mods_size[i].x, mods_size[i].y);
    }
    r2->draw(deckButton,50,25,110,110);
    r2->draw(discardButton,1125,25,110,110);
    r2->draw(buttonL,930,100,180,180);
    for(int i=0;i<layersd.size();i++){
        r2->draw(layersd[i], layerPos.x, layerPos.y, layerSize.x, layerSize.y);
    }
}