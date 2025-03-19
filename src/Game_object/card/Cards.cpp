#include "Game_object/card/Cards.hpp"
#include "Util/Logger.hpp"
namespace Card{
    Cards::Cards(Name card_name,Rarity rarity,Type type,Color color){
        if(s_card_attack_bg_silhouette==nullptr){
            init_static_menber();
        }
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
                break;
        }
        
    }
    void Cards::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        // //if(){
            r2->SetColor(FRAME_SHADOW_COLOR,this->m_color_a/4.0F);
            this->format_render(r2, m_card_bg_silhouette, this->current_x + SHADOW_OFFSET_X * this->m_draw_scale, this->current_y - SHADOW_OFFSET_Y * this->m_draw_scale);
        //}
        r2->SetColor(DEFAULT_COLOR,this->m_color_a);
        this->format_render(r2,m_card_bg,this->current_x,this->current_y);
    //     this.renderPortraitFrame(sb, this.current_x, this.current_y);
    //   this.renderBannerImage(sb, this.current_x, this.current_y);
    }
    void Cards::format_render(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region> &img,float x,float y)const{
        r2->draw(img, x + img->GetOffsetX() - (float)img->GetOrigWidth() / 2.0F, y + img->GetOffsetY() - (float)img->GetOrigHeight() / 2.0F,(float)img->GetRegionWidth(), (float)img->GetOrigHeight(),this->m_angle, (float)img->GetOrigWidth() / 2.0F - img->GetOffsetX(), (float)img->GetRegionHeight() / 2.0F - img->GetOffsetY(), this->m_draw_scale * Setting::SCALE, this->m_draw_scale * Setting::SCALE);
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
    }
    std::shared_ptr<Draw::Atlas_Region>Cards::s_card_attack_bg_silhouette=nullptr,Cards::s_card_skill_bg_silhouette=nullptr,Cards::s_card_power_bg_silhouette=nullptr,Cards::s_card_attack_bg_red=nullptr,Cards::s_card_attack_bg_green=nullptr,Cards::s_card_attack_bg_blue=nullptr,Cards::s_card_attack_bg_purple=nullptr,Cards::s_card_attack_bg_gray=nullptr,Cards::s_card_skill_bg_red=nullptr,Cards::s_card_skill_bg_green=nullptr,Cards::s_card_skill_bg_blue=nullptr,Cards::s_card_skill_bg_purple=nullptr,Cards::s_card_skill_bg_gray=nullptr,Cards::s_card_skill_bg_black=nullptr,Cards::s_card_power_bg_red=nullptr,Cards::s_card_power_bg_green=nullptr,Cards::s_card_power_bg_blue=nullptr,Cards::s_card_power_bg_purple=nullptr,Cards::s_card_power_bg_gray;
}