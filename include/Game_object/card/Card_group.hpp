#ifndef GAME_OBJECT_CARD_CARD_GROUP
#define GAME_OBJECT_CARD_CARD_GROUP
#include "Game_object/card/Cards.hpp"
namespace Card{
class Card_group
{
public:
    Card_group();
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void update(const std::shared_ptr<Effect::Effect_group> &effs,const Uint32 PlayerColor_RGB);
    ~Card_group()=default;

private:
    std::vector<std::shared_ptr<Cards>> card_box;
};
}
#endif