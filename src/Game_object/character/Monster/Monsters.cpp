#include "Game_object/character/Monster/Monsters.hpp"
namespace Monster
{
void Monsters::damage(int num){
    this->current_HP-=num;
}
} // namespace Monster
