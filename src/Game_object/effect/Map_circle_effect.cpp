#include <memory>

#include "Game_object/effect/Map_circle_effect.hpp"
#include "RUtil/Image_book.hpp"
#include "Draw/ReTexture.hpp"
#include "WindowSize.hpp"

namespace Effect
{
    Map_circle_effect::Map_circle_effect(const float x,const float y,const float angle):x(x),y(y),angle(angle){
        this->duration=1.2F;
        this->scale=3.0F*Setting::SCALE;
    }
    void Map_circle_effect::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        r2->SetColor(COLOR,1.0F);
        auto & img=
            (this->duration<1.0F)?IMG5:
            (this->duration<1.05F)?IMG4:
            (this->duration<1.1F)?IMG3:
            (this->duration<1.15F)?IMG2:IMG1;
        r2->draw(img, this->x-96.0F, this->y-96.0F, 192.0F, 192.0F, this->angle, 96.0F, 96.0F, this->scale, this->scale);
    }
    void Map_circle_effect::update(){
        this->TimeGo();
        this->scale=RUtil::Math::varlerp(this->scale, 1.5F*Setting::SCALE, 8.0F, 0.003F);
    }
    const std::shared_ptr<Draw::ReTexture>  &Map_circle_effect::IMG1=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/circle1.png"),
                                            &Map_circle_effect::IMG2=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/circle2.png"),
                                            &Map_circle_effect::IMG3=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/circle3.png"),
                                            &Map_circle_effect::IMG4=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/circle4.png"),
                                            &Map_circle_effect::IMG5=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/circle5.png");
} // namespace Effect
