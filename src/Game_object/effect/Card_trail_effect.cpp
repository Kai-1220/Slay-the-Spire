#include <memory>
#include <GL/glew.h>

#include "Game_object/effect/Card_trail_effect.hpp"
#include "RUtil/Some_Math.hpp"
#include "RUtil/All_Image.hpp"
#include "Draw/Atlas_Region.hpp"
#include "Draw/Draw_2D.hpp"

namespace Effect
{
    void Card_trail_effect::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE);
        r2->SetColor(color,color_a);
        r2->draw(IMG,pos.x,pos.y,12.0F,12.0F,0.0F,6.0F,6.0F,scale,scale);
    }
    void Card_trail_effect::update(){
        this->TimeGo();        
        if(duration<0.25F){
            scale=duration*SCALE_MULTI;
        }else{
            scale=(duration-0.25F)*SCALE_MULTI;
        }
        if(!is_done)
            color_a=RUtil::Math::interpolation_fade(0.0F,0.18F,duration*2.0F);
    }
    const std::shared_ptr<Draw::Atlas_Region> &Card_trail_effect::IMG=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::_combat_blurDot2);
} // namespace Effect
