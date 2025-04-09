#ifndef DRAW_TEXT_BOX
#define DRAW_TEXT_BOX
#include "Draw/Text_layout.hpp"
#include "RUtil/Image_book.hpp"
#include "WindowSize.hpp"
#include "RUtil/Some_Math.hpp"
namespace Draw{
class Text_box
{
public:
    Text_box(const std::shared_ptr<Text_layout> &title,const std::shared_ptr<Text_layout> &body,const float x=0.0F,const float y=0.0F);
    ~Text_box()=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void SetX(const float x){this->x=x;}
    void SetY(const float y){this->y=y;}
    void SetXY(const float x,const float y){this->x=x;this->y=y;}
private:
    void render_box(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    const std::shared_ptr<Text_layout> &title,&body;
    float x,y;
    static const std::shared_ptr<Draw::ReTexture> &s_tip_top,&s_tip_mid,&s_tip_bot;
    static constexpr int SHADOW_A=64,TITLE_FONT_SIZE=23,BODY_FONT_SIZE=23;
    static constexpr Uint32 BASE_COLOR = RUtil::Math::GetColorUint32_RGB(1.0F, 0.9725F, 0.8745F);
    static constexpr float SHADOW_DIST_Y = 14.0F * Setting::SCALE,
                           SHADOW_DIST_X = 9.0F * Setting::SCALE,
                           BOX_EDGE_H = 32.0F * Setting::SCALE,
                           BOX_BODY_H = 64.0F * Setting::SCALE,
                           BOX_W = 320.0F * Setting::SCALE,
                           TEXT_OFFSET_X = 22.0F *Setting::SCALE,
                           HEADER_OFFSET_Y = 12.0F * Setting::SCALE,
                           BODY_OFFSET_Y = -20.0F * Setting::SCALE;
      
};
}
#endif