#ifndef GAME_OBJECT_CARD_CARD_GROUP_HANDLER
#define GAME_OBJECT_CARD_CARD_GROUP_HANDLER
#include "Game_object/card/Card_group.hpp"
#include "Game_object/character/Monster/Monsters.hpp"
#include "RUtil/Image_book.hpp"
namespace Card{
class Card_group_handler
{
public:
    Card_group_handler();
    ~Card_group_handler()=default;
    void discard_all();
    void draw(int n);
    void update();
private:
    const int &input_x=RUtil::Game_Input::getX(),&input_y=RUtil::Game_Input::getY();
    const bool &just_r=RUtil::Game_Input::just_clicked_R(),&just_l=RUtil::Game_Input::just_clicked();
    void refresh_hand_layout()const;
    void hand_card_push()const;
    void release_card();
    void render_hand(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void render_targeting(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void update_targeting();
    bool single_target,in_drop_zone,pass_hesitation_line,is_dragging_card;
    float arrowX,arrowY,hover_start_line;
    std::shared_ptr<Card::Cards> hovered_card=nullptr;
    std::shared_ptr<Monster::Monsters> hovered_monster=nullptr;
    Card_group hand_cards,m_discard,drawPile;
    static const std::shared_ptr<Draw::ReTexture>&reticleBlock_img,&reticleArrow_img;
    static constexpr float SINK_START=80.0F*Setting::SCALE,SINK_RANGE=300.0F*Setting::SCALE,INCREMENT_ANGLE=5.0F,UI_THRESHOLD=1.0F*Setting::SCALE;
    static constexpr int ARROW_COLOR=RUtil::Math::GetColorUint32_RGB(1.0F,0.2F,0.3F);
};
}
#endif