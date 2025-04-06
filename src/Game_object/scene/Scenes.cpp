#include "Game_object/scene/Scenes.hpp"
namespace Scene
{
    void Scenes::render_format(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region>&img){
        r2->draw(img, img->offsetX*Setting::SCALE, img->offsetY*Setting::SCALE, (float)img->GetRegionWidth(), (float)img->GetRegionHeight(), 0.0F, 0.0F, 0.0F, Setting::SCALE, Setting::SCALE);
    }
} // namespace Scene
