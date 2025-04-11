#ifndef GAME_OBJECT_CHARACTER_MONSTER_ACIDSLIMEL
#define GAME_OBJECT_CHARACTER_MONSTER_ACIDSLIMEL
#include "Game_object/character/Monster/Monsters.hpp"

namespace Monster{
enum class AcidSlimeLAction
{
    CorrosiveSpit,
    Lick,
    Tackle,
    Split
};
class AcidSlimeL final:public Monsters
{
public:
    AcidSlimeL();
    ~AcidSlimeL()override=default;
    void Action(AcidSlimeLAction action_type);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2) override;
    
    // void apply(const std::shared_ptr<Action::Action_group> &action_group)const override;
private:
    static const std::shared_ptr<Draw::ReTexture> &img;
    static constexpr int HEIGHT_OFFSET=-200.0F*Setting::SCALE;
    static constexpr int WIDTH=300.0F*Setting::SCALE,
                         HIGHT=180.0F*Setting::SCALE;
};
}
#endif