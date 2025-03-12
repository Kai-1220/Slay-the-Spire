#include "Draw/Text_layout.hpp"
#include "Util/Logger.hpp"
namespace Draw
{
    Text_layout::Text_layout(const std::string &text_string,int fontsize){
        //#y:yellow #g:green #r:red #b:blue #p:purple #n:new line
        //!D!:damage !B!:block !M!:vars
        //[R]:orb_red [G]:orb_green [B]:orb_blue [W]:orb_purple [C]:orb_card 
        //[P]:orb_potion [T]:orb_relic [S]:orb_special
        TTF_Font* m_font = TTF_OpenFont(s_lan_pos.c_str(), 64);
        
        TTF_CloseFont(m_font);
    }
    Text_layout::language Text_layout::s_language=Text_layout::language::zht;
    std::string Text_layout::s_lan_pos=RESOURCE_DIR"/font/zht/NotoSansCJKtc-Regular.otf";
    Text_layout::font_weight Text_layout::s_font_weight=Text_layout::font_weight::regular;
    std::shared_ptr<Draw::Image_Region> Text_layout::orb_red=nullptr,Text_layout::orb_blue=nullptr,
                                        Text_layout::orb_green=nullptr,Text_layout::orb_purple=nullptr,
                                        Text_layout::orb_card=nullptr,Text_layout::orb_potion=nullptr,
                                        Text_layout::orb_relic=nullptr,Text_layout::orb_special=nullptr;
    void Text_layout::SetLanguage(language lan){
        s_language=lan;
        pos_update();
    }
    void Text_layout::SetFontWeight(font_weight fw){
        s_font_weight=fw;
        pos_update();
    }
    void Text_layout::pos_update(){
        switch (s_language)
        {
        case language::eng:
            s_lan_pos=RESOURCE_DIR"/font/";
            break;
        case language::jpn:
            s_lan_pos=RESOURCE_DIR"/font/jpn/NotoSansCJKjp-";
            break;
        case language::zht:
            s_lan_pos=RESOURCE_DIR"/font/zht/NotoSansCJKtc-";
            break;
        default:
            LOG_ERROR("language ERROR");
            s_lan_pos=RESOURCE_DIR"/font/zht/NotoSansCJKtc-";
            break;
        }
        if(s_language==language::eng){
            switch (s_font_weight)
            {
            case font_weight::bold:
                s_lan_pos+="Kreon-Bold.ttf";
                break;
            case font_weight::medium:
                s_lan_pos+="ZillaSlab-RegularItalic.otf";
                break;
            case font_weight::regular:
                s_lan_pos+="Kreon-Regular.ttf";
                break;
            default:
                LOG_ERROR("Font_weight ERROR");
                s_lan_pos+="Kreon-Regular.ttf";
                break;
            }
        }else{
            switch (s_font_weight)
            {
            case font_weight::bold:
                s_lan_pos+="Bold.otf";
                break;
            case font_weight::medium:
                s_lan_pos+="Medium.otf";
                break;
            case font_weight::regular:
                s_lan_pos+="Regular.otf";
                break;
            default:
                LOG_ERROR("Font_weight ERROR");
                s_lan_pos+="Regular.otf";
                break;
            }
        }
    }

} // namespace Draw
