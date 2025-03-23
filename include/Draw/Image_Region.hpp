#ifndef DRAW_Image_Region_HPP
#define DRAW_Image_Region_HPP
#include "Draw/ReTexture.hpp"
namespace Draw {
//Reference from java gdx textureregion
/**
 * @class Image_Region
 * @brief Cut a sub_image from image.
 * 
 * (0,0) is Top-Left corner.
 */
class Image_Region
{
public:
    /**
     * @brief Constructor that takes a texture for sub_image base.
     *
     * By default, the position will be set to (0, 0) in the top-left corner
     * 
     * @param texture sub_image base.
     * @param x The horizontal position of image(from the left), default is 0.
     * @param y The vertical position of image(from the top), default is 0.
     * @param width The width of the image region. Default is the full width of the texture.
     * @param height The height of the image region. Default is the full height of the texture.
     * 
     */
    Image_Region(const std::shared_ptr<ReTexture> &ReTexture,
        const int x = 0, const int y = 0,
        const int width = -1, const int height = -1);
    void SetRegion(const int x=0,const int y=0,const int width=-1,const int height=-1);
    void SetTexture(const std::shared_ptr<ReTexture> &ReTexture);
    std::shared_ptr<ReTexture> GetTexture()const{return texture;}
    int GetRegionWidth()const{return region_w;}
    int GetRegionHeight()const{return region_h;}
    float GetU()const{return u;}
    float GetU2()const{return u2;}
    float GetV()const{return v;}
    float GetV2()const{return v2;}
    virtual ~Image_Region() = default;
private:
    void SetRegion(const float u,const float v,const float u2,const float v2);
    std::shared_ptr<ReTexture> texture;//ptr to texture
    float u,v,u2,v2;//from top-left corner
    int region_w,region_h;
};


}
#endif