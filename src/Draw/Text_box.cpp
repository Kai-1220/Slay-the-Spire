#include "Draw/Text_box.hpp"
#include "RUtil/ColorValuesOnly.hpp"

namespace Draw
{
    Text_box::Text_box(const std::shared_ptr<Text_layout> &title,const std::shared_ptr<Text_layout> &body,const float x,const float y):title(title),body(body),x(x),y(y){
        title->set_fontsize(TITLE_FONT_SIZE);
        body->set_fontsize(BODY_FONT_SIZE);
    }

    void Text_box::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        render_box(r2);
    }
    void Text_box::render_box(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        const float h=body->GetHeight();
        //bottom-right shadow
        r2->SetColor(RUtil::Colors::BLACK,SHADOW_A);
        r2->draw(s_tip_top, this->x + SHADOW_DIST_X, this->y - SHADOW_DIST_Y, BOX_W, BOX_EDGE_H);
        r2->draw(s_tip_mid, this->x + SHADOW_DIST_X, this->y - SHADOW_DIST_Y - h - BOX_EDGE_H, BOX_W, h + BOX_EDGE_H);
        r2->draw(s_tip_bot, this->x + SHADOW_DIST_X, this->y - SHADOW_DIST_Y - h - BOX_BODY_H, BOX_W, BOX_EDGE_H);
        r2->SetColor(-1);
        r2->draw(s_tip_top, this->x, this->y, BOX_W, BOX_EDGE_H);
        r2->draw(s_tip_mid, this->x, this->y - h - BOX_EDGE_H, BOX_W, h + BOX_EDGE_H);
        r2->draw(s_tip_bot, this->x, this->y - h - BOX_BODY_H, BOX_W, BOX_EDGE_H);
        //text
        r2->SetColor_RGBA(RUtil::GOLD_COLOR);
        title->render_without_format_word_top_left(r2, x + TEXT_OFFSET_X, y + HEADER_OFFSET_Y);
        r2->SetColor(BASE_COLOR,1.0F);
        body->render_without_format_word_top_left(r2, x + TEXT_OFFSET_X, y + BODY_OFFSET_Y);
    }
    
    const std::shared_ptr<Draw::ReTexture> &Text_box::s_tip_top=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/tip/tipTop.png"),&Text_box::s_tip_mid=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/tip/tipMid.png"),&Text_box::s_tip_bot=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/tip/tipBot.png");
} // namespace RUtil
