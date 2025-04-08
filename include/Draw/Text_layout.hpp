#ifndef DRAW_TEXT_LAYOUT_HPP
#define DRAW_TEXT_LAYOUT_HPP
#include "pch.hpp"
#include "Util/Color.hpp"
#include "Draw/Atlas_Region.hpp"
#include "Draw/ReText.hpp"
#include "Draw/Draw_2D.hpp"
namespace Draw{
//need fix check.
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
    //This class is affected by Setting::SCALE
    Text_layout(const std::string &text_string);
    ~Text_layout()=default;
    static void SetLanguage(language lan);
    static void SetFontWeight(font_weight fw);
    void set_middle();
    void set_left();
    //フォントサイズかえること書いてるだけと、32以上とぼやけるかも。
    void set_fontsize(int fontsize);
    void set_damage(int value);
    void set_block(int value);
    void set_vars(int value,int pos);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2,const float center_x,const float center_y,const float a=1.0F)const;
    void render_without_format_word(const std::shared_ptr<Draw::Draw_2D> &r2,const float center_x,const float center_y,const float angle,const float scale,const float origin_x,const float origin_y)const;
    float GetWidth()const{return width;}
    float GetHeight()const{return height;}
    static void split_text(std::vector<std::string> &strs,const std::string &text_string);
private:
    struct regs_info{
        bool is_var=false;
        float x,y,w,h;
        Uint32 c=-1;
    };
    static void pos_update();
    static void init_orbs();
    static void init_nums();
    void set_texture_pos(const std::shared_ptr<Draw::ReText> &t_retext,const std::vector<std::string> &strs);
    void adjust_pos(int info_pos,float dis);
    void set_things(int info_pos,int value,int old_value);
    void fix_width();
    void scale_all_pos(const float scale);
    static language s_language;
    static std::string s_lan_pos;
    static font_weight s_font_weight;
    static std::shared_ptr<Draw::Atlas_Region>orb_red,orb_green,orb_blue,orb_purple,orb_card,orb_potion,orb_relic,orb_special;
    static std::shared_ptr<Draw::Image_Region> nums[10];
    static constexpr Uint32 GOLD_COLOR=-272084481,
                            RED_TEXT_COLOR = -10132481,
                            GREEN_TEXT_COLOR = 2147418367,
                            BLUE_TEXT_COLOR = -2016482305,
                            PURPLE_COLOR = -293409025,
                            WHITE=-1;
    static constexpr int BIGGIST_SIZE=32;//temp max 32 if there is a bigger font ,adjust this.
    std::vector<std::shared_ptr<Draw::Image_Region>> regs;
    std::vector<regs_info> m_regs_info;
    
    int damage_pos=-1,block_pos=-1,damage=0,block=0;
    std::vector<std::pair<int,int>> pos_and_vars;

    int m_fontsize;
    float width,height;
    bool middle_mode;
};
}
#endif