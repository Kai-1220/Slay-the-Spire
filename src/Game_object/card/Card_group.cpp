#include "Game_object/card/Card_group.hpp"
namespace Card{
    Card_group::Card_group(){

    }
    void Card_group::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        for(const auto &it:card_box){
            it->render(r2);
        }
    }
    void Card_group::update(const std::shared_ptr<Effect::Effect_group> &effs,const Uint32 PlayerColor_RGB){
        for(auto &it:card_box){
            it->update(effs,PlayerColor_RGB);
        }
    }
}