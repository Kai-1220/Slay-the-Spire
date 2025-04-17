#include "Game_object/card/Cards.hpp"
#include "RUtil/Game_Input.hpp"
#include "RUtil/All_Image.hpp"
#include "Game_object/effect/Card_glow_border.hpp"

#include "Util/Logger.hpp"

namespace Card{
    static const std::shared_ptr<Draw::Atlas_Region> &BgSilhouette(Type type);
    static const std::shared_ptr<Draw::Atlas_Region> &CardBg(Type type,Color color);
    static const std::shared_ptr<Draw::Atlas_Region> &CardFrame(Type type,Rarity rarity);
    static const std::shared_ptr<Draw::Atlas_Region> &CardLeftFrame(Rarity rarity);
    static const std::shared_ptr<Draw::Atlas_Region> &CardMidFrame(Rarity rarity);
    static const std::shared_ptr<Draw::Atlas_Region> &CardRightFrame(Rarity rarity);
    static const std::shared_ptr<Draw::Atlas_Region> &CardBanner(Rarity rarity);
    
    Cards::Cards(RUtil::AtlasRegionID card_name,Rarity rarity,Type type,Color color,Target target,int cost):
                        card_name(card_name),rarity(rarity),type(type),color(color),target(target),cost(cost),
                        m_card_bg_silhouette(BgSilhouette(type)),m_card_bg(CardBg(type,color)),m_card_frame(CardFrame(type,rarity)),
                        m_card_left_frame(CardLeftFrame(rarity)),m_card_mid_frame(CardMidFrame(rarity)),m_card_right_frame(CardRightFrame(rarity)),
                        m_card_banner(CardBanner(rarity)),m_card_portrait(RUtil::All_Image::GetAtlasRegion(card_name)),
                        m_card_flash(m_card_bg_silhouette,this->current_x,this->current_y,this->m_angle,this->m_draw_scale,true),
                        hb(IMG_WIDTH_S,IMG_HEIGHT_S)
    {
        static bool once=false;
        if(!once){
            init_static_menber();
        }
        this->SetFontTypeOffset();
        
        is_glowing=darken=false;
        m_dark_timer=m_glow_timer=m_hover_timer=0.0F;
        m_draw_scale=m_target_draw_scale=0.7F;
        m_tint_a=0.0F;
        m_color_a=1.0F;
        
        //x,y,angle not set
    }
    
    void Cards::update(Effect::Effect_group &effs,const Uint32 PlayerTrailColor_RGB){
        //flash update
        if(!m_card_flash.IsDone()) m_card_flash.update();
        //hover time update
        if(m_hover_timer!=0.0F)
            m_hover_timer=m_hover_timer<DT?0.0F:m_hover_timer-DT;

        this->update_flying(effs,PlayerTrailColor_RGB);
        if(!this->is_flying){
            current_x=RUtil::Math::varlerp(current_x,target_x,6.0F,CARD_SNAP_THRESHOLD);
            current_y=RUtil::Math::varlerp(current_y,target_y,6.0F,CARD_SNAP_THRESHOLD);
        }
        //angle
        if(this->m_angle!=this->target_angle){
            this->m_angle=RUtil::Math::varlerp(this->m_angle,target_angle,12.0F,0.003F);
        }
        //scale
        this->hb.move(this->current_x,this->current_y);
        this->hb.resize(IMG_WIDTH*this->m_draw_scale, IMG_HEIGHT*this->m_draw_scale);
        if(hb.ClickStarted()){
            this->m_draw_scale=RUtil::Math::varlerp(this->m_draw_scale, this->m_target_draw_scale*0.9F, 7.5F, 0.003F);
            this->m_draw_scale=RUtil::Math::varlerp(this->m_draw_scale, this->m_target_draw_scale*0.9F, 7.5F, 0.003F);
        }else{
            this->m_draw_scale=RUtil::Math::varlerp(this->m_draw_scale, this->m_target_draw_scale, 7.5F, 0.003F);
        }

        //color
        if(m_dark_timer!=0.0F){
            m_dark_timer-=DT;
            if(m_dark_timer<0.0F)m_dark_timer=0.0F;
            m_tint_a=darken?(1-m_dark_timer/0.3F):m_dark_timer/0.3F;
        }
        //glow
        if(is_glowing){
            m_glow_timer-=DT;
            if(m_glow_timer<0.0F){
                glowgroup.AddTop(std::make_shared<Effect::Card_glow_border>(m_card_bg_silhouette,this->current_x,this->current_y,this->m_angle,this->m_draw_scale));
                m_glow_timer=0.3F;
            }
        }
        glowgroup.update();
    }

    void Cards::render(const std::shared_ptr<Draw::Draw_2D> &r2,const Uint32 PlayerColor_RGB)const{
        if(is_shuffling&&shuffle_invisible) return;
        if(is_shuffling){
            r2->SetColor(PlayerColor_RGB,1.0F);
            format_render(r2,m_card_bg_silhouette,this->current_x,this->current_y,1.0F+this->m_tint_a/5.0F);
        }
        //flash
        if(!m_card_flash.IsDone()){
            m_card_flash.render(r2);
            r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        }
        //glow
        if(static_cast<int>(glowgroup.size())!=0)
            glowgroup.render(r2);
        //image
        //shadow
        r2->SetColor(FRAME_SHADOW_COLOR,this->m_color_a/4.0F);
        this->format_render(r2, m_card_bg_silhouette, this->current_x + SHADOW_OFFSET_X * this->m_draw_scale, this->current_y - SHADOW_OFFSET_Y * this->m_draw_scale);
        //bg
        r2->SetColor(DEFAULT_COLOR,this->m_color_a);
        this->format_render(r2,m_card_bg,this->current_x,this->current_y);
        //portrait
        const float p_rw=(float)m_card_portrait->GetRegionWidth(),
                    p_rh=(float)m_card_portrait->GetRegionHeight();
        r2->draw(m_card_portrait, this->current_x-p_rw/2.0F, this->current_y-p_rh/2.0F+72.0F, p_rw, p_rh, this->m_angle, p_rw/2.0F, p_rh/2.0F-72.0F, this->m_draw_scale*Setting::SCALE, this->m_draw_scale*Setting::SCALE);
        //frame
        this->format_render(r2,m_card_frame,this->current_x,this->current_y);
        if(m_type_width>1.1F){//only need if text too long.
            this->frame_format_render(r2,m_card_mid_frame,0.0F,m_type_width);
            this->frame_format_render(r2,m_card_left_frame,-m_type_offset,1.0F);
            this->frame_format_render(r2,m_card_right_frame,m_type_offset,1.0F);
        }
        //banner
        this->format_render(r2,m_card_banner,this->current_x,this->current_y);

        //type
        r2->SetColor(TYPE_COLOR,this->m_color_a);
        s_ui_vec[this->m_text_pos]->render_without_format_word(r2,this->current_x,this->current_y-22.0F*this->m_draw_scale*Setting::SCALE,this->m_angle,this->m_draw_scale,0.0F,22.0F*this->m_draw_scale*Setting::SCALE);
    
        //tint
        r2->SetColor(TINT_COLOR,this->m_tint_a);
        this->format_render(r2, m_card_bg_silhouette, this->current_x, this->current_y);
    }
    void Cards::format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,float x,float y,float scale)const{
        r2->draw(img, x + img->offsetX - (float)img->original_width / 2.0F, y + img->offsetY - (float)img->original_height / 2.0F,(float)img->GetRegionWidth(), (float)img->GetRegionHeight(),this->m_angle, (float)img->original_width / 2.0F - img->offsetX, (float)img->original_height / 2.0F - img->offsetY, this->m_draw_scale * Setting::SCALE*scale, this->m_draw_scale * Setting::SCALE*scale);
    }
    void Cards::frame_format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,const float x_offset,const float x_scale)const{
        r2->draw(img, this->current_x + img->offsetX - (float)img->original_width / 2.0F + x_offset * this->m_draw_scale, this->current_y + img->offsetY - (float)img->original_height / 2.0F, (float)img->GetRegionWidth(), (float)img->GetRegionHeight(), this->m_angle, (float)img->original_width / 2.0F - img->offsetX - x_offset * this->m_draw_scale, (float)img->original_height / 2.0F - img->offsetY,  this->m_draw_scale * Setting::SCALE * x_scale, this->m_draw_scale * Setting::SCALE);
    }
    void Cards::Shrink(bool immediate){
        m_target_draw_scale=0.12F;
        if(immediate) m_draw_scale=0.12F;
    }
    void Cards::Darken(bool immediate){
        darken=true;
        if(immediate){
            m_tint_a=1.0F;
            m_dark_timer=0.0F;
        }else{
            m_dark_timer=0.3F;
        }
    };
    void Cards::Lighten(){
        darken=false;
        m_dark_timer=0.3F;
    }
    void Cards::Hover(){
        m_draw_scale=1.0F;
        m_target_draw_scale=1.0F;
    }
    void Cards::Unhover(){
        m_target_draw_scale=0.75F;
    }
    void Cards::start_glow(){
        is_glowing=true;
    }
    void Cards::stop_glow(){
        is_glowing=false;
        for(const auto&it:glowgroup)it->QuickDisappear(5.0F);
    }
    void Cards::Flash(Uint32 _c){
        m_card_flash.change_color(_c);
    }
    void Cards::SetTargetAngle(const float value){target_angle=value;}
    void Cards::SetAngle(const float value){m_angle=value;}
    void Cards::SetTargetDrawScale(const float value){m_target_draw_scale=value;}
    void Cards::SetDrawScale(const float value){m_draw_scale=value;}
    void Cards::SetHoverTimer(const float value){m_hover_timer=value;}
    void Cards::MoveTargetY(const float value){target_y+=value;}
    void Cards::MoveTargetX(const float value){target_x+=value;}
    void Cards::MoveTargetAngle(const float value){target_angle+=value;}
    bool Cards::IsHoveredInHand(const float scale)const{
        //The hover detection area here will be larger than the card's hitbox if scale>m_draw_scale,
        //will be smaller if scale<m_draw_scale
        if(m_hover_timer>0.0F) return false;
        const float x=(float)RUtil::Game_Input::getX(),y=(float)RUtil::Game_Input::getY(),
                    hw=IMG_WIDTH*scale/2.0F,hh=IMG_HEIGHT*scale/2.0F;
        return current_x-hw<x && x<current_x+hw && current_y-hh<y && y<current_y+hh;
    }
    void Cards::draw(){
        current_x=Card_soul::DRAW_PILE_X;
        current_y=Card_soul::DRAW_PILE_Y;
        m_angle=target_angle=0.0F;
        Lighten();
        m_draw_scale=0.12F;
        m_target_draw_scale=0.75F;
    }
    void Cards::render_hovered_shadow(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetColor(0,0.66F);
        this->format_render(r2,RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::_512_card_super_shadow),this->current_x,this->current_y,1.15F);
    }
    void Cards::init_static_menber(){
        s_ui_vec[0]->set_fontsize(CARD_FONT_SIZE);
        constexpr float padding=10.0F*Setting::SCALE;
        float jitai_width=s_ui_vec[0]->GetWidth()+padding;
        constexpr float mid_frame_width=48.0F*Setting::SCALE;
        s_type_offset_attack=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_attack=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;//let the space have twice as large
        s_ui_vec[1]->set_fontsize(CARD_FONT_SIZE);
        jitai_width=s_ui_vec[1]->GetWidth()+padding;
        s_type_offset_skill=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_skill=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;
        s_ui_vec[2]->set_fontsize(CARD_FONT_SIZE);
        jitai_width=s_ui_vec[2]->GetWidth()+padding;
        s_type_offset_power=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_power=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;
        s_ui_vec[3]->set_fontsize(CARD_FONT_SIZE);
        jitai_width=s_ui_vec[3]->GetWidth()+padding;
        s_type_offset_curse=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_curse=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;
        s_ui_vec[7]->set_fontsize(CARD_FONT_SIZE);
        jitai_width=s_ui_vec[7]->GetWidth()+padding;
        s_type_offset_status=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_status=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;
    }
    
    void Cards::SetFontTypeOffset(){
        switch(this->type){
            case Type::attack:
                m_type_offset=s_type_offset_attack;
                m_type_width=s_type_width_attack;
                m_text_pos=0;
                break;
            case Type::skill:
                m_type_offset=s_type_offset_skill;
                m_type_width=s_type_width_skill;
                m_text_pos=1;
                break;
            case Type::power:
                m_type_offset=s_type_offset_power;
                m_type_width=s_type_width_power;
                m_text_pos=2;
                break;
            case Type::curse:
                m_type_offset=s_type_offset_curse;
                m_type_width=s_type_width_curse;
                m_text_pos=3;
                break;
            case Type::status:
                m_type_offset=s_type_offset_status;
                m_type_width=s_type_width_status;
                m_text_pos=7;
                break;
            default:
                LOG_ERROR("The type doesn't exist");
                break;
        }
    }

    const std::vector<std::shared_ptr<Draw::Text_layout>> &Cards::s_ui_vec=RUtil::Text_Vector_Reader::GetTextVector(RUtil::Text_ID::SingleCardViewPopup);
    float Cards::s_type_offset_attack=0.0F,Cards::s_type_offset_skill=0.0F,Cards::s_type_offset_power=0.0F,Cards::s_type_offset_status=0.0F,Cards::s_type_offset_curse=0.0F,Cards::s_type_width_attack=0.0F,Cards::s_type_width_skill=0.0F,Cards::s_type_width_power=0.0F,Cards::s_type_width_status=0.0F,Cards::s_type_width_curse=0.0F;
    const float &Cards::DT=RUtil::Game_Input::delta_time();

    using namespace RUtil;
    static const std::shared_ptr<Draw::Atlas_Region> &BgSilhouette(Type type){
        switch(type){
            case Type::attack: return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_attack_silhouette);
            case Type::power: return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_power_silhouette);
            default: return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_silhouette);
        }   
    }
    static const std::shared_ptr<Draw::Atlas_Region> &CardBg(Type type,Color color){
        switch(type){
            case Type::attack:
                switch(color){
                    case Color::red:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_attack_red);
                    case Color::green:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_attack_green);
                    case Color::blue:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_attack_blue);
                    case Color::purple:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_attack_purple);
                    case Color::colorless:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_attack_gray);
                    default:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_black);
                }
            case Type::power:
                switch(color){
                    case Color::red:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_power_red);
                    case Color::green:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_power_green);
                    case Color::blue:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_power_blue);
                    case Color::purple:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_power_purple);
                    case Color::colorless:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_power_gray);
                    default:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_black);
                }
            default:
                switch(color){
                    case Color::red:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_red);
                    case Color::green:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_green);
                    case Color::blue:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_blue);
                    case Color::purple:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_purple);
                    case Color::colorless:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_gray);
                    default:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_bg_skill_black);
                }
        }   
    }
    static const std::shared_ptr<Draw::Atlas_Region> &CardFrame(Type type,Rarity rarity){
        switch(type){
            case Type::attack:
                switch(rarity){
                    case Rarity::rare:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_attack_rare);
                    case Rarity::uncommon:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_attack_uncommon);
                    default:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_attack_common);
                }
            case Type::power:
                switch(rarity){
                    case Rarity::rare:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_power_rare);
                    case Rarity::uncommon:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_power_uncommon);
                    default:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_power_common);
                }
            default:
                switch(rarity){
                    case Rarity::rare:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_skill_rare);
                    case Rarity::uncommon:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_skill_uncommon);
                    default:
                        return All_Image::GetAtlasRegion(AtlasRegionID::_512_frame_skill_common);
                }
        }   
    }
    static const std::shared_ptr<Draw::Atlas_Region> &CardLeftFrame(Rarity rarity){
        switch(rarity){
            case Rarity::rare: return All_Image::GetAtlasRegion(AtlasRegionID::_512_rare_left);
            case Rarity::uncommon: return All_Image::GetAtlasRegion(AtlasRegionID::_512_uncommon_left);
            default: return All_Image::GetAtlasRegion(AtlasRegionID::_512_common_left);
        }
    }
    static const std::shared_ptr<Draw::Atlas_Region> &CardMidFrame(Rarity rarity){
        switch(rarity){
            case Rarity::rare: return All_Image::GetAtlasRegion(AtlasRegionID::_512_rare_center);
            case Rarity::uncommon: return All_Image::GetAtlasRegion(AtlasRegionID::_512_uncommon_center);
            default: return All_Image::GetAtlasRegion(AtlasRegionID::_512_common_center);
        }
    }
    static const std::shared_ptr<Draw::Atlas_Region> &CardRightFrame(Rarity rarity){
        switch(rarity){
            case Rarity::rare: return All_Image::GetAtlasRegion(AtlasRegionID::_512_rare_right);
            case Rarity::uncommon: return All_Image::GetAtlasRegion(AtlasRegionID::_512_uncommon_right);
            default: return All_Image::GetAtlasRegion(AtlasRegionID::_512_common_right);
        }
    }
    static const std::shared_ptr<Draw::Atlas_Region> &CardBanner(Rarity rarity){
        switch(rarity){
            case Rarity::rare: return All_Image::GetAtlasRegion(AtlasRegionID::_512_banner_rare);
            case Rarity::uncommon: return All_Image::GetAtlasRegion(AtlasRegionID::_512_banner_uncommon);
            default: return All_Image::GetAtlasRegion(AtlasRegionID::_512_banner_common);
        }
    }
}