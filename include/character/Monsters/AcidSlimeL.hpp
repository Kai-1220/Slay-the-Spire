#ifndef AcidSlimeL_HPP
#define AcidSlimeL_HPP
#include "Monster.hpp"
#include <string>
#include <iostream>
enum class AcidSlimeLAction
{
    CorrosiveSpit,
    Lick,
    Tackle,
    Split
};

class AcidSlimeL : public Monster {
public:
    void setAction(AcidSlimeLAction action);
    void RandomSetAction();
    AcidSlimeLAction getAction() const;

private:
    AcidSlimeLAction m_Action;
    ={30,30,40};
};
#endif