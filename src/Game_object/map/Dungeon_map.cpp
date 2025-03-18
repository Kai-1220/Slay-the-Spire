#include"Game_object/map/Dungeon_map.hpp"
#include "RUtil/Some_Math.hpp"
#include <iostream>
namespace Map{
    Dungeon_map::Dungeon_map(){
        map_top=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/mapTop.png");
        map_mid=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/mapMid.png");
        map_bottom=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/mapBot.png");
        map_blend=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/mapBlend.png");
        map_legend=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/legend2.png");
        map_legends_items.push_back(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/event.png"));
        map_legends_items.push_back(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/shop.png"));
        map_legends_items.push_back(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/chest.png"));
        map_legends_items.push_back(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/rest.png"));
        map_legends_items.push_back(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/monster.png"));
        map_legends_items.push_back(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/elite.png"));
        map_a=1.0F;
        map_mid_pos = MAP_Y * 16.0F - 1380.0F * Setting::SCALE;
        map_offsetY = map_mid_pos - 120.0F * Setting::SCALE;
    }
    void Dungeon_map::render(const std::shared_ptr<Draw::Draw_2D> &r2,float screen_offsetY)const{
        printf("%f\n",map_offsetY);
        r2->SetColor(Util::Colors::WHITE,map_a);
        r2->draw(map_top, 0.0F, H + screen_offsetY + map_offsetY, (float)WINDOW_WIDTH, 1080.0F * Setting::SCALE);
        r2->draw(map_mid, 0.0F, screen_offsetY + map_offsetY, (float)WINDOW_WIDTH, 1080.0F * Setting::SCALE);
        r2->draw(map_bottom, 0.0F, -map_mid_pos +screen_offsetY + map_offsetY + 1.0F, (float)WINDOW_WIDTH, 1080.0F * Setting::SCALE);
        r2->draw(map_blend, 0.0F, screen_offsetY+ map_offsetY + 800.0F * Setting::SCALE, (float)WINDOW_WIDTH, BLEND_H);
        r2->draw(map_blend, 0.0F, screen_offsetY+ map_offsetY - 220.0F * Setting::SCALE, (float)WINDOW_WIDTH, BLEND_H);
        
        r2->draw(map_legend, legend_pos.x, legend_pos.y, 512*Setting::SCALE, 800*Setting::SCALE);
        r2->SetColor(Util::Colors::BLACK);
        for (int i = 0; i < map_legends_items.size(); i++) {
            r2->draw(map_legends_items[i], legend_pos.x+legend_item_offset, legend_pos.y+legend_item_offset+legend_item_offset/2*(map_legends_items.size()-i), legend_item_size.x, legend_item_size.y);
        }
    }
    void Dungeon_map::show() {
        map_target_a = 1.0F;
        map_mid_pos = MAP_Y * 16.0F - 1380.0F * Setting::SCALE;
        map_offsetY = map_mid_pos - 120.0F * Setting::SCALE;
    }
    void Dungeon_map::hide(){
        map_target_a = 0.0F;
    }
    void Dungeon_map::update(){
        map_a=RUtil::Math::fadelerp(map_a,map_target_a);
    }
}