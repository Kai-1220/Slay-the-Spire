#include "Game_object/map/Legend.hpp"
#include "Game_object/room/Rooms.hpp"
#include "RUtil/Text_Vector_Reader.hpp"
#include "RUtil/ColorValuesOnly.hpp"

#include "Util/Logger.hpp"

namespace Map
{
    Legend::Legend(){
        items.emplace_back(event,s_vec_text[0],s_vec_text[1],s_vec_text[2],0);
        items.emplace_back(merchant,s_vec_text[3],s_vec_text[4],s_vec_text[5],1);
        items.emplace_back(treasure,s_vec_text[6],s_vec_text[7],s_vec_text[8],2);
        items.emplace_back(rest,s_vec_text[9],s_vec_text[10],s_vec_text[11],3);
        items.emplace_back(enemy,s_vec_text[12],s_vec_text[13],s_vec_text[14],4);
        items.emplace_back(elite,s_vec_text[15],s_vec_text[16],s_vec_text[17],5);
        legend_a=1.0F;
    }
    void Legend::update(const float map_a,bool on_top){
        if(map_a>=0.8F&&on_top){
            legend_a=RUtil::Math::fadelerp(legend_a,1.0F);
        }else{
            legend_a=RUtil::Math::fadelerp(legend_a,0.0F);
        }
        if(on_top)
            for(auto&it:items) it.update();
    }
    void Legend::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetColor(RUtil::Colors::WHITE,legend_a);
        r2->draw(legend_img, Legend_item::LEGEND_X - 256.0F, Legend_item::LEGEND_Y - 400.0F, 512.0F, 800.0F, 0.0F, 256.0F, 400.0F, Setting::SCALE, Setting::SCALE);
        for(const auto&it:items) it.render(r2,legend_a);
    }
    const bool &Legend::get_hovered_hb_ref(Room::Room_type room_type)const{
        switch (room_type)
        {
        case Room::Room_type::Event: return items[0].get_hovered_hb_ref();
        case Room::Room_type::Shop: return items[1].get_hovered_hb_ref();
        case Room::Room_type::Treasure: return items[2].get_hovered_hb_ref();
        case Room::Room_type::Rest: return items[3].get_hovered_hb_ref();
        case Room::Room_type::Monster: return items[4].get_hovered_hb_ref();
        case Room::Room_type::Elite: return items[5].get_hovered_hb_ref();
        default:
            LOG_ERROR("the room type of legend doesn't exist.");
            break;
        }
        return items[0].get_hovered_hb_ref();
    }
    const std::vector<std::shared_ptr<Draw::Text_layout>> &Legend::s_vec_text=RUtil::Text_Vector_Reader::GetTextVector(RUtil::Text_ID::Legend);
    const std::shared_ptr<Draw::ReTexture> &Legend::event=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/event.png"),&Legend::merchant=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/shop.png"),&Legend::treasure=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/chest.png"),&Legend::rest=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/rest.png"),&Legend::enemy=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/monster.png"),&Legend::elite=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/elite.png");
    const std::shared_ptr<Draw::ReTexture> &Legend::legend_img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/legend2.png");
} // namespace Map
