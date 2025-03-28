#ifndef GAME_OBJECT_ROOM_MONSTER_ROOM
#define GAME_OBJECT_ROOM_MONSTER_ROOM
#include "Game_object/room/rooms.hpp"
#include "RUtil/Image_book.hpp"
namespace Room{
//need:Monster Player Cards BattleManage
class Monster_room:public Rooms
{
public:
    Monster_room();
    Room_type GetType()const{return Room_type::Monster;}
    std::shared_ptr<Draw::ReTexture> GetTexture()const{return IMG;}
    std::shared_ptr<Draw::ReTexture> GetOutlineTexture()const{return IMG_O;}
private:
    const std::shared_ptr<Draw::ReTexture> &IMG=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/map/monster.png");
    const std::shared_ptr<Draw::ReTexture> &IMG_O=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/map/monsterOutline.png");
};
}
#endif