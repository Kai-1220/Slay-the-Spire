#ifndef GAME_OBJECT_CARD_CARDS
#define GAME_OBJECT_CARD_CARDS
#include "RUtil/Atlas_Reader.hpp"
#include "RUtil/All_Image.hpp"
#include "Draw/Draw_2D.hpp"
#include "RUtil/Text_Vector_Reader.hpp"

#include "RUtil/Some_Math.hpp"
#include "Game_object/card/Card_soul.hpp"
#include "Game_object/effect/Card_flash.hpp"
#include "RUtil/Hitbox.hpp"
#include "Game_object/effect/Effect_group.hpp"

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
enum class Target{
    enemy,
    all_enemy,
    self,
    self_and_enemy,
    all,
    none
};
//control render logic
//and normal move
class Cards:public Card_soul{
public:
    Cards(RUtil::AtlasRegionID card_name,Rarity rarity,Type type,Color color,Target target,int cost);
    virtual ~Cards() = default;
    Cards(const Cards& other)://ensure internal references are properly set when coping. //(m_card_flash)
        card_name(other.card_name),rarity(other.rarity),type(other.type),color(other.color),target(other.target),cost(other.cost),
        m_card_bg_silhouette(other.m_card_bg_silhouette),m_card_bg(other.m_card_bg),m_card_frame(other.m_card_frame),
        m_card_left_frame(other.m_card_left_frame),m_card_mid_frame(other.m_card_mid_frame),m_card_right_frame(other.m_card_right_frame),
        m_card_banner(other.m_card_banner),m_card_portrait(other.m_card_portrait),
        m_card_flash(other.m_card_bg_silhouette,this->current_x,this->current_y,this->m_angle,this->m_draw_scale,true),
        hb(IMG_WIDTH_S,IMG_HEIGHT_S)
    {
        this->SetFontTypeOffset();
        is_glowing=darken=false;
        m_dark_timer=m_glow_timer=m_hover_timer=0.0F;
        m_draw_scale=m_target_draw_scale=0.7F;
        m_tint_a=0.0F;
        m_color_a=1.0F;
    }
    Cards(Cards &&) = delete;
    Cards &operator=(const Cards &) = delete;
    Cards &operator=(Cards &&) = delete;

    void render(const std::shared_ptr<Draw::Draw_2D> &r2,const Uint32 PlayerColor_RGB)const;
    void render_hovered_shadow(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void update(Effect::Effect_group &effs,const Uint32 PlayerTrailColor_RGB);
    void update_hover_logic();
    void SetTargetAngle(const float value);
    void SetAngle(const float value);
    void SetTargetDrawScale(const float value);
    void SetDrawScale(const float value);
    void SetHoverTimer(const float value);//hover timer will be set when releasing card.
    void MoveTargetY(const float value);
    void MoveTargetX(const float value);
    void MoveTargetAngle(const float value);
    void Shrink(bool immediate);
    void Darken(bool immediate);
    void Lighten();
    void Hover();
    void Unhover();
    void start_glow();
    void stop_glow();
    void draw();
    void Flash(Uint32 _c);
    bool IsHoveredInHand(const float scale)const;

    bool CanUse()const noexcept{return true;}
    int GetCost()const noexcept{return cost;}
    float GetX()const noexcept{return current_x;}
    float GetY()const noexcept{return current_y;}
    void SetY(const float value,const bool immediate=false)noexcept{target_y=value;if(immediate)current_y=value;}
    void SetX(const float value,const bool immediate=false)noexcept{target_x=value;if(immediate)current_x=value;}
    bool IsSingleTarget()const noexcept{return target==Target::enemy||target==Target::self_and_enemy;}

    const RUtil::AtlasRegionID card_name;
    const Rarity rarity;
    const Type type;
    const Color color;
    const Target target;
private:
    static const float &DT;
    int m_text_pos,cost;
    bool darken,is_glowing;
    float m_color_a,m_draw_scale,m_angle,m_type_width,m_type_offset,m_tint_a,m_target_draw_scale,m_dark_timer,m_glow_timer,m_hover_timer;
    const std::shared_ptr<Draw::Atlas_Region> &m_card_bg_silhouette,&m_card_bg,&m_card_frame,&m_card_left_frame,&m_card_mid_frame,&m_card_right_frame,&m_card_banner,&m_card_portrait;
    Effect::Effect_group glowgroup;
    Effect::Card_flash m_card_flash;
    RUtil::Hitbox hb;

    void format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,const float x,const float y,const float scale=1.0F)const;
    void frame_format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,const float x_offset,const float x_scale)const;
    static void init_static_menber();
    void SetFontTypeOffset();
    static constexpr Uint32 FRAME_SHADOW_COLOR=0,DEFAULT_COLOR=RUtil::Math::GetColorUint32_RGB(255,255,255),TYPE_COLOR=RUtil::Math::GetColorUint32_RGB(0.35F,0.35F,0.35F),TINT_COLOR=RUtil::Math::GetColorUint32_RGB(43,37,65);
    static constexpr float  SHADOW_OFFSET_X = 18.0F * Setting::SCALE,
                            SHADOW_OFFSET_Y = 14.0F * Setting::SCALE,
                            CARD_SNAP_THRESHOLD = 1.0F * Setting::SCALE;
    static const std::vector<std::shared_ptr<Draw::Text_layout>> &s_ui_vec;
    static float s_type_offset_attack,s_type_offset_skill,s_type_offset_power,s_type_offset_status,s_type_offset_curse,s_type_width_attack,s_type_width_skill,s_type_width_power,s_type_width_status,s_type_width_curse;
    static constexpr int CARD_FONT_SIZE=17;
public:
    static constexpr float  IMG_WIDTH = 300.0F * Setting::SCALE,
                            IMG_HEIGHT = 420.0F * Setting::SCALE,
                            IMG_WIDTH_S = 300.0F * Setting::SCALE * 0.7F,
                            IMG_HEIGHT_S = 420.0F * Setting::SCALE * 0.7F;

};
inline bool operator<(Rarity lhs, Rarity rhs) {
    return static_cast<int>(lhs) < static_cast<int>(rhs);
}
inline bool operator<(Type lhs, Type rhs) {
    return static_cast<int>(lhs) < static_cast<int>(rhs);
}
}
#endif