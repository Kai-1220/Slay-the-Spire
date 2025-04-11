#include "Game_object/character/Player.hpp"
#include "RUtil/Random.hpp"
#include <iostream>
namespace Character{
    Player::Player()
    {
        max_HP=80;
        current_HP=80;
        current_Block=0;
        setPosition(glm::vec2(WINDOW_WIDTH*0.5F+WIDTH_OFFSET,WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
        setHPBarWidth(WIDTH*0.5F);
    }
    
    void Player::render(const std::shared_ptr<Draw::Draw_2D> &r2) const 
    {
        r2->SetColor(-1);
        r2->draw(img,getPosition().x,getPosition().y,WIDTH,HIGHT); 
        render_HP(r2);
    }
    const std::shared_ptr<Draw::ReTexture> &Player::img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/character/Ironclad.png");

}

