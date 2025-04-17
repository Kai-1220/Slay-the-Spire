#ifndef GAME_OBJECT_ROOM_MONSTER_ROOM
#define GAME_OBJECT_ROOM_MONSTER_ROOM
#include "Game_object/room/rooms.hpp"
#include "RUtil/Image_book.hpp"
#include "Game_object/character/Monster/Monsters.hpp"
#include "Game_object/character/Monster/AcidSlimeL.hpp"
#include "Game_object/character/Monster/FatGremlin.hpp"
#include "Game_object/character/Monster/JawWorm.hpp"
#include "Game_object/character/Player.hpp"
namespace Room{
//need:Monster Player Cards BattleManage
class Monster_room:public Rooms
{
public:
    Monster_room();
    const std::shared_ptr<Draw::ReTexture> &GetTexture()const override{return IMG;}
    const std::shared_ptr<Draw::ReTexture> &GetOutlineTexture()const override{return IMG_O;}
    void update(Action::Action_group_handler &action_group_handler,Card::Card_group_handler &card_group_handler,Dungeon::Overlay &overlay,const RUtil::Random_package &random_package)override;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void init_room()override;
private:
    void prepare_to_battle();
    float m_wait_timer;
    std::shared_ptr<Monster::Monsters> m_monster=nullptr;
    Monster::MonsterID m_monster_id=Monster::MonsterID::None;
    static const std::shared_ptr<Draw::ReTexture> &IMG;
    static const std::shared_ptr<Draw::ReTexture> &IMG_O;
    std::shared_ptr<Monster::AcidSlimeL> m_acid_slime_l;
    std::shared_ptr<Monster::FatGremlin> m_fat_gremlin;
    std::shared_ptr<Monster::JawWorm> m_jaw_worm;
    std::shared_ptr<Character::Player> m_player;
};
}
#endif