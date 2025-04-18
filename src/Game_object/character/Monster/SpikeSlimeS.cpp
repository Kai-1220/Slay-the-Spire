#include "Game_object/character/Monster/SpikeSlimeS.hpp"
#include "RUtil/Random.hpp"
namespace Monster{
    SpikeSlimeS::SpikeSlimeS():Monsters(Setting::WINDOW_WIDTH*0.5F, Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET, WIDTH, HIGHT)
    {
        setHP(MIN_HP,MAX_HP);
        setBlock(0);
        m_damage=DAMAGE;
        setPosition(glm::vec2(Setting::WINDOW_WIDTH*0.5F,Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
        setHPBarWidth(WIDTH*0.8F);
    }
    
    void SpikeSlimeS::render(const std::shared_ptr<Draw::Draw_2D> &r2) const 
    {
        r2->SetColor(-1);
        r2->draw(img,getPosition().x,getPosition().y,WIDTH,HIGHT);
        render_HP(r2);
    }
    const std::shared_ptr<Draw::ReTexture> &SpikeSlimeS::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Spike Slime/Spike-slime-l-pretty.png");

}

