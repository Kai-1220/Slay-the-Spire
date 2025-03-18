#ifndef GAME_OBJECT_CARD_CARDS
#define GAME_OBJECT_CARD_CARDS
#include "RUtil/Atlas_Reader.hpp"
namespace Card{
enum class Rarity{
    basic,
    special,
    common,
    uncommon,
    rare,
    curse
};
enum class Type{
    attack,
    skill,
    power,
    status,
    curse
};
enum class Color{
    red,
    green,
    blue,
    purple,
    colorless,
    curse
};
class Cards{
public:
    Cards(Rarity rarity,Type type,Color color);
    
private:
    std::shared_ptr<Draw::Atlas_Region> m_card_bg_silhouette,m_card_bg;
    void init_static_menber();
    static std::shared_ptr<Draw::Atlas_Region>s_card_attack_bg_silhouette,s_card_skill_bg_silhouette,s_card_power_bg_silhouette,s_card_attack_bg_red,s_card_attack_bg_green,s_card_attack_bg_blue,s_card_attack_bg_purple,s_card_attack_bg_gray,s_card_skill_bg_red,s_card_skill_bg_green,s_card_skill_bg_blue,s_card_skill_bg_purple,s_card_skill_bg_gray,s_card_skill_bg_black,s_card_power_bg_red,s_card_power_bg_green,s_card_power_bg_blue,s_card_power_bg_purple,s_card_power_bg_gray;
};
}
#endif