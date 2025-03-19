#ifndef GAME_OBJECT_CARD_CARDS
#define GAME_OBJECT_CARD_CARDS
#include "RUtil/Atlas_Reader.hpp"
#include "Game_object/card/Card_image_box.hpp"
#include "Draw/Draw_2D.hpp"
#include "WindowSize.hpp"
#include "RUtil/Some_Math.hpp"
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
    Cards(Name card_name,Rarity rarity,Type type,Color color);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
private:
    float current_x,current_y,m_color_a,m_draw_scale,m_angle;
    std::shared_ptr<Draw::Atlas_Region> m_card_bg_silhouette,m_card_bg,m_card;
    void init_static_menber();
    void format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,const float x,const float y)const;
    static constexpr Uint32 FRAME_SHADOW_COLOR=0,DEFAULT_COLOR=RUtil::Math::GetColorUint32_RGB(255,255,255);
    static constexpr float SHADOW_OFFSET_X = 18.0F * Setting::SCALE,
                           SHADOW_OFFSET_Y = 14.0F * Setting::SCALE;
    static std::shared_ptr<Draw::Atlas_Region>s_card_attack_bg_silhouette,s_card_skill_bg_silhouette,s_card_power_bg_silhouette,s_card_attack_bg_red,s_card_attack_bg_green,s_card_attack_bg_blue,s_card_attack_bg_purple,s_card_attack_bg_gray,s_card_skill_bg_red,s_card_skill_bg_green,s_card_skill_bg_blue,s_card_skill_bg_purple,s_card_skill_bg_gray,s_card_skill_bg_black,s_card_power_bg_red,s_card_power_bg_green,s_card_power_bg_blue,s_card_power_bg_purple,s_card_power_bg_gray;
};
}
#endif