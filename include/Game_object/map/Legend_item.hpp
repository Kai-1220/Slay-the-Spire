#ifndef GAME_OBJECT_MAP_LEGEND_ITEM
#define GAME_OBJECT_MAP_LEGEND_ITEM
#include "Draw/Text_box.hpp"
#include "RUtil/Hitbox.hpp"
namespace Map{
class Legend_item
{
public:
    Legend_item(const std::shared_ptr<Draw::ReTexture> &img,const std::shared_ptr<Draw::Text_layout> &label,const std::shared_ptr<Draw::Text_layout> &title,const std::shared_ptr<Draw::Text_layout> &body,int idx);
    ~Legend_item()=default;
    void update(){this->hb.update();}
    void render(const std::shared_ptr<Draw::Draw_2D> &r2,const float color_a)const;
private:
    const float y;
    const std::shared_ptr<Draw::ReTexture> &img;
    const Draw::Text_box m_text_box;
    RUtil::Hitbox hb;
    const std::shared_ptr<Draw::Text_layout> &label;
    static constexpr float SPACE = 58.0F * Setting::SCALE,
                           OFFSET = 100.0F * Setting::SCALE,
                           ICON_X = 1575.0F * Setting::SCALE,
                           TEXT_X = 1670.0F * Setting::SCALE;
public:
    static constexpr float LEGEND_X = 1670.0F * Setting::SCALE,
                           LEGEND_Y = 600.0F * Setting::SCALE;
};
}
#endif