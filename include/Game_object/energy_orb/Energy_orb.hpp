#ifndef GAME_OBJECT_ENERGY_ORB_ENERGY_ORB
#define GAME_OBJECT_ENERGY_ORB_ENERGY_ORB
#include "Game_object/character/Player.hpp"
namespace EnergyOrb{
class Energy_orb{
public:
    Energy_orb(const int &energy_ref,const float &panel_x,const float &panel_y):energy(energy_ref),panel_x(panel_x),panel_y(panel_y){}
    virtual ~Energy_orb()=default;
    virtual void update()=0;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
protected:
    const int &energy;
    const float &panel_x,&panel_y;
    static constexpr float ORB_SCALE=1.15F*Setting::SCALE;
};
}
#endif