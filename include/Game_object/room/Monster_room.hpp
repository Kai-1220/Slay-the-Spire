#ifndef GAME_OBJECT_ROOM_MONSTER_ROOM
#define GAME_OBJECT_ROOM_MONSTER_ROOM
#include "Game_object/room/rooms.hpp"
#include "RUtil/Image_book.hpp"
#include "Game_object/character/Monster/Monsters.hpp"
namespace Room{
//need:Monster Player Cards BattleManage
class Monster_room:public Rooms
{
public:
    Monster_room();
    Room_type GetType()const{return Room_type::Monster;}
    std::shared_ptr<Draw::ReTexture> GetTexture()const{return IMG;}
    std::shared_ptr<Draw::ReTexture> GetOutlineTexture()const{return IMG_O;}
    void update(const std::shared_ptr<Action::Action_group> action_group,const std::shared_ptr<Card::Card_group_handler> c_handler);
    void init_room()override;
private:
    bool is_waiting_player;
    std::shared_ptr<Monster::Monsters> m_monster=nullptr;
    Monster::MonsterID m_monster_id=Monster::MonsterID::None;
    const std::shared_ptr<Draw::ReTexture> &IMG=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/map/monster.png");
    const std::shared_ptr<Draw::ReTexture> &IMG_O=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/map/monsterOutline.png");
};
}
#endif