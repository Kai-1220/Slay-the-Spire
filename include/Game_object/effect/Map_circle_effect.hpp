#ifndef GAME_OBJECT_EFFECT_MAP_CIRCLE_EFFECT
#define GAME_OBJECT_EFFECT_MAP_CIRCLE_EFFECT
#include "Game_object/effect/Effects.hpp"
#include "RUtil/Image_book.hpp"
#include "RUtil/Some_Math.hpp"
namespace Effect{
class Map_circle_effect final:public Effects
{
public:
    Map_circle_effect(const float x,const float y,const float angle);
    ~Map_circle_effect()override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update() override;
private:
const float x,y,angle;
static const std::shared_ptr<Draw::ReTexture> &IMG1,&IMG2,&IMG3,&IMG4,&IMG5;
static constexpr Uint32 COLOR=RUtil::Math::GetColorUint32_RGB(0.09F,0.13F,0.17F);
};
}
#endif