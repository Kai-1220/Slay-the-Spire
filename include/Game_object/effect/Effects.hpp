#ifndef GAME_OBJECT_EFFECT_EFFECTS
#define GAME_OBJECT_EFFECT_EFFECTS
#include "Draw/Draw_2D.hpp"
namespace Effect{
class Effects
{
public:
    virtual ~Effects()=default;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    virtual void update()=0;
    bool IsDone()const{return is_done;}
protected:
    bool is_done;
};
} // namespace Effect

#endif