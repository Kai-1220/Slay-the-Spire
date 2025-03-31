#include "Game_object/effect/Card_trail_effect.hpp"
#include "RUtil/Game_Input.hpp"
#include "RUtil/Some_Math.hpp"
namespace Effect
{
    Card_trail_effect::Card_trail_effect(glm::vec2 pos,Uint32 RGB_color):Effects(RGB_color),pos(pos-6.0F){
        duration=0.5F;
        scale=0.01F;
    }
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
} // namespace Effect
