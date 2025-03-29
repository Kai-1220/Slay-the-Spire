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
    void Card_group::MoveAllCardTo(Card_group &group){
        group.card_box.insert(group.card_box.end(), std::make_move_iterator(this->card_box.rbegin()), std::make_move_iterator(this->card_box.rend()));
        this->card_box.clear();
    }
    void Card_group::RemoveTop(){
        card_box.pop_back();
    }
    void Card_group::AddTop(const std::shared_ptr<Cards>&card){
        card_box.emplace_back(card);
    }
    void Card_group::SortByRarity(const bool ascending){
        if(ascending)std::sort(card_box.begin(),card_box.end(),[](const auto&aa,const auto&bb){return aa->rarity<bb->rarity;});
        else std::sort(card_box.begin(),card_box.end(),[](const auto&aa,const auto&bb){return bb->rarity<aa->rarity;});
    }
    void Card_group::SortByType(const bool ascending){
        if(ascending)std::sort(card_box.begin(),card_box.end(),[](const auto&aa,const auto&bb){return aa->type<bb->type;});
        else std::sort(card_box.begin(),card_box.end(),[](const auto&aa,const auto&bb){return bb->type<aa->type;});
    }
    void Card_group::SortByCost(const bool ascending){
        if(ascending)std::sort(card_box.begin(),card_box.end(),[](const auto&aa,const auto&bb){return aa->GetCost()<bb->GetCost();});
        else std::sort(card_box.begin(),card_box.end(),[](const auto&aa,const auto&bb){return bb->GetCost()<aa->GetCost();});
    }
}