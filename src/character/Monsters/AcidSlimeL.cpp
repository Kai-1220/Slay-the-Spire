#include "AcidSlimeL.h"
#include <iostream>
AcidSlimeL::AcidSlimeL(){
    m_Name = "Acid Slime L";
    m_HP = 100;
    m_Damage = 10;
    m_Action = AcidSlimeLAction::CorrosiveSpit;
}
AcidSlimeL::setAction(AcidSlimeLAction action){
    m_Action = action;
}
AcidSlimeL::getAction() const{
    return m_Action;
}
AcidSlimeL::RandomSetAction(){
    int action = rand() % 100;
    if(action)
}
