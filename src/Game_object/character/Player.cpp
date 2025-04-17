#include "Game_object/character/Player.hpp"
#include "RUtil/Random.hpp"
namespace Character{
    Player::Player():Characters(Setting::WINDOW_WIDTH*0.5F+WIDTH_OFFSET, Setting::WINDOW_HEIGHT*0.5F, WIDTH, HIGHT),player_type(PlayerType::Ironclad) 
    {
        max_energy=3;
        current_energy=3;
        max_HP=80;
        current_HP=80;
        current_Block=0;
        setPosition(glm::vec2(Setting::WINDOW_WIDTH*0.5F+WIDTH_OFFSET,Setting::WINDOW_HEIGHT*0.5F+HEIGHT_OFFSET),WIDTH);
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

