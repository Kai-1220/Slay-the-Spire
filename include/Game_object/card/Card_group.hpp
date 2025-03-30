#ifndef GAME_OBJECT_CARD_CARD_GROUP
#define GAME_OBJECT_CARD_CARD_GROUP
#include "Game_object/card/Cards.hpp"
namespace Card{
class Card_group
{
public:
    Card_group();
    Card_group(const Card_group&) = delete;
    Card_group(Card_group&&) = delete;
    Card_group& operator=(const Card_group&) = delete;
    Card_group& operator=(Card_group&&) = delete;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void update(const std::shared_ptr<Effect::Effect_group> &effs,const Uint32 PlayerColor_RGB);
    void SortByRarity(const bool ascending);
    void SortByType(const bool ascending);
    void SortByCost(const bool ascending);
    void MoveAllCardTo(Card_group &group);
    void RemoveTop();
    void AddTop(const std::shared_ptr<Cards>&card);
    std::shared_ptr<Cards> GetHoveredCard()const;
    int GetCardPos(const std::shared_ptr<Cards> &card)const;
    const auto&Top()const{return card_box.back();}
    const auto&Bot()const{return card_box.front();}
    ~Card_group()=default;
    int Size()const{return static_cast<int>(card_box.size());}
    const std::shared_ptr<Cards>&operator[](size_t idx)const{return card_box[idx];}
    auto begin()const{return card_box.begin();}
    auto end()const{return card_box.end();}
    bool empty()const{return card_box.empty();}
private:
    std::vector<std::shared_ptr<Cards>> card_box;
};
}
#endif