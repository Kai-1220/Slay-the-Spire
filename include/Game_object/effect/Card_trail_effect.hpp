#pragma once

#include <glm/vec2.hpp>

#include "Game_object/effect/Effects.hpp"
#include "Game_object/interface/Reusable.hpp"
#include "WindowSize.hpp"

//fwd decl
namespace Draw{
    class Atlas_Region;
}

namespace Effect{
class Card_trail_effect final:public Effects,public Interface::Reusable<Card_trail_effect>
{
public:
    Card_trail_effect(glm::vec2 pos,Uint32 RGB_color){Initial(pos,RGB_color);}
    ~Card_trail_effect() override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void update() override;
    //reusable interface function
    void Initial(glm::vec2 pos,Uint32 RGB_color){
        this->pos=pos-6.0F;
        this->color=RGB_color;
        this->duration=0.5F;
        this->scale=0.01F;
    }
    //pool function
    static constexpr bool UseAutoRelease()noexcept{return true;}
private:
glm::vec2 pos;
static const std::shared_ptr<Draw::Atlas_Region> &IMG;
static constexpr float SCALE_MULTI = Setting::SCALE * 22.0F;
};
}