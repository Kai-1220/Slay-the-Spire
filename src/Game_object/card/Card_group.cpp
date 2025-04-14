#include <algorithm>

#include "Game_object/card/Card_group.hpp"

#include "Util/Logger.hpp"

namespace Card{
    Card_group::Card_group(){

    }
    void Card_group::render(const std::shared_ptr<Draw::Draw_2D> &r2,Uint32 PlayerColor_RGB)const{
        for(const auto &it:box){
            it->render(r2,PlayerColor_RGB);
        }
    }
    void Card_group::update(const std::shared_ptr<Effect::Effect_group> &effs,const Uint32 PlayerColor_RGB){
        for(auto &it:box){
            it->update(effs,PlayerColor_RGB);
        }
    }
    void Card_group::MoveAllCardTo(Card_group &group){
        group.box.insert(group.box.end(), std::make_move_iterator(this->box.rbegin()), std::make_move_iterator(this->box.rend()));
        this->box.clear();
    }
    void Card_group::RemoveCard(const std::shared_ptr<Cards>&card){
        const int pos=GetCardPos(card);
        if(pos!=-1)
            box.erase(box.begin()+pos);
        else 
            LOG_ERROR("Try to remove card that not exist in this group.");
    }
    void Card_group::SortByRarity(const bool ascending){
        if(ascending)std::sort(box.begin(),box.end(),[](const auto&aa,const auto&bb){return aa->rarity<bb->rarity;});
        else std::sort(box.begin(),box.end(),[](const auto&aa,const auto&bb){return bb->rarity<aa->rarity;});
    }
    void Card_group::SortByType(const bool ascending){
        if(ascending)std::sort(box.begin(),box.end(),[](const auto&aa,const auto&bb){return aa->type<bb->type;});
        else std::sort(box.begin(),box.end(),[](const auto&aa,const auto&bb){return bb->type<aa->type;});
    }
    void Card_group::SortByCost(const bool ascending){
        if(ascending)std::sort(box.begin(),box.end(),[](const auto&aa,const auto&bb){return aa->GetCost()<bb->GetCost();});
        else std::sort(box.begin(),box.end(),[](const auto&aa,const auto&bb){return bb->GetCost()<aa->GetCost();});
    }
    std::shared_ptr<Cards> Card_group::GetHoveredCard()const{
        for(const auto&it:box){
            if(it->IsHoveredInHand(0.7F)){
                return it;
            }
        }
        return nullptr;
    }
    int Card_group::GetCardPos(const std::shared_ptr<Cards> &card)const{
        const int len=static_cast<int>(box.size());
        for(int i=0;i<len;i++) if(box[i]==card) return i;
        return -1;
    }
    Card_group& Card_group::operator=(const Card_group&other){
        box.clear();
        for(const auto&it:other) box.emplace_back(std::make_shared<Card::Cards>(*it));
        return *this;
    }
    void Card_group::ShuffleWithRng(const std::shared_ptr<RUtil::Random> &rng){
        std::shuffle(box.begin(),box.end(),*rng);
    }
    bool Card_group::IsSomeoneFlying()const{
        for(const auto&it:box)
            if(it->is_fly()) return true;
        return false;
    }
}