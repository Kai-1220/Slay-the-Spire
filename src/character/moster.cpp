#include "Monster.hpp"
Monster::Attack(std::shared_ptr<Character> target){
    target->TakeDamage(m_Damage);
}