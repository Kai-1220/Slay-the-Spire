#pragma once

#include <memory>
#include <list>

#include "Game_object/Group_template.hpp"

//fwd decl
namespace Effect{
    class Effects;
}
namespace Draw{
    class Draw_2D;
}

namespace Effect
{
class Effect_group:public Template::Group_template<std::list<std::shared_ptr<Effects>>>
{
public:
    Effect_group()=default;
    ~Effect_group()override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void update();
    
    using Template::Group_template<std::list<std::shared_ptr<Effects>>>::AddTop;
    void AddTop(Effects* const item){box2.emplace_back(item);}
private:
    std::list<Effects*> box2;
};
} // namespace Effect
