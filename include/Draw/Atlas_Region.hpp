#pragma once
#include "Draw/Image_Region.hpp"
#include <string>
namespace Draw{
class Atlas_Region:public Draw::Image_Region
{
public:
    Atlas_Region(const std::string &name,int x,int y,
                 const std::shared_ptr<Draw::ReTexture> &texture,
                 float offsetX,float offsetY,
                 int packed_width,int packed_height,
                 int original_width,int original_height,
                 bool rotate);
    ~Atlas_Region()=default;
    //read-only first,if something goes wrong it will be change.
    const std::string name;
    const float offsetX,offsetY;
    const int original_width,original_height;
    const bool rotate;
};
}
