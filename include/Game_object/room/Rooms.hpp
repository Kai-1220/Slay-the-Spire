#ifndef GAME_OBJECT_ROOM_ROOMS
#define GAME_OBJECT_ROOM_ROOMS
#include "Draw/ReTexture.hpp"
#include <type_traits>
#include "Game_object/action/Action_group.hpp"
#include "Game_object/card/Card_group_handler.hpp"
namespace Room{
enum class Room_type{
    Monster
};

class Rooms{
public:
    virtual ~Rooms()=default;
    virtual Room_type GetType()const=0;
    virtual std::shared_ptr<Draw::ReTexture> GetTexture()const=0;
    virtual std::shared_ptr<Draw::ReTexture> GetOutlineTexture()const=0;
    // virtual void update();//cardhander,character,
    virtual void init_room()=0;
private:
//player or something
};
}
#endif