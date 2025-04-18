#include "Game_object/character/Monster/AcidSlimeM.hpp"
#include "RUtil/Random.hpp"
namespace Monster{
    AcidSlimeM::AcidSlimeM():Monsters(Setting::WINDOW_WIDTH*0.5F, Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET, WIDTH, HIGHT)
    {
        setHP(28,32);
        setBlock(0);
        m_damage=10;
        setPosition(glm::vec2(Setting::WINDOW_WIDTH*0.5F,Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
        setHPBarWidth(WIDTH*0.8F);
    }
    
    void AcidSlimeM::render(const std::shared_ptr<Draw::Draw_2D> &r2) const 
    {
        r2->SetColor(-1);
        r2->draw(img,getPosition().x,getPosition().y,WIDTH,HIGHT);
        render_HP(r2);
    }
    const std::shared_ptr<Draw::ReTexture> &AcidSlimeM::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Acid Slime/Acid-slime-m-pretty.png");

}

