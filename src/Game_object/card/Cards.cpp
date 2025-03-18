#include "Game_object/card/Cards.hpp"
#include "Util/Logger.hpp"
namespace Card{
    Cards::Cards(Rarity rarity,Type type,Color color){
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