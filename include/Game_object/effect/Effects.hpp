#ifndef GAME_OBJECT_EFFECT_EFFECTS
#define GAME_OBJECT_EFFECT_EFFECTS
#include "Draw/Draw_2D.hpp"
namespace Effect{
class Effects
{
public:
    Effects():color(0xffffffff){};
    Effects(Uint32 color):color(color){}
    virtual ~Effects()=default;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    virtual void update()=0;
    bool IsDone()const{return is_done;}
    void TimeGo();
    void QuickDisappear(float x){duration/=x;}
protected:
    bool is_done;
    Uint32 color;
    float duration,scale,color_a=1.0F;
    static const float &DT;
};
} // namespace Effect

#endif