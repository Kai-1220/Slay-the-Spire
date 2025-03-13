#include "Draw/Atlas_Region.hpp"
namespace Draw
{
Atlas_Region::Atlas_Region( const std::string &name,int x,int y,
                const std::shared_ptr<Draw::ReTexture> &texture,
                float offsetX,float offsetY,
                int packed_width,int packed_height,
                int original_width,int original_height,
                bool rotate):
                offsetX(offsetX),offsetY(offsetY),
                packed_width(packed_width),packed_height(packed_height),
                rotate(rotate),name(name),
                Image_Region(texture,x,y,original_width,original_height){}                          
} // namespace Draw