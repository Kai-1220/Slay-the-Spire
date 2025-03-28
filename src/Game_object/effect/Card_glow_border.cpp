#include "Game_object/effect/Card_glow_border.hpp"
#include "RUtil/Game_Input.hpp"
namespace Effect
{
    Card_glow_border::Card_glow_border(const std::shared_ptr<Draw::Atlas_Region>&silhouette,const int &card_x,const int &card_y,const float &card_angle,const float &card_scale):Effects(DFAULT_COLOR),card_x(card_x),card_y(card_y),card_angle(card_angle),card_scale(card_scale),img(silhouette){
        this->duration=1.2F;
    }
    void Card_glow_border::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE);
        r2->SetColor(color,color_a);
        r2->draw(img, card_x + img->offsetX - (float)img->original_width/2.0F, card_y + img->offsetY - (float)img->original_height/2.0F, (float)img->GetRegionWidth(), (float)img->GetRegionHeight(), card_angle, (float)img->original_width/2.0F - img->offsetX, (float)img->original_height/2.0F - img->offsetY, this->scale, this->scale);
    }
    void Card_glow_border::update(){
        if(this->duration<0.0F) is_done=true;
        else{
            this->scale=(1.0F+RUtil::Math::interpolation_powout2(0.03F,0.11F,1.0F-this->duration))*card_scale*Setting::SCALE;
            this->color_a=this->duration/2.0F;
            this->duration-=RUtil::Game_Input::delta_time();
        }
    }
} // namespace Effect
