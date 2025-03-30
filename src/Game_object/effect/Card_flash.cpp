#include "Game_object/effect/Card_flash.hpp"
namespace Effect
{
    Card_flash::Card_flash(const std::shared_ptr<Draw::Atlas_Region>&silhouette,const int &card_x,const int &card_y,const float &card_angle,const float &card_scale):card_x(card_x),card_y(card_y),card_angle(card_angle),card_scale(card_scale),img(silhouette){
        change_color(DFAULT_COLOR);
    }
    Card_flash::Card_flash(const std::shared_ptr<Draw::Atlas_Region>&silhouette,const int &card_x,const int &card_y,const float &card_angle,const float &card_scale,const Uint32 color):card_x(card_x),card_y(card_y),card_angle(card_angle),card_scale(card_scale),img(silhouette){
        change_color(color);
    }
    void Card_flash::change_color(const Uint32 color){
        this->color=color;
        this->scale=0.0F;
        this->duration=0.5F;
    }  
    void Card_flash::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE);
        r2->SetColor(color,this->duration);
        const float scale_factor=card_scale*(this->scale+1.0F)*Setting::SCALE;
        r2->draw(img, card_x + img->offsetX - (float)img->original_width/2.0F, card_y + img->offsetY - (float)img->original_height/2.0F, (float)img->GetRegionWidth(), (float)img->GetRegionHeight(), card_angle, (float)img->original_width/2.0F - img->offsetX, (float)img->original_height/2.0F - img->offsetY, scale_factor*0.52F, scale_factor*0.52F);
        r2->draw(img, card_x + img->offsetX - (float)img->original_width/2.0F, card_y + img->offsetY - (float)img->original_height/2.0F, (float)img->GetRegionWidth(), (float)img->GetRegionHeight(), card_angle, (float)img->original_width/2.0F - img->offsetX, (float)img->original_height/2.0F - img->offsetY, scale_factor*0.55F, scale_factor*0.55F);
        r2->draw(img, card_x + img->offsetX - (float)img->original_width/2.0F, card_y + img->offsetY - (float)img->original_height/2.0F, (float)img->GetRegionWidth(), (float)img->GetRegionHeight(), card_angle, (float)img->original_width/2.0F - img->offsetX, (float)img->original_height/2.0F - img->offsetY, scale_factor*0.58F, scale_factor*0.58F);
    }
    void Card_flash::update(){
        this->TimeGo();
        if(!is_done){
            this->scale=RUtil::Math::Apply(1.2F,1.1F,RUtil::Math::BounceIn(this->duration*2.0F));
        }
    }
}