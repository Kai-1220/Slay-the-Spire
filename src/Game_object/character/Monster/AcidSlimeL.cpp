#include "Game_object/character/Monster/AcidSlimeL.hpp"
#include "RUtil/Random.hpp"
namespace Monster{
    AcidSlimeL::AcidSlimeL():Monsters(Setting::WINDOW_WIDTH*0.5F, Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET, WIDTH, HIGHT)
    {
        setHP(65,69);
        setBlock(0);
        m_damage=16;
        setPosition(glm::vec2(Setting::WINDOW_WIDTH*0.5F,Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
        setHPBarWidth(WIDTH*0.8F);
    }
    
    void AcidSlimeL::render(const std::shared_ptr<Draw::Draw_2D> &r2) const 
    {
        r2->SetColor(-1);
        r2->draw(img,getPosition().x,getPosition().y,WIDTH,HIGHT);
        render_HP(r2);
    }
    const std::shared_ptr<Draw::ReTexture> &AcidSlimeL::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Acid Slime/Acid-slime-l-pretty.png");

}

