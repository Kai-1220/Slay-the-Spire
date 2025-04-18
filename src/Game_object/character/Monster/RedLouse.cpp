#include "Game_object/character/Monster/RedLouse.hpp"
#include "RUtil/Random.hpp"
namespace Monster{
    RedLouse::RedLouse():Monsters(Setting::WINDOW_WIDTH*0.5F, Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET, WIDTH, HIGHT)
    {
        setHP(8,12);
        setBlock(0);
        m_damage=int(RUtil::Random::GetRandomFloat(MIN_DAMAGE,MAX_DAMAGE));
        setPosition(glm::vec2(Setting::WINDOW_WIDTH*0.5F,Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
        setHPBarWidth(WIDTH*0.8F);
    }
    
    void RedLouse::render(const std::shared_ptr<Draw::Draw_2D> &r2) const 
    {
        r2->SetColor(-1);
        r2->draw(img,getPosition().x,getPosition().y,WIDTH,HIGHT);
        render_HP(r2);
    }
    const std::shared_ptr<Draw::ReTexture> &RedLouse::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Louses/Louse-red-pretty.png");

}

