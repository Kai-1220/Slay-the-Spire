#ifndef GAME_OBJECT_CARD_CARDS
#define GAME_OBJECT_CARD_CARDS
#include "RUtil/Atlas_Reader.hpp"
#include "Game_object/card/Card_image_box.hpp"
#include "Draw/Draw_2D.hpp"
#include "RUtil/Some_Math.hpp"
#include "RUtil/Text_Vector_Reader.hpp"
#include "Game_object/card/Card_soul.hpp"
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
//control render logic
class Cards:public Card_soul{
public:
    Cards(Name card_name,Rarity rarity,Type type,Color color);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    virtual ~Cards()=default;
private:
    int m_text_pos;
    float m_color_a,m_draw_scale,m_angle,m_type_width,m_type_offset,m_tint_a;
    std::shared_ptr<Draw::Atlas_Region> m_card_bg_silhouette,m_card_bg,m_card,m_card_frame,m_card_left_frame,m_card_mid_frame,m_card_right_frame,m_card_banner;
    void init_static_menber();
    void format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,const float x,const float y)const;
    void frame_format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,const float x_offset,const float x_scale)const;
    static constexpr Uint32 FRAME_SHADOW_COLOR=0,DEFAULT_COLOR=RUtil::Math::GetColorUint32_RGB(255,255,255),TYPE_COLOR=RUtil::Math::GetColorUint32_RGB(0.35F,0.35F,0.35F),TINT_COLOR=RUtil::Math::GetColorUint32_RGB(43,37,65);
    static constexpr float SHADOW_OFFSET_X = 18.0F * Setting::SCALE,
                           SHADOW_OFFSET_Y = 14.0F * Setting::SCALE;
    static std::shared_ptr<Draw::Atlas_Region>s_card_attack_bg_silhouette,s_card_skill_bg_silhouette,s_card_power_bg_silhouette,s_card_attack_bg_red,s_card_attack_bg_green,s_card_attack_bg_blue,s_card_attack_bg_purple,s_card_attack_bg_gray,s_card_skill_bg_red,s_card_skill_bg_green,s_card_skill_bg_blue,s_card_skill_bg_purple,s_card_skill_bg_gray,s_card_skill_bg_black,s_card_power_bg_red,s_card_power_bg_green,s_card_power_bg_blue,s_card_power_bg_purple,s_card_power_bg_gray,s_card_frame_attack_common,s_card_frame_attack_uncommon,s_card_frame_attack_rare,s_card_frame_skill_common,s_card_frame_skill_uncommon,s_card_frame_skill_rare,s_card_frame_power_common,s_card_frame_power_uncommon,s_card_frame_power_rare,s_card_common_frame_left,s_card_common_frame_mid,s_card_common_frame_right,s_card_uncommon_frame_left,s_card_uncommon_frame_mid,s_card_uncommon_frame_right,s_card_rare_frame_left,s_card_rare_frame_mid,s_card_rare_frame_right,s_card_banner_common,s_card_banner_uncommon,s_card_banner_rare;
    static std::shared_ptr<std::vector<Draw::Text_layout>> s_ui_vec;
    static float s_type_offset_attack,s_type_offset_skill,s_type_offset_power,s_type_offset_status,s_type_offset_curse,s_type_width_attack,s_type_width_skill,s_type_width_power,s_type_width_status,s_type_width_curse;
    static constexpr int CARD_FONT_SIZE=17;
};
}
#endif