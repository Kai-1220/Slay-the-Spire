#pragma once

#include "Game_object/effect/Effects.hpp"
#include "Game_object/interface/Reusable.hpp"

//fwd decl
namespace Draw{
    class ReTexture;
}

namespace Effect{
class End_turn_button_glow final:public Effects,public Interface::Reusable<End_turn_button_glow>
{
public:
    End_turn_button_glow(const float &button_x,const float &button_y);
    ~End_turn_button_glow()override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update() override;
    void Initial(float,float);
private:
    const float &button_x,&button_y;
    static const std::shared_ptr<Draw::ReTexture> img;
};
}