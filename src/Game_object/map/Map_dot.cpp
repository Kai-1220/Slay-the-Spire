#include "Game_object/map/Map_dot.hpp"
#include "RUtil/Random.hpp"
#include "RUtil/Image_book.hpp"
#include "Draw/Draw_2D.hpp"

namespace Map{
    Map_dot::Map_dot(float x,float y,float rotation,bool jitter){
        if(jitter){
            this->x=x+RUtil::Random::GetRandomFloat(-DIST_JITTER,DIST_JITTER);
            this->y=y+RUtil::Random::GetRandomFloat(-DIST_JITTER,DIST_JITTER);
            this->rotation=rotation+RUtil::Random::GetRandomFloat(-20.0F,20.0F);
        }else{
            this->x=x;this->y=y;this->rotation=rotation;
        }
        this->rotation+=90.0F;
    }
    void Map_dot::render(const std::shared_ptr<Draw::Draw_2D> &r2,const float screen_offset)const{
        r2->draw(dot_texture,this->x-8.0F,this->y-8.0F+screen_offset+OFFSET_Y,
                16.0F,16.0F,this->rotation,8.0F,8.0F,Setting::SCALE,Setting::SCALE);
    }
    const std::shared_ptr<Draw::ReTexture> &Map_dot::dot_texture=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/dot1.png");
    
}