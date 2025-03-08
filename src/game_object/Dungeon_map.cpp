#include"game_object/Dungeon_map.hpp"
namespace Object{
    Dungeon_map::Dungeon_map(){
        std::shared_ptr<RUtil::Image_book> book=RUtil::Image_book::GetBook();
        map_top=book->GetTexture(RESOURCE_DIR"/image/map/mapTop.png");
        map_mid=book->GetTexture(RESOURCE_DIR"/image/map/mapMid.png");
        map_bottom=book->GetTexture(RESOURCE_DIR"/image/map/mapBot.png");
        map_blend=book->GetTexture(RESOURCE_DIR"/image/map/mapBlend.png");
    }
    void Dungeon_map::render(std::shared_ptr<Draw::Draw_2D> r2){
        
    }
}