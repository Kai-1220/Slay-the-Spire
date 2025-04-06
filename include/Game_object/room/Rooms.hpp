#ifndef GAME_OBJECT_ROOM_ROOMS
#define GAME_OBJECT_ROOM_ROOMS
#include "Draw/ReTexture.hpp"
#include "Game_object/action/Action_group.hpp"
#include "Game_object/card/Card_group_handler.hpp"
namespace Room{
enum class Room_type{
    Monster,
    Shop,
    Rest,
    Event
};

class Rooms{
public:
    Rooms(Room_type type):room_type(type){}
    virtual ~Rooms()=default;
    virtual const std::shared_ptr<Draw::ReTexture> &GetTexture()const=0;
    virtual const std::shared_ptr<Draw::ReTexture> &GetOutlineTexture()const=0;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    virtual void update(const std::shared_ptr<Action::Action_group_handler> &action_group_handler,const std::shared_ptr<Card::Card_group_handler> &card_group_handler)=0;
    virtual void init_room()=0;
    const Room_type room_type;
private:
//player or something
};
}
#endif