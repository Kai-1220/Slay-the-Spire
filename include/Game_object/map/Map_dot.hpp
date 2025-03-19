#ifndef GAME_OBJECT_MAP_DOT_MAP
#define GAME_OBJECT_MAP_DOT_MAP
#include "WindowSize.hpp"
#include "RUtil/Image_book.hpp"
#include "Draw/Draw_2D.hpp"
namespace Map{
class Map_dot{
public:
    //x,y are texture center
    Map_dot(float x,float y,float rotation,bool jitter);
    ~Map_dot()=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2,float screen_offset)const;
private:
    float x,y,rotation;
    static std::shared_ptr<Draw::ReTexture> dot_texture;
    static constexpr float DIST_JITTER = 4.0F * Setting::SCALE;
    static constexpr float OFFSET_Y = 172.0F * Setting::SCALE;
};
}
#endif