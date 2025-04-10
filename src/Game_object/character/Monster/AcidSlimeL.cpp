#include "Game_object/character/Monster/AcidSlimeL.hpp"
#include "RUtil/Random.hpp"
Monster::AcidSlimeL::AcidSlimeL()
{
    max_HP=69-int(RUtil::Random::GetRandomFloat(0.0F,5.0F));
    current_HP=max_HP;
    current_Block=0;
    m_damage=16;
}

