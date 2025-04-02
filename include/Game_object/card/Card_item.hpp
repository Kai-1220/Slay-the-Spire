#ifndef GAME_OBJECT_CARD_ITEM
#define GAME_OBJECT_CARD_ITEM
#include <memory>
namespace Monster{
class Monsters;
}
namespace Card{
class Cards;
struct Card_item
{ 
    std::shared_ptr<Cards> card;
    std::shared_ptr<Monster::Monsters> monster;
};
}
#endif