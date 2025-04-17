#include"Game_object/map/Dungeon_map.hpp"
#include"Game_object/map/Map_node.hpp"
#include"RUtil/ColorValuesOnly.hpp"

namespace Map{
    Dungeon_map::Dungeon_map(const float &screen_offsetY,const bool &on_top):boss_hitbox(400.0F*Setting::SCALE,360.0F*Setting::SCALE),screen_offsetY(screen_offsetY),on_top(on_top){
        map_a=map_target_a=1.0F;
        map_mid_pos = MAP_Y * 16.0F - 1380.0F * Setting::SCALE;
        map_offsetY = map_mid_pos - 120.0F * Setting::SCALE;
        boss_node_color_rgb=Map_node::NOT_TAKEN_COLOR;
    }
    void Dungeon_map::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetColor(RUtil::Colors::WHITE,map_a);
        r2->draw(map_top, 0.0F, H + screen_offsetY + map_offsetY, (float)Setting::WINDOW_WIDTH, 1080.0F * Setting::SCALE);
        r2->draw(map_mid, 0.0F, screen_offsetY + map_offsetY, (float)Setting::WINDOW_WIDTH, 1080.0F * Setting::SCALE);
        r2->draw(map_bottom, 0.0F, -map_mid_pos +screen_offsetY + map_offsetY + 1.0F, (float)Setting::WINDOW_WIDTH, 1080.0F * Setting::SCALE);
        r2->draw(map_blend, 0.0F, screen_offsetY+ map_offsetY + 800.0F * Setting::SCALE, (float)Setting::WINDOW_WIDTH, BLEND_H);
        r2->draw(map_blend, 0.0F, screen_offsetY+ map_offsetY - 220.0F * Setting::SCALE, (float)Setting::WINDOW_WIDTH, BLEND_H);
        legend.render(r2);
    }
    // void Dungeon_map::show() {
    //     map_target_a = 1.0F;
    //     map_mid_pos = MAP_Y * 16.0F - 1380.0F * Setting::SCALE;
    //     map_offsetY = map_mid_pos - 120.0F * Setting::SCALE;
    // }
    // void Dungeon_map::hide(){
    //     map_target_a = 0.0F;
    // }
    void Dungeon_map::hide_instantly(){
        map_target_a=map_a=0.0F;
        legend.hide_instantly();
    }
    void Dungeon_map::update(){
        this->legend.update(map_a,on_top);
        map_a=RUtil::Math::fadelerp(map_a,map_target_a);
        if(on_top){//check boos hitbox
            boss_hitbox.move((float)Setting::WINDOW_WIDTH/2.0F, screen_offsetY + map_offsetY + BOSS_OFFSET_Y + BOSS_L/2.0F);
            boss_hitbox.update();
            // if(boss_hitbox.ClickStarted())

        }
        if(on_top&&(boss_hitbox.Hovered()||at_boss)){
            boss_node_color_rgb=Map_node::AVAILABLE_COLOR;
        }else{
            boss_node_color_rgb=RUtil::Math::color_lerp_rgb(boss_node_color_rgb,Map_node::NOT_TAKEN_COLOR,RUtil::Game_Input::delta_time()*8.0F);
        }
    }
    const std::shared_ptr<Draw::ReTexture> &Dungeon_map::map_top=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/mapTop.png"),&Dungeon_map::map_mid=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/mapMid.png"),&Dungeon_map::map_bottom=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/mapBot.png"),&Dungeon_map::map_blend=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/mapBlend.png");
}