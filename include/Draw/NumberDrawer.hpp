#pragma once

#include <memory>
#include <vector>

//fwd decl
namespace Draw{
    class Image_Region;
    class Draw_2D;
}

namespace Draw{
//Assume that all digits have the same width and height
class NumberDrawer
{
public:
    NumberDrawer(int fontsize);
    ~NumberDrawer()=default;
    void SetFontHeight(const float h){unit_w*=h/unit_h;unit_h=h;}
    void render(const std::shared_ptr<Draw_2D> &r2,const std::string &num_str,const float center_x,const float center_y,const float scale=1.0F)const;
private:
    int unit_w,unit_h;
    int fontsize;
public://need to delete.
    static const std::vector<std::shared_ptr<Image_Region>> &GetNums();
};
}