#ifndef GAME_OBJECT_CHARACTER_PLAYER
#define GAME_OBJECT_CHARACTER_PLAYER
#include "Game_object/character/Characters.hpp"
namespace Character{
class Player:public Characters
{
public:
    Player()=default;
    virtual ~Player()=default;
    void damage(int num)override{this->current_HP-=num;};
private:

};
}
#endif