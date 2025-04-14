#include <GL/glew.h> 

#include "Game_object/effect/Refresh_energy_effect.hpp"
#include "RUtil/Some_Math.hpp"
#include "RUtil/All_Image.hpp"
#include "Draw/Atlas_Region.hpp"
#include "Draw/Draw_2D.hpp"
#include "WindowSize.hpp"

namespace Effect
{
    Refresh_energy_effect::Refresh_energy_effect(const float &panel_x,const float &panel_y):panel_x(panel_x),panel_y(panel_y){
        this->scale=Setting::SCALE/1.2F;
        this->duration=0.4F;
    }
    void Refresh_energy_effect::update(){
        this->TimeGo();
        this->scale*=1.0F + DT*2.5F;
        this->color_a=RUtil::Math::interpolation_fade(0.0F,0.75F,this->duration/0.4F);
        if(color_a<0.0F) color_a=0.0F;
    }
    void Refresh_energy_effect::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE);
        r2->SetColor(-1,color_a);
        r2->draw(white_ring, panel_x, panel_y, (float)white_ring->GetRegionWidth(), (float)white_ring->GetRegionHeight(), 0.0F, (float)white_ring->GetRegionWidth()/2.0F, (float)white_ring->GetRegionHeight()/2.0F, this->scale, this->scale);
    }
    const std::shared_ptr<Draw::Atlas_Region> & Refresh_energy_effect::white_ring=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::_whiteRing);
} // namespace Effect