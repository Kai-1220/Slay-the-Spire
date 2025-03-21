#include "Game_object/map/Map_dot.hpp"
#include "RUtil/Some_Math.hpp"
namespace Map{
    Map_dot::Map_dot(float x,float y,float rotation,bool jitter){
        if(dot_texture==nullptr)dot_texture=RUtil::Image_book::GetTexture("Image/map/dot1.png");
        if(jitter){
            this->x=x+RUtil::Math::GetRandomFloat(-DIST_JITTER,DIST_JITTER);
            this->y=y+RUtil::Math::GetRandomFloat(-DIST_JITTER,DIST_JITTER);
            this->rotation=rotation+RUtil::Math::GetRandomFloat(-20.0F,20.0F);
        }else{
            this->x=x;this->y=y;this->rotation=rotation;
        }
    }
    void Map_dot::render(const std::shared_ptr<Draw::Draw_2D> &r2,float screen_offset)const{
        r2->draw(dot_texture,this->x-8.0F,this->y-8.0F+screen_offset+OFFSET_Y,
                16.0F,16.0F,this->rotation,8.0F,8.0F,Setting::SCALE,Setting::SCALE);
    }
    std::shared_ptr<Draw::ReTexture> Map_dot::dot_texture=nullptr;//RUtil::Image_book::GetTexture("image/map/dot1.png");
}