#ifndef GAME_OBJECT_CARD_CARD_GROUP_HANDLER
#define GAME_OBJECT_CARD_CARD_GROUP_HANDLER

#include <list>

#include "Game_object/card/Card_group.hpp"
#include "Game_object/character/Monster/Monsters.hpp"
#include "RUtil/Image_book.hpp"
#include "Game_object/action/Action_group_handler.hpp"
namespace Card{
class Card_group_handler
{
public:
    Card_group_handler();
    ~Card_group_handler()=default;
    Card_group_handler(const Card_group_handler &) = delete;
    Card_group_handler(Card_group_handler &&) = delete;
    Card_group_handler &operator=(const Card_group_handler &) = delete;
    Card_group_handler &operator=(Card_group_handler &&)=delete;

    void discard_all();
    void discard(const std::shared_ptr<Cards> &card);
    void draw();
    void update(Action::Action_group_handler &action_group_handler);
    void refresh_hand_layout()const;
    void prepare_for_battle(const std::shared_ptr<RUtil::Random> &rng);
    void shuffle(bool shuffle_invisible);
    void hand_hide();
    void render_hand(const std::shared_ptr<Draw::Draw_2D> &r2,Uint32 PlayerColor_RGB)const;
    void render_flying_cards(const std::shared_ptr<Draw::Draw_2D> &r2, const Uint32 PlayerColor_RGB)const{for(const auto&it:flying_cards) it->render(r2,PlayerColor_RGB);}
    void update_flying_cards(Effect::Effect_group &effs, Uint32 PlayerTrailColor_RGB){
        for (auto it = flying_cards.begin(); it != flying_cards.end();) {
            (*it)->update(effs,PlayerTrailColor_RGB);
            if (!(*it)->is_fly())
                it = flying_cards.erase(it);
            else
                ++it;
        }
    }
    void update_hand_cards(Effect::Effect_group &effs, Uint32 PlayerTrailColor_RGB){hand_cards.update(effs,PlayerTrailColor_RGB);}
    void add_to_master_deck(std::shared_ptr<Cards> &&card){master_deck.AddTop(std::move(card));}
    int discard_pile_size()const{return m_discard.size();}
    int draw_pile_size()const{return draw_pile.size();}
    int hand_cards_size()const{return hand_cards.size();}
    bool is_someone_flying()const noexcept{return !flying_cards.empty();}
    void discard_pile_shuffle_with_rng(const std::shared_ptr<RUtil::Random> &rng){m_discard.ShuffleWithRng(rng);}
private:
    static const int &input_x,&input_y;
    static const bool &just_r,&just_l;
    bool single_target,in_drop_zone,pass_hesitation_line,is_dragging_card;
    float arrowX,arrowY,hover_start_line;
    std::shared_ptr<Card::Cards> hovered_card=nullptr;
    std::shared_ptr<Monster::Monsters> hovered_monster=nullptr;
    Card_group hand_cards,m_discard,draw_pile,master_deck,exhaust_pile;
    std::list<std::shared_ptr<Card::Cards>> flying_cards;//shared_ptr is needed here.
    void hand_card_push()const;
    void release_card();
    void play_card(Action::Action_group_handler &action_group_handler);
    void render_targeting(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void update_targeting();
    void update_drop_zone_status();
    void update_hovered_card();
    void handle_dragging(Action::Action_group_handler &action_group_handler);
    void check_drag_start();
    
    static const std::shared_ptr<Draw::ReTexture>&reticleBlock_img,&reticleArrow_img;
    static constexpr float SINK_START=80.0F*Setting::SCALE,SINK_RANGE=300.0F*Setting::SCALE,INCREMENT_ANGLE=5.0F,UI_THRESHOLD=1.0F*Setting::SCALE;
    static constexpr int ARROW_COLOR=RUtil::Math::GetColorUint32_RGB(1.0F,0.2F,0.3F);
};
}
#endif