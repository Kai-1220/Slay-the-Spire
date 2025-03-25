#ifndef GAME_OBJECT_CARD_CARD_IMAGE_BOX
#define GAME_OBJECT_CARD_CARD_IMAGE_BOX
#include "RUtil/Atlas_Reader.hpp"
namespace Card{
enum class Name;
class Card_image_box
{
public:
    Card_image_box()=delete;~Card_image_box()=delete;Card_image_box(const Card_image_box &) = delete;Card_image_box(Card_image_box &&) = delete;Card_image_box &operator=(const Card_image_box &) = delete;Card_image_box &operator=(Card_image_box &&) = delete;
    static void InitIMGS();
    static std::shared_ptr<Draw::Atlas_Region> GetIMG(Name card_name);
private:
    static std::vector<std::shared_ptr<Draw::Atlas_Region>> BOX;
    template <typename ...Args>
    static void BOX_emplace(const Args&...args);
};
enum class Name{red_attack_anger,red_skill_armaments,red_power_barricade,red_attack_bash,red_skill_battle_trance,red_power_berserk,red_attack_blood_for_blood,red_skill_bloodletting,red_attack_bludgeon,red_attack_body_slam,red_power_brutality,red_skill_burning_pact,red_attack_carnage,red_attack_clash,red_attack_cleave,red_attack_clothesline,red_power_combust,red_power_corruption,red_power_dark_embrace,red_skill_defend,red_power_demon_form,red_skill_disarm,red_skill_double_tap,red_attack_drop_kick,red_skill_dual_wield,red_skill_entrench,red_power_evolve,red_skill_exhume,red_attack_feed,red_power_feel_no_pain,red_attack_fiend_fire,red_power_fire_breathing,red_skill_flame_barrier,red_skill_flex,red_skill_ghostly_armor,red_skill_havoc,red_attack_headbutt,red_attack_heavy_blade,red_attack_hemokinesis,red_attack_immolate,red_skill_impervious,red_skill_infernal_blade,red_power_inflame,red_skill_intimidate,red_attack_iron_wave,red_power_juggernaut,red_skill_limit_break,red_power_metallicize,red_skill_offering,red_attack_perfected_strike,red_attack_pommel_strike,red_skill_power_through,red_attack_pummel,red_skill_rage,red_attack_rampage,red_attack_reaper,red_attack_reckless_charge,red_power_rupture,red_attack_searing_blow,red_skill_second_wind,red_skill_seeing_red,red_skill_sentinel,red_attack_sever_soul,red_skill_shockwave,red_skill_shrug_it_off,red_skill_spot_weakness,red_attack_strike,red_attack_sword_boomerang,red_attack_thunder_clap,red_skill_true_grit,red_attack_twin_strike,red_attack_uppercut,red_skill_warcry,red_attack_whirlwind,red_attack_wild_strike};
}
#endif