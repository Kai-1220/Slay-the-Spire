#include "Game_object/room/Monster_room.hpp"
#include "RUtil/Image_book.hpp"
namespace Room{
Monster_room::Monster_room(){
    if(IMG==nullptr){
        IMG=RUtil::Image_book::GetTexture("image/map/monster.png");
        IMG_O=RUtil::Image_book::GetTexture("image/map/monsterOutline.png");
    }
}
std::shared_ptr<Draw::ReTexture> Monster_room::IMG=nullptr,Monster_room::IMG_O=nullptr;
}