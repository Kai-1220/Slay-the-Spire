#include "Game_object/character/Monster/FatGremlin.hpp"
#include "RUtil/Random.hpp"
namespace Monster{
    FatGremlin::FatGremlin()
    {
        setHP(40,44);
        setBlock(0);
        m_damage=12;
        pos.x=WINDOW_WIDTH*0.5F+550.0F*Setting::SCALE;  
        pos.y=WINDOW_HEIGHT*0.5F-300.0F*Setting::SCALE;
    }
    
    void FatGremlin::render(const std::shared_ptr<Draw::Draw_2D> &r2)
    {
        r2->SetColor(-1);
        r2->draw(img,pos.x,pos.y,270.0F*Setting::SCALE*1.5,136.37F*Setting::SCALE*3); 
    }
    const std::shared_ptr<Draw::ReTexture> &FatGremlin::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Gremlins/Fat-gremlin-pretty.png");

}

