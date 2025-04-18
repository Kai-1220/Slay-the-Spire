#include <GL/glew.h>

#include "Game_object/effect/Card_glow_border.hpp"
#include "Draw/Atlas_Region.hpp"
#include "Draw/Draw_2D.hpp"
#include "RUtil/Some_Math.hpp"
#include "WindowSize.hpp"

namespace Effect
{
    Card_glow_border::Card_glow_border(const std::shared_ptr<Draw::Atlas_Region>&silhouette,const float &card_x,const float &card_y,const float &card_angle,const float &card_scale):card_x(card_x),card_y(card_y),card_angle(card_angle),card_scale(card_scale),img(silhouette){
        color=DFAULT_COLOR;
        this->duration=1.2F;
    }
    void Card_glow_border::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE);
        r2->SetColor(color,color_a);
        r2->draw(img, card_x + img->offsetX - (float)img->original_width/2.0F, card_y + img->offsetY - (float)img->original_height/2.0F, (float)img->GetRegionWidth(), (float)img->GetRegionHeight(), card_angle, (float)img->original_width/2.0F - img->offsetX, (float)img->original_height/2.0F - img->offsetY, this->scale, this->scale);
    }
    void Card_glow_border::update(){
        this->scale=(1.0F+RUtil::Math::interpolation_powout2(0.03F,0.11F,1.0F-this->duration))*card_scale*Setting::SCALE;
        this->color_a=this->duration/2.0F;
        this->TimeGo();
    }
} // namespace Effect
