#ifndef GAME_OBJECT_ROOM_ROOMS
#define GAME_OBJECT_ROOM_ROOMS
#include "Draw/ReTexture.hpp"
#include <type_traits>
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
private:
//player or something
};
}
#endif