#ifndef GAME_OBJECT_CARD_CARD_GROUP_HANDLER
#define GAME_OBJECT_CARD_CARD_GROUP_HANDLER
#include "Game_object/card/Card_group.hpp"
namespace Card{
class Card_group_handler
{
public:
    Card_group_handler();
    ~Card_group_handler()=default;
    void discard_all();
private:
    void refresh_hand_layout();
    Card_group hand_cards,m_discard;
    static constexpr float SINK_START=80.0F*Setting::SCALE,SINK_RANGE=300.0F*Setting::SCALE,INCREMENT_ANGLE=5.0F;
};
}
#endif