#include "Game_object/character/Monster/Monsters.hpp"
namespace Monster
{
void Monsters::damage(int num){
    this->current_HP-=num;
}
void Monsters::setHP(int min,int max){
    this->max_HP=max-int(RUtil::Random::GetRandomFloat(0.0F,max-min+1));
    this->current_HP=max_HP;
} // namespace Monster
void Monsters::setBlock(int num){
    this->current_Block=num;
}

} // namespace Monster