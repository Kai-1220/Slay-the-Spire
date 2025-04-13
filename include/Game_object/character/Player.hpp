#ifndef GAME_OBJECT_CHARACTER_PLAYER
#define GAME_OBJECT_CHARACTER_PLAYER
#include "Game_object/character/Characters.hpp"
namespace Character{
enum class PlayerType{
    Ironclad,
    Silent,
    Defect,
    Watcher
};
class Player final :public Characters
{
public:
    Player();
    virtual ~Player()=default;
    void damage(int num)override{current_HP-=num;};
    void render(const std::shared_ptr<Draw::Draw_2D> &r2) const override;
    const PlayerType player_type;
    const int &GetCurrEnergy()const{return current_enegy;}
    const int &GetMaxEnergy()const{return max_energy;}
private:
    int max_energy,current_enegy;
    static const std::shared_ptr<Draw::ReTexture> &img;
    static constexpr int WIDTH_OFFSET=-800.0F*Setting::SCALE,
                        HEIGHT_OFFSET=-200.0F*Setting::SCALE;
    static constexpr int WIDTH=300.0F*Setting::SCALE,
                        HIGHT=200.0F*Setting::SCALE;
};
}
#endif