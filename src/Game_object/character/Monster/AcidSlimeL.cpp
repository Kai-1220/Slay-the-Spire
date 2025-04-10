#include "Game_object/character/Monster/AcidSlimeL.hpp"
#include "RUtil/Random.hpp"
namespace Monster{
    AcidSlimeL::AcidSlimeL()
    {
        setHP(65,69);
        setBlock(0);
        m_damage=16;
        pos.x=WINDOW_WIDTH*0.5F;  
        pos.y=WINDOW_HEIGHT*0.5F-300.0F*Setting::SCALE;
    }
    
    void AcidSlimeL::render(const std::shared_ptr<Draw::Draw_2D> &r2)
    {
        r2->SetColor(-1);
        r2->draw(img,pos.x,pos.y,111.24F*Setting::SCALE*2.5,159.42F*Setting::SCALE*2.5); 
    }
    const std::shared_ptr<Draw::ReTexture> &AcidSlimeL::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/monster/Acid Slime/Acid-slime-l-pretty.png");

}

