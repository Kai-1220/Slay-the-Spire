#include "Game_object/card/Card_image_box.hpp"

namespace Card{
std::shared_ptr<Draw::Atlas_Region> Card_image_box::GetIMG(Name card_name){
    return BOX[static_cast<int>(card_name)];
}
void Card_image_box::InitIMGS(){
    BOX_emplace("red/attack/anger","red/skill/armaments","red/power/barricade","red/attack/bash","red/skill/battle_trance","red/power/berserk","red/attack/blood_for_blood","red/skill/bloodletting","red/attack/bludgeon","red/attack/body_slam","red/power/brutality","red/skill/burning_pact","red/attack/carnage","red/attack/clash","red/attack/cleave","red/attack/clothesline","red/power/combust","red/power/corruption","red/power/dark_embrace","red/skill/defend","red/power/demon_form","red/skill/disarm","red/skill/double_tap","red/attack/drop_kick","red/skill/dual_wield","red/skill/entrench","red/power/evolve","red/skill/exhume","red/attack/feed","red/power/feel_no_pain","red/attack/fiend_fire","red/power/fire_breathing","red/skill/flame_barrier","red/skill/flex","red/skill/ghostly_armor","red/skill/havoc","red/attack/headbutt","red/attack/heavy_blade","red/attack/hemokinesis","red/attack/immolate","red/skill/impervious","red/skill/infernal_blade","red/power/inflame","red/skill/intimidate","red/attack/iron_wave","red/power/juggernaut","red/skill/limit_break","red/power/metallicize","red/skill/offering","red/attack/perfected_strike","red/attack/pommel_strike","red/skill/power_through","red/attack/pummel","red/skill/rage","red/attack/rampage","red/attack/reaper","red/attack/reckless_charge","red/power/rupture","red/attack/searing_blow","red/skill/second_wind","red/skill/seeing_red","red/skill/sentinel","red/attack/sever_soul","red/skill/shockwave","red/skill/shrug_it_off","red/skill/spot_weakness","red/attack/strike","red/attack/sword_boomerang","red/attack/thunder_clap","red/skill/true_grit","red/attack/twin_strike","red/attack/uppercut","red/skill/warcry","red/attack/whirlwind","red/attack/wild_strike");
}
template <typename ...Args>
void Card_image_box::BOX_emplace(const Args&...args){
    RUtil::Atlas_Reader temp(RESOURCE_DIR"/Image/cards/cards.atlas");
    (BOX.emplace_back(temp.Find_Atlas_Region(args)),...);
}
std::vector<std::shared_ptr<Draw::Atlas_Region>> Card_image_box::BOX;
}