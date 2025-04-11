#include "Game_object/character/Monster/JawWorm.hpp"
#include "RUtil/Random.hpp"
namespace Monster{
    JawWorm::JawWorm()
    {
        setHP(40,44);
        setBlock(0);
        m_damage=12;
        setPosition(glm::vec2(WINDOW_WIDTH*0.5F+WIDTH_OFFSET,WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
        setHPBarWidth(WIDTH);
    }
    
    void JawWorm::render(const std::shared_ptr<Draw::Draw_2D> &r2)
    {
        update();
        r2->SetColor(-1);
        r2->draw(img,getPosition().x,getPosition().y,WIDTH,HIGHT);  
        render_HP(r2);

    }
    const std::shared_ptr<Draw::ReTexture> &JawWorm::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Jaw Worm/Jaw-worm-pretty.png");
    
}

