#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "character.hpp"
#include <string>
#include <iostream>


class Monster : public Character {
public:
    void Attack(std::shared_ptr<Character> target);

private:
    unsigned int m_Damage;
    std::string m_Name;
    int ActionProbability;
};
#endif