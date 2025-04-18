#ifndef GAME_OBJECT_CHARACTER_MONSTER_CULTIST_HPP
#define GAME_OBJECT_CHARACTER_MONSTER_CULTIST_HPP
#include "Game_object/character/Monster/Monsters.hpp"

namespace Monster{
enum class CultistAction
{
    Incantation,
    DarkStrike,
};
class Cultist final:public Monsters
{
public:
    Cultist();
    ~Cultist()override=default;
    void Action(CultistAction action_type);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2) const override;
    // void apply(const std::shared_ptr<Action::Action_group> &action_group)const override;
private:
    
    static const std::shared_ptr<Draw::ReTexture> &img;
    static constexpr int HEIGHT_OFFSET=-200.0F*Setting::SCALE;
    static constexpr int WIDTH=300.0F*Setting::SCALE,
                         HIGHT=180.0F*Setting::SCALE;
    static constexpr int MAX_HP=54,
                         MIN_HP=48,
                         DAMAGE=6;
};
}
#endif