#include "Game_object/card/red/Strike_red.hpp"
namespace Card{
namespace Red{
    Strike_red::Strike_red():Cards(RUtil::AtlasRegionID::_red_attack_strike,Rarity::basic,Type::attack,Color::red,1){}
}
}