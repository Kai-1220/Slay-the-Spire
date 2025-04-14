#include <GL/glew.h> 

#include "Game_object/effect/Fade_wide.hpp"
#include "RUtil/Some_Math.hpp"
#include "RUtil/All_Image.hpp"
#include "RUtil/Image_book.hpp"
#include "Draw/ReTexture.hpp"
#include "Draw/Atlas_Region.hpp"
#include "Draw/Draw_2D.hpp"
#include "WindowSize.hpp"

namespace Effect
{
    Fade_wide::Fade_wide(Uint32 dungeon_fade_color){
        color=dungeon_fade_color;
        color_a=0.0F;
        duration=1.5F;
        this->y=(float)(Setting::WINDOW_HEIGHT+IMG->GetRegionHeight());
        //scale is used as a timer here.
        this->scale=0.1F;
    }
    void Fade_wide::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        r2->SetColor(this->color,this->color_a);
        r2->draw(IMG,0.0F,this->y,(float)Setting::WINDOW_WIDTH,(float)IMG->GetRegionHeight());
        r2->draw(white_square,0.0F,this->y+(float)IMG->GetRegionHeight()-1.0F*Setting::SCALE,(float)Setting::WINDOW_WIDTH,(float)Setting::WINDOW_HEIGHT);
    }
    void Fade_wide::update(){
        if(0.0F<this->scale){//delay timer
            this->scale-=DT;
        }else{
            //1sec for fadein, 0.5sec wait, and then clear fade.
            this->duration-=DT;
            if(this->duration<0.0F){
                this->color_a=RUtil::Math::varlerp(this->color_a,0.0F,3.0F,0.01F);
                if(color_a<=0.0F) is_done=true;
            }else if(0.5F<this->duration){
                this->color_a=RUtil::Math::Apply(1.0F,0.0F,glm::pow((this->duration-0.5F)/1.0F,5));
                this->y=RUtil::Math::Apply((float)(-IMG->GetRegionHeight()),(float)(Setting::WINDOW_HEIGHT+IMG->GetRegionHeight()),glm::pow((this->duration-0.5F)/1.0F,3));
            }
        }
    }
    const std::shared_ptr<Draw::Atlas_Region> &Fade_wide::IMG=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::_ui_topDownFader);
    const std::shared_ptr<Draw::ReTexture> &Fade_wide::white_square=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/other/whiteSquare32.png");
} // namespace Effect
