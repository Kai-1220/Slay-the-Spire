#include "Game_object/card/Cards.hpp"
#include "Util/Logger.hpp"
namespace Card{
    Cards::Cards(Name card_name,Rarity rarity,Type type,Color color){
        if(s_card_attack_bg_silhouette==nullptr){
            init_static_menber();
        }
        //attack, power and other
        switch(type){
            case Type::attack:
                m_card_bg_silhouette=s_card_attack_bg_silhouette;
                switch(color){
                    case Color::red:
                        m_card_bg=s_card_attack_bg_red;
                        break;
                    case Color::green:
                        m_card_bg=s_card_attack_bg_green;
                        break;
                    case Color::blue:
                        m_card_bg=s_card_attack_bg_blue;
                        break;
                    case Color::purple:
                        m_card_bg=s_card_attack_bg_purple;
                        break;
                    case Color::colorless:
                        m_card_bg=s_card_attack_bg_gray;
                        break;
                    default:
                        m_card_bg=s_card_skill_bg_black;
                        break;
                }
                switch(rarity){
                    case Rarity::rare:
                        m_card_frame=s_card_frame_attack_rare;
                        break;
                    case Rarity::uncommon:
                        m_card_frame=s_card_frame_attack_uncommon;
                        break;
                    default:
                        m_card_frame=s_card_frame_attack_common;
                        break;
                }
                break;
            case Type::power:
                m_card_bg_silhouette=s_card_power_bg_silhouette;
                switch(color){
                    case Color::red:
                        m_card_bg=s_card_power_bg_red;
                        break;
                    case Color::green:
                        m_card_bg=s_card_power_bg_green;
                        break;
                    case Color::blue:
                        m_card_bg=s_card_power_bg_blue;
                        break;
                    case Color::purple:
                        m_card_bg=s_card_power_bg_purple;
                        break;
                    case Color::colorless:
                        m_card_bg=s_card_power_bg_gray;
                        break;
                    default:
                        m_card_bg=s_card_skill_bg_black;
                        break;
                }
                switch(rarity){
                    case Rarity::rare:
                        m_card_frame=s_card_frame_power_rare;
                        break;
                    case Rarity::uncommon:
                        m_card_frame=s_card_frame_power_uncommon;
                        break;
                    default:
                        m_card_frame=s_card_frame_power_common;
                        break;
                }
                break;
            default:
                m_card_bg_silhouette=s_card_skill_bg_silhouette;
                switch(color){
                    case Color::red:
                        m_card_bg=s_card_skill_bg_red;
                        break;
                    case Color::green:
                        m_card_bg=s_card_skill_bg_green;
                        break;
                    case Color::blue:
                        m_card_bg=s_card_skill_bg_blue;
                        break;
                    case Color::purple:
                        m_card_bg=s_card_skill_bg_purple;
                        break;
                    case Color::colorless:
                        m_card_bg=s_card_skill_bg_gray;
                        break;
                    default:
                        m_card_bg=s_card_skill_bg_black;
                        break;
                }
                switch(rarity){
                    case Rarity::rare:
                        m_card_frame=s_card_frame_skill_rare;
                        break;
                    case Rarity::uncommon:
                        m_card_frame=s_card_frame_skill_uncommon;
                        break;
                    default:
                        m_card_frame=s_card_frame_skill_common;
                        break;
                }
                break;
        }
        //all type
        switch(type){
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
        switch(rarity){
            case Rarity::rare:
                m_card_mid_frame=s_card_rare_frame_mid;
                m_card_left_frame=s_card_rare_frame_left;
                m_card_right_frame=s_card_rare_frame_right;
                m_card_banner=s_card_banner_rare;
                break;
            case Rarity::uncommon:
                m_card_mid_frame=s_card_uncommon_frame_mid;
                m_card_left_frame=s_card_uncommon_frame_left;
                m_card_right_frame=s_card_uncommon_frame_right;
                m_card_banner=s_card_banner_uncommon;
                break;
            default:
                m_card_mid_frame=s_card_common_frame_mid;
                m_card_left_frame=s_card_common_frame_left;
                m_card_right_frame=s_card_common_frame_right;
                m_card_banner=s_card_banner_common;
                break;
        }
        current_x=600;
        current_y=250;
        m_color_a=1.0F;
        m_draw_scale=2.0F;
        m_angle=60.0F;
    }
    void Cards::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        //image
        // //if(){
            r2->SetColor(FRAME_SHADOW_COLOR,this->m_color_a/4.0F);
            this->format_render(r2, m_card_bg_silhouette, this->current_x + SHADOW_OFFSET_X * this->m_draw_scale, this->current_y - SHADOW_OFFSET_Y * this->m_draw_scale);
        //}
        r2->SetColor(DEFAULT_COLOR,this->m_color_a);
        this->format_render(r2,m_card_bg,this->current_x,this->current_y);

        this->format_render(r2,m_card_frame,this->current_x,this->current_y);

        if(m_type_width>1.1F){//only need if text too long.
            this->frame_format_render(r2,m_card_mid_frame,0.0F,m_type_width);
            this->frame_format_render(r2,m_card_left_frame,-m_type_offset,1.0F);
            this->frame_format_render(r2,m_card_right_frame,m_type_offset,1.0F);
        }
        this->format_render(r2,m_card_banner,this->current_x,this->current_y);
        
        r2->SetColor(TYPE_COLOR,this->m_color_a);
        s_ui_vec->at(this->m_text_pos).render_without_format_word(r2,this->current_x,this->current_y-22.0F*this->m_draw_scale*Setting::SCALE,this->m_angle,this->m_draw_scale,0.0F,22.0F*this->m_draw_scale*Setting::SCALE);
    }
    void Cards::format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,float x,float y)const{
        r2->draw(img, x + img->GetOffsetX() - (float)img->GetOrigWidth() / 2.0F, y + img->GetOffsetY() - (float)img->GetOrigHeight() / 2.0F,(float)img->GetRegionWidth(), (float)img->GetRegionHeight(),this->m_angle, (float)img->GetOrigWidth() / 2.0F - img->GetOffsetX(), (float)img->GetOrigHeight() / 2.0F - img->GetOffsetY(), this->m_draw_scale * Setting::SCALE, this->m_draw_scale * Setting::SCALE);
    }
    void Cards::frame_format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,const float x_offset,const float x_scale)const{
        r2->draw(img, this->current_x + img->GetOffsetX() - (float)img->GetOrigWidth() / 2.0F + x_offset * this->m_draw_scale, this->current_y + img->GetOffsetY() - (float)img->GetOrigHeight() / 2.0F, (float)img->GetRegionWidth(), (float)img->GetRegionHeight(), this->m_angle, (float)img->GetOrigWidth() / 2.0F - img->GetOffsetX() - x_offset * this->m_draw_scale, (float)img->GetOrigHeight() / 2.0F - img->GetOffsetY(),  this->m_draw_scale * Setting::SCALE * x_scale, this->m_draw_scale * Setting::SCALE);
    }
    void Cards::init_static_menber(){
        RUtil::Atlas_Reader temp(RESOURCE_DIR"/Image/cardui/cardui.atlas");
        s_card_attack_bg_silhouette=temp.Find_Atlas_Region("512/bg_attack_silhouette");
        s_card_skill_bg_silhouette=temp.Find_Atlas_Region("512/bg_skill_silhouette");
        s_card_power_bg_silhouette=temp.Find_Atlas_Region("512/bg_power_silhouette");
        s_card_attack_bg_red=temp.Find_Atlas_Region("512/bg_attack_red");
        s_card_attack_bg_green=temp.Find_Atlas_Region("512/bg_attack_green");
        s_card_attack_bg_blue=temp.Find_Atlas_Region("512/bg_attack_blue");
        s_card_attack_bg_purple=temp.Find_Atlas_Region("512/bg_attack_purple");
        s_card_attack_bg_gray=temp.Find_Atlas_Region("512/bg_attack_gray");
        s_card_skill_bg_red=temp.Find_Atlas_Region("512/bg_skill_red");
        s_card_skill_bg_green=temp.Find_Atlas_Region("512/bg_skill_green");
        s_card_skill_bg_blue=temp.Find_Atlas_Region("512/bg_skill_blue");
        s_card_skill_bg_purple=temp.Find_Atlas_Region("512/bg_skill_purple");
        s_card_skill_bg_gray=temp.Find_Atlas_Region("512/bg_skill_gray");
        s_card_skill_bg_black=temp.Find_Atlas_Region("512/bg_skill_black");
        s_card_power_bg_red=temp.Find_Atlas_Region("512/bg_power_red");
        s_card_power_bg_green=temp.Find_Atlas_Region("512/bg_power_green");
        s_card_power_bg_blue=temp.Find_Atlas_Region("512/bg_power_blue");
        s_card_power_bg_purple=temp.Find_Atlas_Region("512/bg_power_purple");
        s_card_power_bg_gray=temp.Find_Atlas_Region("512/bg_power_gray"); 
        s_card_frame_attack_common = temp.Find_Atlas_Region("512/frame_attack_common");
        s_card_frame_attack_uncommon = temp.Find_Atlas_Region("512/frame_attack_uncommon");
        s_card_frame_attack_rare = temp.Find_Atlas_Region("512/frame_attack_rare");
        s_card_frame_skill_common = temp.Find_Atlas_Region("512/frame_skill_common");
        s_card_frame_skill_uncommon = temp.Find_Atlas_Region("512/frame_skill_uncommon");
        s_card_frame_skill_rare = temp.Find_Atlas_Region("512/frame_skill_rare");
        s_card_frame_power_common = temp.Find_Atlas_Region("512/frame_power_common");
        s_card_frame_power_uncommon = temp.Find_Atlas_Region("512/frame_power_uncommon");
        s_card_frame_power_rare = temp.Find_Atlas_Region("512/frame_power_rare");
        s_card_common_frame_left = temp.Find_Atlas_Region("512/common_left");
        s_card_common_frame_mid = temp.Find_Atlas_Region("512/common_center");
        s_card_common_frame_right = temp.Find_Atlas_Region("512/common_right");
        s_card_uncommon_frame_left = temp.Find_Atlas_Region("512/uncommon_left");
        s_card_uncommon_frame_mid = temp.Find_Atlas_Region("512/uncommon_center");
        s_card_uncommon_frame_right = temp.Find_Atlas_Region("512/uncommon_right");
        s_card_rare_frame_left = temp.Find_Atlas_Region("512/rare_left");
        s_card_rare_frame_mid = temp.Find_Atlas_Region("512/rare_center");
        s_card_rare_frame_right = temp.Find_Atlas_Region("512/rare_right");
        s_card_banner_common = temp.Find_Atlas_Region("512/banner_common");
        s_card_banner_uncommon = temp.Find_Atlas_Region("512/banner_uncommon");
        s_card_banner_rare = temp.Find_Atlas_Region("512/banner_rare");
        s_ui_vec=RUtil::Text_Vector_Reader::GetTextVector(RUtil::Text_ID::SingleCardViewPopup);
        s_ui_vec->at(0).set_fontsize(CARD_FONT_SIZE);
        const float padding=10.0F*Setting::SCALE;
        float jitai_width=s_ui_vec->at(0).GetWidth()+padding;
        constexpr float mid_frame_width=48.0F*Setting::SCALE;
        s_type_offset_attack=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_attack=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;//let the space have twice as large
        s_ui_vec->at(1).set_fontsize(CARD_FONT_SIZE);
        jitai_width=s_ui_vec->at(1).GetWidth()+padding;
        s_type_offset_skill=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_skill=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;
        s_ui_vec->at(2).set_fontsize(CARD_FONT_SIZE);
        jitai_width=s_ui_vec->at(2).GetWidth()+padding;
        s_type_offset_power=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_power=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;
        s_ui_vec->at(3).set_fontsize(CARD_FONT_SIZE);
        jitai_width=s_ui_vec->at(3).GetWidth()+padding;
        s_type_offset_curse=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_curse=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;
        s_ui_vec->at(7).set_fontsize(CARD_FONT_SIZE);
        jitai_width=s_ui_vec->at(7).GetWidth()+padding;
        s_type_offset_status=(jitai_width-mid_frame_width)/2.0F;
        s_type_width_status=(jitai_width/mid_frame_width-1.0F)*2.0F+1.0F;
    }
    std::shared_ptr<Draw::Atlas_Region>Cards::s_card_attack_bg_silhouette=nullptr,Cards::s_card_skill_bg_silhouette=nullptr,Cards::s_card_power_bg_silhouette=nullptr,Cards::s_card_attack_bg_red=nullptr,Cards::s_card_attack_bg_green=nullptr,Cards::s_card_attack_bg_blue=nullptr,Cards::s_card_attack_bg_purple=nullptr,Cards::s_card_attack_bg_gray=nullptr,Cards::s_card_skill_bg_red=nullptr,Cards::s_card_skill_bg_green=nullptr,Cards::s_card_skill_bg_blue=nullptr,Cards::s_card_skill_bg_purple=nullptr,Cards::s_card_skill_bg_gray=nullptr,Cards::s_card_skill_bg_black=nullptr,Cards::s_card_power_bg_red=nullptr,Cards::s_card_power_bg_green=nullptr,Cards::s_card_power_bg_blue=nullptr,Cards::s_card_power_bg_purple=nullptr,Cards::s_card_power_bg_gray=nullptr,Cards::s_card_frame_attack_common=nullptr,Cards::s_card_frame_attack_uncommon=nullptr,Cards::s_card_frame_attack_rare=nullptr,Cards::s_card_frame_skill_common=nullptr,Cards::s_card_frame_skill_uncommon=nullptr,Cards::s_card_frame_skill_rare=nullptr,Cards::s_card_frame_power_common=nullptr,Cards::s_card_frame_power_uncommon=nullptr,Cards::s_card_frame_power_rare=nullptr,Cards::s_card_common_frame_left=nullptr,Cards::s_card_common_frame_mid=nullptr,Cards::s_card_common_frame_right=nullptr,Cards::s_card_uncommon_frame_left=nullptr,Cards::s_card_uncommon_frame_mid=nullptr,Cards::s_card_uncommon_frame_right=nullptr,Cards::s_card_rare_frame_left=nullptr,Cards::s_card_rare_frame_mid=nullptr,Cards::s_card_rare_frame_right=nullptr,Cards::s_card_banner_common=nullptr,Cards::s_card_banner_uncommon=nullptr,Cards::s_card_banner_rare=nullptr;
    std::shared_ptr<std::vector<Draw::Text_layout>> Cards::s_ui_vec=nullptr;
    float Cards::s_type_offset_attack=0.0F,Cards::s_type_offset_skill=0.0F,Cards::s_type_offset_power=0.0F,Cards::s_type_offset_status=0.0F,Cards::s_type_offset_curse=0.0F,Cards::s_type_width_attack=0.0F,Cards::s_type_width_skill=0.0F,Cards::s_type_width_power=0.0F,Cards::s_type_width_status=0.0F,Cards::s_type_width_curse=0.0F;
}