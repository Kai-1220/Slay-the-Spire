#include "Game_object/card/Card_group_handler.hpp"
#include "Util/Logger.hpp"
#include "Cursor.hpp"
namespace Card{
    static constexpr float LOW_LOW_LINE=50.0F*Setting::SCALE;
    static constexpr float HOVER_CARD_Y_POSITION=210.0F*Setting::SCALE;
    static constexpr float START_LINE_OFFSET=140.0F*Setting::SCALE;
    static constexpr float CARD_DROP_END_Y=static_cast<float>(WINDOW_HEIGHT)*0.81F;
    static constexpr float CARD_DROP_START_Y=350.0F*Setting::SCALE;
    Card_group_handler::Card_group_handler(){
        single_target=in_drop_zone=pass_hesitation_line=is_dragging_card=false;
        //in_drop_zone:(x,y) in area that can use card.
        //in_draggin_card: dragging card,include in single_target mode
        //single_target: targeting one enemy
        //pass_hesitation_line: dragging card to in_drop_zone
    }
    void Card_group_handler::draw(){
        if(draw_pile.empty()){
            LOG_ERROR("the draw_pile is empty but, it was drawn.");
        }else{
            auto card=draw_pile.PopTop();
            card->draw();
            card->SetHoverTimer(0.0F);
            hand_cards.AddTop(card);
        }
    }
    void Card_group_handler::discard_all(){
        for(const auto&it:hand_cards){
            it->Shrink();
            it->Darken();//false
            it->discard();
        }
        hand_cards.MoveAllCardTo(m_discard);
    }
    void Card_group_handler::discard(const std::shared_ptr<Cards> &card){
        card->Shrink();
        card->Darken();
        card->discard();
        m_discard.AddTop(card);
    }
    void Card_group_handler::release_card(){
        single_target=false;
        in_drop_zone=false;
        pass_hesitation_line=false;
        is_dragging_card=false;
        if(hovered_card!=nullptr){
            //hovertimer
            hovered_card->SetHoverTimer(0.25F);
            hovered_card->Unhover();
        }
        hovered_card=nullptr;
        refresh_hand_layout();
        
    }
    void Card_group_handler::play_card(const std::shared_ptr<Action::Action_group_handler> &action_group_handler){
        hovered_card->Unhover();
        hand_cards.RemoveCard(hovered_card);
        if(hovered_card->target==Target::enemy||hovered_card->target==Target::self_and_enemy)
            action_group_handler->AddCardQueue(Card_item{hovered_card,hovered_monster});
        else
            action_group_handler->AddCardQueue(Card_item{hovered_card,nullptr});
        hovered_card=nullptr;
        is_dragging_card=false;
    }
    void Card_group_handler::refresh_hand_layout()const{
        const int len=hand_cards.Size();
        if(len==0) return;
        const float angle_start=(float)len*INCREMENT_ANGLE/2.0F,
                    increment_sink=SINK_RANGE/(float)len/2.0F;
        const int middle=len/2;
        for(int i=0;i<len;i++){
            //len=4         //len=3
            //middle=2      //middle=1
            //0 1 2 3       //0 1 2
            //-2 -1 0 1     //-1 0 1
            //-1 0 0 -1
            //set y
            int t = i - middle;
            if(0<=t)t=-t;
            else if(!bool(len&1))t++;
            t=(int)((float)t*1.7F);
            hand_cards[i]->SetTargetY(SINK_START+increment_sink*t);
            //set angle
            hand_cards[i]->SetTargetAngle(angle_start-((float)i+0.5F)*INCREMENT_ANGLE);
        }
        //adjust y & set x
        constexpr float half_width=(float)WINDOW_WIDTH/2.0F;
        switch (len)
        {
        case 1:
            hand_cards[0]->SetTargetX(half_width);
            break;
        case 2:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.47F);
            hand_cards[1]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.53F);
            break;
        case 3:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.9F);
            hand_cards[1]->SetTargetX(half_width);
            hand_cards[2]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.9F);
            hand_cards[0]->MoveTargetY(20.0F*Setting::SCALE);
            hand_cards[2]->MoveTargetY(20.0F*Setting::SCALE);
            break;
        case 4:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.36F);
            hand_cards[1]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.46F);
            hand_cards[2]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.46F);
            hand_cards[3]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.36F);
            hand_cards[1]->MoveTargetY(-10.0F*Setting::SCALE);
            hand_cards[2]->MoveTargetY(-10.0F*Setting::SCALE);
            break;
        case 5:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.7F);
            hand_cards[1]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.9F);
            hand_cards[2]->SetTargetX(half_width);
            hand_cards[3]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.9F);
            hand_cards[4]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.7F);
            hand_cards[0]->MoveTargetY(25.0F*Setting::SCALE);
            hand_cards[2]->MoveTargetY(-10.0F*Setting::SCALE);
            hand_cards[4]->MoveTargetY(25.0F*Setting::SCALE);
            break;
        case 6:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*2.1F);
            hand_cards[1]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.3F);
            hand_cards[2]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.43F);
            hand_cards[3]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.43F);
            hand_cards[4]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.3F);
            hand_cards[5]->SetTargetX(half_width+Cards::IMG_WIDTH_S*2.1F);
            hand_cards[0]->MoveTargetY(10.0F*Setting::SCALE);
            hand_cards[5]->MoveTargetY(10.0F*Setting::SCALE);
            break;
        case 7:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*2.4F);
            hand_cards[1]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.7F);
            hand_cards[2]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.9F);
            hand_cards[3]->SetTargetX(half_width);
            hand_cards[4]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.9F);
            hand_cards[5]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.7F);
            hand_cards[6]->SetTargetX(half_width+Cards::IMG_WIDTH_S*2.4F);
            hand_cards[0]->MoveTargetY(25.0F*Setting::SCALE);
            hand_cards[1]->MoveTargetY(18.0F*Setting::SCALE);
            hand_cards[3]->MoveTargetY(-6.0F*Setting::SCALE);
            hand_cards[5]->MoveTargetY(18.0F*Setting::SCALE);
            hand_cards[6]->MoveTargetY(25.0F*Setting::SCALE);
            break;
        case 8:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*2.5F);
            hand_cards[1]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.82F);
            hand_cards[2]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.1F);
            hand_cards[3]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.38F);
            hand_cards[4]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.38F);
            hand_cards[5]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.1F);
            hand_cards[6]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.77F);
            hand_cards[7]->SetTargetX(half_width+Cards::IMG_WIDTH_S*2.5F);
            hand_cards[1]->MoveTargetY(10.0F*Setting::SCALE);
            hand_cards[6]->MoveTargetY(10.0F*Setting::SCALE);
            for(const auto&it:hand_cards) it->SetTargetDrawScale(0.7125F);
            break;
        case 9:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*2.8F);
            hand_cards[1]->SetTargetX(half_width-Cards::IMG_WIDTH_S*2.2F);
            hand_cards[2]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.53F);
            hand_cards[3]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.8F);
            hand_cards[4]->SetTargetX(half_width);
            hand_cards[5]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.8F);
            hand_cards[6]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.53F);
            hand_cards[7]->SetTargetX(half_width+Cards::IMG_WIDTH_S*2.2F);
            hand_cards[8]->SetTargetX(half_width+Cards::IMG_WIDTH_S*2.8F);
            hand_cards[1]->MoveTargetY(22.0F*Setting::SCALE);
            hand_cards[2]->MoveTargetY(18.0F*Setting::SCALE);
            hand_cards[3]->MoveTargetY(12.0F*Setting::SCALE);
            hand_cards[5]->MoveTargetY(12.0F*Setting::SCALE);
            hand_cards[6]->MoveTargetY(18.0F*Setting::SCALE);
            hand_cards[7]->MoveTargetY(22.0F*Setting::SCALE);
            for(const auto&it:hand_cards) it->SetTargetDrawScale(0.67499995F);
            break;
        case 10:
            hand_cards[0]->SetTargetX(half_width-Cards::IMG_WIDTH_S*2.9F);
            hand_cards[1]->SetTargetX(half_width-Cards::IMG_WIDTH_S*2.4F);
            hand_cards[2]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.8F);
            hand_cards[3]->SetTargetX(half_width-Cards::IMG_WIDTH_S*1.1F);
            hand_cards[4]->SetTargetX(half_width-Cards::IMG_WIDTH_S*0.4F);
            hand_cards[5]->SetTargetX(half_width+Cards::IMG_WIDTH_S*0.4F);
            hand_cards[6]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.1F);
            hand_cards[7]->SetTargetX(half_width+Cards::IMG_WIDTH_S*1.8F);
            hand_cards[8]->SetTargetX(half_width+Cards::IMG_WIDTH_S*2.4F);
            hand_cards[9]->SetTargetX(half_width+Cards::IMG_WIDTH_S*2.9F);
            hand_cards[1]->MoveTargetY(20.0F*Setting::SCALE);
            hand_cards[2]->MoveTargetY(17.0F*Setting::SCALE);
            hand_cards[3]->MoveTargetY(12.0F*Setting::SCALE);
            hand_cards[4]->MoveTargetY(5.0F*Setting::SCALE);
            hand_cards[5]->MoveTargetY(5.0F*Setting::SCALE);
            hand_cards[6]->MoveTargetY(12.0F*Setting::SCALE);
            hand_cards[7]->MoveTargetY(17.0F*Setting::SCALE);
            hand_cards[8]->MoveTargetY(20.0F*Setting::SCALE);
            for(const auto&it:hand_cards) it->SetTargetDrawScale(0.63750005F);
            break;
        default:
            LOG_ERROR("There are too many cards in hand.");
            break;
        }
        //adjust scale
        if(len<8){
            for(const auto&it:hand_cards) it->SetTargetDrawScale(0.75F);
        }
        //...
    }
    void Card_group_handler::update(const std::shared_ptr<Action::Action_group_handler> &action_group_handler){
        if(single_target){
            update_targeting();
        }else{
            const bool last_in=in_drop_zone;
            in_drop_zone=CARD_DROP_START_Y<(float)input_y&&(float)input_y<CARD_DROP_END_Y;
            if(!last_in&&in_drop_zone&&is_dragging_card){
                hovered_card->Flash(0x87ceeb00);//color.sky
            }
            if(is_dragging_card&&in_drop_zone){
                pass_hesitation_line=true;
            }
            if(is_dragging_card&&(float)input_y<LOW_LOW_LINE&&pass_hesitation_line){
                pass_hesitation_line=false;
                this->release_card();
            }
            //check hover card
            if(hovered_card==nullptr){
                hovered_card=hand_cards.GetHoveredCard();
                if(hovered_card!=nullptr){
                    hovered_card->SetTargetY(HOVER_CARD_Y_POSITION);
                    hovered_card->SetY(HOVER_CARD_Y_POSITION);
                    hovered_card->SetAngle(0.0F);
                    hovered_card->Hover();
                    hand_card_push();
                }
            }
            //check if start to drag card
            if(just_l&&hovered_card!=nullptr&&!is_dragging_card){
                hover_start_line=(float)input_y*START_LINE_OFFSET;
                is_dragging_card=true;
                pass_hesitation_line=false;
                hovered_card->SetTargetDrawScale(0.7F);
            }else if(is_dragging_card){
                if(!just_r){
                    if(just_l){
                        if(in_drop_zone&&hovered_card->target!=Target::enemy&&hovered_card->target!=Target::self_and_enemy){//and canuse
                            play_card(action_group_handler);
                        }else{
                            release_card();
                        }
                    }else{
                        hovered_card->SetTargetX(input_x);
                        hovered_card->SetTargetY(input_y);
                        if(in_drop_zone&&(hovered_card->target==Target::enemy||hovered_card->target==Target::self_and_enemy)){
                            single_target=true;
                            arrowX=input_x;
                            arrowY=input_y;
                            Cursor::SetVisible(false);
                            refresh_hand_layout();
                            hovered_card->SetTargetX(WINDOW_WIDTH/2.0F);
                            hovered_card->SetTargetY(Card::Cards::IMG_HEIGHT*0.75F/2.5F);
                        }
                    }
                }else{
                    release_card();
                }
            }

        }
    }
    void Card_group_handler::prepare_for_battle(const std::shared_ptr<RUtil::Random> &rng){
        this->m_discard.Clear();
        this->hand_cards.Clear();
        this->exhaust_pile.Clear();
        this->draw_pile=this->master_deck;
        draw_pile.ShuffleWithRng(rng);
        hovered_card=nullptr;
        single_target=in_drop_zone=pass_hesitation_line=is_dragging_card=false;
        hovered_monster=nullptr;
    }
    void Card_group_handler::render_hand(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        if(hovered_card!=nullptr){
            hovered_card->render_hovered_shadow(r2);
        }
        hand_cards.render(r2);
        if(single_target)
            render_targeting(r2);
    }
    void Card_group_handler::render_targeting(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        if(hovered_monster==nullptr){
            r2->SetColor(-1);
        }else{
            r2->SetColor(ARROW_COLOR,1.0F);
        }
        //control point
        const float cp_x=hovered_card->GetX()-(arrowX-hovered_card->GetX())/4.0F,
                    cp_y=arrowY+(arrowY-hovered_card->GetY())/2.0F;
        const glm::vec2 ctr_pt{cp_x,cp_y};
        //hover -> arrow
        const glm::vec2 start{hovered_card->GetX(),hovered_card->GetY()},end{arrowX,arrowY};
        float rad=7.0F*Setting::SCALE;
        glm::vec2 last_pt{ctr_pt},now_pt;
        for(int i=0;i<19;i++){//draw block
            rad+=0.4F*Setting::SCALE;
            now_pt=RUtil::Math::BezierQuadratic(start,ctr_pt,end,(float)i/20.0F);
            r2->draw(reticleBlock_img, now_pt.x-64.0F, now_pt.y-64.0F, 128.0F, 128.0F, RUtil::Math::GetDegress(now_pt-last_pt)-90.0F, 64.0F, 64.0F, rad/18.0F, rad/18.0F);
        }
        //draw arrow
        r2->draw(reticleArrow_img, arrowX-128.0F, arrowY-128.0F, 256.0F, 256.0F, RUtil::Math::GetDegress(now_pt-last_pt)-90.0F, 128.0F, 128.0F);
    }
    void Card_group_handler::update_targeting(){
        hovered_monster=nullptr;
        //monster check
        //for(monst:monster_group)....
        if(!just_r&&(float)input_y>LOW_LOW_LINE&&(float)input_y>hover_start_line - 400.0F*Setting::SCALE){//check if height is in range, release if not.
            if(just_l){
                if(hovered_monster!=nullptr){
                    single_target=false;
                    Cursor::SetVisible(true);
                    hovered_monster=nullptr;
                }
            }
        }else{
            release_card();
            single_target=false;
            Cursor::SetVisible(true);
            hovered_monster=nullptr;
        }

        if(single_target){
            arrowX=RUtil::Math::varlerp(arrowX,(float)input_x,20.0F,UI_THRESHOLD);
            arrowY=RUtil::Math::varlerp(arrowY,(float)input_y,20.0F,UI_THRESHOLD);
        }
    }
    void Card_group_handler::hand_card_push()const{
        const int len=hand_cards.Size();
        if(len>1){
            const int pos=hand_cards.GetCardPos(hovered_card);
            if(pos!=-1){
                const float push=len==2?0.2F:(len==3||len==4?0.27F:0.4F);
                float j=push;
                //right
                for(int i=pos+1;i<len;i++){
                    hand_cards[i]->MoveTargetX(Cards::IMG_WIDTH_S*j);
                    j*=0.25F;
                }
                j=push;
                //left
                for(int i=pos-1;0<=i;i--){
                    hand_cards[i]->MoveTargetX(-Cards::IMG_WIDTH_S*j);
                    j*=0.25F;
                }
            }else{
                LOG_ERROR("Hovered card not in hand, How?");
            }
        }
    }
    void Card_group_handler::add_to_master_deck(std::shared_ptr<Cards> &&card){
        master_deck.AddTop(std::move(card));
    }
    const std::shared_ptr<Draw::ReTexture>&Card_group_handler::reticleBlock_img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/reticleBlock.png"),&Card_group_handler::reticleArrow_img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/reticleArrow.png");
    const int &Card_group_handler::input_x=RUtil::Game_Input::getX(),&Card_group_handler::input_y=RUtil::Game_Input::getY();
    const bool &Card_group_handler::just_r=RUtil::Game_Input::just_clicked_R(),&Card_group_handler::just_l=RUtil::Game_Input::just_clicked();
    
}
