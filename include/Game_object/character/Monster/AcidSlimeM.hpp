#ifndef GAME_OBJECT_CHARACTER_MONSTER_ACIDSLIMEM
#define GAME_OBJECT_CHARACTER_MONSTER_ACIDSLIMEM
#include "Game_object/character/Monster/Monsters.hpp"

namespace Monster{
    enum class AcidSlimeMAction
    {
        CorrosiveSpit,
        Lick,
        Tackle,
    };
class AcidSlimeM final:public Monsters
{
public:
    AcidSlimeM();
    ~AcidSlimeM()override=default;
    void Action(AcidSlimeMAction action_type);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2) const override;
    // void apply(const std::shared_ptr<Action::Action_group> &action_group)const override;
private:
    
    static const std::shared_ptr<Draw::ReTexture> &img;
    static constexpr int HEIGHT_OFFSET=-200.0F*Setting::SCALE;
    static constexpr int WIDTH=300.0F*Setting::SCALE,
                         HIGHT=180.0F*Setting::SCALE;
};
}
#endif