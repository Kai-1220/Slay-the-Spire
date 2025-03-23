#include "Game_object/effect/Card_trail_effect.hpp"
#include "RUtil/Game_Input.hpp"
#include "RUtil/Some_Math.hpp"
namespace Effect
{
    Card_trail_effect::Card_trail_effect(float x,float y,Uint32 RGB_color):x(x-6.0F),y(y-6.0F),color(RGB_color){
        if(IMG==nullptr) IMG=RUtil::Atlas_shared::GetRegion(RESOURCE_DIR"/Image/vfx/vfx.atlas","combat/blurDot2");
        duration=0.5F;
        scale=0.01F;
        is_done=false;
        color_a=1.0F;
    }
    void Card_trail_effect::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE);
        r2->SetColor(color,color_a);
        r2->draw(IMG,x,y,12.0F,12.0F,0.0F,6.0F,6.0F,scale,scale);
    }
    void Card_trail_effect::update(){
        duration-=RUtil::Game_Input::delta_time();        
        if(duration<0.25F){
            scale=duration*SCALE_MULTI;
        }else{
            scale=(duration-0.25F)*SCALE_MULTI;
        }
        if(duration<0.0F){
            is_done=true;
        }else{
            color_a=RUtil::Math::interpolation_fade(0.0F,0.18F,duration*2.0F);
        }
    }
    std::shared_ptr<Draw::Atlas_Region> Card_trail_effect::IMG=nullptr;
} // namespace Effect
