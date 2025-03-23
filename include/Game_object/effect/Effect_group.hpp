#ifndef GAME_OBJECT_EFFECT_EFFECT_GROUP
#define GAME_OBJECT_EFFECT_EFFECT_GROUP
#include "Game_object/effect/Effects.hpp"
#include <list>
namespace Effect
{
class Effect_group
{
public:
    Effect_group()=default;
    ~Effect_group()=default;
    void AddEffect(std::shared_ptr<Effects> &&eff);
    void AddEffect(const std::shared_ptr<Effects> &eff);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void update();
private:
    std::list<std::shared_ptr<Effects>> box;
};

} // namespace Effect

#endif