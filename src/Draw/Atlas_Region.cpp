#include "Draw/Atlas_Region.hpp"
namespace Draw
{
Atlas_Region::Atlas_Region(const std::string& name, int x, int y,
    const std::shared_ptr<Draw::ReTexture>& texture,
    float offsetX, float offsetY,
    int packed_width, int packed_height,
    int original_width, int original_height, bool rotate): 
                Draw::Image_Region(texture, x, y, packed_width, packed_height),
                name(name),
                offsetX(offsetX),
                offsetY(offsetY),
                original_width(original_width),
                original_height(original_height),
                rotate(rotate){}                         
} // namespace Draw