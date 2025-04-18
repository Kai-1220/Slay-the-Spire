#include "Game_object/character/Monster/Cultist.hpp"
#include "RUtil/Random.hpp"
namespace Monster{
    Cultist::Cultist():Monsters(Setting::WINDOW_WIDTH*0.5F, Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET, WIDTH, HIGHT)
    {
        setHP(MIN_HP,MAX_HP);
        setBlock(0);
        m_damage=DAMAGE;
        setPosition(glm::vec2(Setting::WINDOW_WIDTH*0.5F,Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
        setHPBarWidth(WIDTH*0.8F);
    }
    
    void Cultist::render(const std::shared_ptr<Draw::Draw_2D> &r2) const 
    {
        r2->SetColor(-1);
        r2->draw(img,getPosition().x,getPosition().y,WIDTH,HIGHT);
        render_HP(r2);
    }
    const std::shared_ptr<Draw::ReTexture> &Cultist::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Cultist/Cultist-pretty.png");

}

