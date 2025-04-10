#include "Game_object/map/Legend_item.hpp"
#include "Game_object/map/Map_node.hpp"
namespace Map
{
    Legend_item::Legend_item(const std::shared_ptr<Draw::ReTexture> &img,const std::shared_ptr<Draw::Text_layout> &label,const std::shared_ptr<Draw::Text_layout> &title,const std::shared_ptr<Draw::Text_layout> &body,int idx):
    y(LEGEND_Y - idx * SPACE + OFFSET),
    img(img),
    m_text_box(title, body, 1500.0F*Setting::SCALE, 270.0F*Setting::SCALE),
    hb(TEXT_X, this->y, 230.0F*Setting::SCALE, SPACE-2.0,true),
    label(label){}

    void Legend_item::render(const std::shared_ptr<Draw::Draw_2D> &r2,const float color_a)const{
        r2->SetColor(Map_node::AVAILABLE_COLOR,color_a);
        if(hb.Hovered()){
            r2->draw(img, ICON_X-64.0F, this->y-64.0F, 128.0F, 128.0F, 0.0F, 64.0F, 64.0F, Setting::SCALE/1.2F, Setting::SCALE/1.2F);
            label->render_without_format_word_top_left(r2, TEXT_X-50.0F*Setting::SCALE, this->y+13.0F*Setting::SCALE);
            m_text_box.render(r2);
        }else{
            r2->draw(img, ICON_X-64.0F, this->y-64.0F, 128.0F, 128.0F, 0.0F, 64.0F, 64.0F, Setting::SCALE/1.65F, Setting::SCALE/1.65F);
            label->render_without_format_word_top_left(r2, TEXT_X-50.0F*Setting::SCALE, this->y+13.0F*Setting::SCALE);
        }
    }
} // namespace Map
