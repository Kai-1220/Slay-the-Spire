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
enum class Name{anger,armaments,barricade,bash,battle_trance,berserk,blood_for_blood,bloodletting,bludgeon,body_slam,brutality,burning_pact,carnage,clash,cleave,clothesline,combust,corruption,dark_embrace,defend,demon_form,disarm,double_tap,drop_kick,dual_wield,entrench,evolve,exhume,feed,feel_no_pain,fiend_fire,fire_breathing,flame_barrier,flex,ghostly_armor,havoc,headbutt,heavy_blade,hemokinesis,immolate,impervious,infernal_blade,inflame,intimidate,iron_wave,juggernaut,limit_break,metallicize,offering,perfected_strike,pommel_strike,power_through,pummel,rage,rampage,reaper,reckless_charge,rupture,searing_blow,second_wind,seeing_red,sentinel,sever_soul,shockwave,shrug_it_off,spot_weakness,strike,sword_boomerang,thunder_clap,true_grit,twin_strike,uppercut,warcry,whirlwind,wild_strike};
}
#endif