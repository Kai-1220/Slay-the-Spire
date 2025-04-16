#pragma once

#include <vector>

#include "Game_object/map/Legend_item.hpp"

//fwd decl
namespace Room{
    enum class Room_type;
}

namespace Map{
class Legend
{
public:
    Legend();
    ~Legend()=default;
    void update(const float map_a,bool on_top);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void hide_instantly(){legend_a=0.0F;for(auto&it:items) it.unhovered();}
    const bool &get_hovered_hb_ref(Room::Room_type room_type)const;
private:
    std::vector<Legend_item> items;
    float legend_a;
    static const std::vector<std::shared_ptr<Draw::Text_layout>> &s_vec_text;
    static const std::shared_ptr<Draw::ReTexture> &event,&merchant,&treasure,&rest,&enemy,&elite;
    static const std::shared_ptr<Draw::ReTexture> &legend_img;
};
}
