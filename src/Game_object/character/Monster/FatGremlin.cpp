#include "Game_object/character/Monster/FatGremlin.hpp"
#include "RUtil/Random.hpp"
#include <iostream>
namespace Monster{
    FatGremlin::FatGremlin()
    {
        setHP(40,44);
        setBlock(0);
        m_damage=12;
        setPosition(glm::vec2(WINDOW_WIDTH*0.5F+WIDTH_OFFSET,WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
        setHPBarWidth(WIDTH*0.8F);
    }
    
    void FatGremlin::render(const std::shared_ptr<Draw::Draw_2D> &r2) const 
    {
        r2->SetColor(-1);
        r2->draw(img,getPosition().x,getPosition().y,WIDTH,HIGHT); 
        render_HP(r2);
    }
    const std::shared_ptr<Draw::ReTexture> &FatGremlin::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Gremlins/Fat-gremlin-pretty.png");

}

