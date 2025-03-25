#include "Game_object/card/Card_group_handler.hpp"
namespace Card{
    Card_group_handler::Card_group_handler(){

    }
    void Card_group_handler::refresh_hand_layout(){
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
            LOG_ERROR("Card is too many.");
            break;
        }
        //adjust scale
        if(len<8){
            for(const auto&it:hand_cards) it->SetTargetDrawScale(0.75F);
        }
        //...
    }
}
