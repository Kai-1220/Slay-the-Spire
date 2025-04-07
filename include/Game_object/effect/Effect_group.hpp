#ifndef GAME_OBJECT_EFFECT_EFFECT_GROUP
#define GAME_OBJECT_EFFECT_EFFECT_GROUP
#include "Game_object/effect/Effects.hpp"
#include "Game_object/Group_template.hpp"
#include <list>
namespace Effect
{
class Effect_group:public Template::Group_template<std::list<std::shared_ptr<Effects>>>
{
public:
    Effect_group()=default;
    ~Effect_group()override=default;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void update();
};

} // namespace Effect

#endif