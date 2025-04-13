#include "Draw/Image_Region.hpp"
#include "Draw/ReTexture.hpp"

namespace Draw{
    Image_Region::Image_Region(const std::shared_ptr<ReTexture> &texture,
        const int x, const int y,
        const int width, const int height):texture(texture){
        SetRegion(x,y,width,height);
    }
    void Image_Region::SetRegion(const int x,const int y,const int width,const int height){
        region_w=width==-1?texture->GetWidth():abs(width);
        region_h=height==-1?texture->GetHeight():abs(height);
        float unit_w=1.0F/(float)texture->GetWidth(),
              unit_h=1.0F/(float)texture->GetHeight();
        SetRegion((float)x*unit_w,(float)y*unit_h,(float)(x+region_w)*unit_w,(float)(y+region_h)*unit_h);
    }
    void Image_Region::SetRegion(const float u,const float v,const float u2,const float v2){
        //private
        //Don't need worry about region are wrong.
        this->u=u;
        this->v=v;
        this->u2=u2;
        this->v2=v2;
        //for sometime may wrong if pixel are exact one
        //IDK
        //java gdx did this small adjust.
        if(region_h==1 && region_w==1){
            int t_w=texture->GetWidth(),
                t_h=texture->GetHeight();
            float adj_x=0.25F/(float)t_w,
                  adj_y=0.25F/(float)t_h;
            this->u+=adj_x;
            this->u2-=adj_x;
            this->v+=adj_y;
            this->v2-=adj_y;
        }
    }
}