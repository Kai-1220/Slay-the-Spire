#ifndef GAME_OBJECT_ROOM_ROOMS
#define GAME_OBJECT_ROOM_ROOMS
#include "Draw/ReTexture.hpp"
#include "Game_object/action/Action_group.hpp"
#include "Game_object/card/Card_group_handler.hpp"
#include "Game_object/character/Player.hpp"
namespace Room{
enum class Room_type{
    Monster,
    Shop,
    Rest,
    Event,
    Treasure,
    Elite
};
enum class Room_phase{
    complete,
    incomplete
};
class Rooms{
public:
    Rooms(Room_type type):room_type(type){}
    virtual ~Rooms()=default;
    virtual const std::shared_ptr<Draw::ReTexture> &GetTexture()const=0;
    virtual const std::shared_ptr<Draw::ReTexture> &GetOutlineTexture()const=0;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    virtual void update(const std::shared_ptr<Action::Action_group_handler> &action_group_handler,const std::shared_ptr<Card::Card_group_handler> &card_group_handler,const RUtil::Random_package &random_package)=0;
    virtual void init_room()=0;
    const Room_type room_type;
    auto get_phase()const{return room_phase;}
protected:
    Room_phase room_phase=Room_phase::incomplete;
};
}
#endif