#ifndef DRAW_TEXT_LAYOUT_HPP
#define DRAW_TEXT_LAYOUT_HPP
#include "pch.hpp"
#include "Util/Color.hpp"
#include "Draw/Atlas_Region.hpp"
namespace Draw{
class Text_layout
{
public:
    enum class language{
        eng,
        zht,
        jpn
    };
    enum class font_weight{
        regular,
        bold,
        medium
    };
    //#y:yellow #g:green #r:red #b:blue #p:purple #n:new line
    //!D!:damage !B!:block !M!:vars
    //[R]:orb_red [G]:orb_green [B]:orb_blue [W]:orb_purple [C]:orb_card 
    //[P]:orb_potion [T]:orb_relic [S]:orb_special
    Text_layout(const std::string &text_string,int fontsize);
    ~Text_layout()=default;
    static void SetLanguage(language lan);
    static void SetFontWeight(font_weight fw);
private:
    struct regs_info{
        float x,y,w,h;
        Uint32 c;
    };
    static void pos_update();
    static void init_orbs();
    static language s_language;
    static std::string s_lan_pos;
    static font_weight s_font_weight;
    static std::shared_ptr<Draw::Atlas_Region>orb_red,orb_green,orb_blue,orb_purple,orb_card,orb_potion,orb_relic,orb_special;
    static constexpr Uint32 GOLD_COLOR=-272084481,
                            RED_TEXT_COLOR = -10132481,
                            GREEN_TEXT_COLOR = 2147418367,
                            BLUE_TEXT_COLOR = -2016482305,
                            PURPLE_COLOR = -293409025,
                            WHITE=-1;
    std::vector<std::shared_ptr<Draw::Image_Region>> regs;
    std::vector<regs_info> m_regs_info;
    
};
}
#endif