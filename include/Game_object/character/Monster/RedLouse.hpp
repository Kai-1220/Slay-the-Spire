#ifndef GAME_OBJECT_CHARACTER_MONSTER_REDLOUSE_HPP
#define GAME_OBJECT_CHARACTER_MONSTER_REDLOUSE_HPP
#include "Game_object/character/Monster/Monsters.hpp"

namespace Monster{
enum class RedLouseAction
{
    Bite,
    Grow
};
class RedLouse final:public Monsters
{
public:
    RedLouse();
    ~RedLouse()override=default;
    void Action(RedLouseAction action_type);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2) const override;
    // void apply(const std::shared_ptr<Action::Action_group> &action_group)const override;
private:
    
    static const std::shared_ptr<Draw::ReTexture> &img;
    static constexpr int HEIGHT_OFFSET=-200.0F*Setting::SCALE;
    static constexpr int WIDTH=300.0F*Setting::SCALE,
                         HIGHT=180.0F*Setting::SCALE;
    static constexpr int MAX_HP=15,
                         MIN_HP=10,
                         MIN_DAMAGE=5,
                         MAX_DAMAGE=7;
};
}
#endif