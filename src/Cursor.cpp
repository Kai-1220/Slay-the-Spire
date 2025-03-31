#include "Cursor.hpp"
static constexpr float OFFSET=Setting::SCALE*24.0F;

void Cursor::SetVisible(bool is_visible){Cursor::is_visible=is_visible;}

void Cursor::Draw(const std::shared_ptr<Draw::Draw_2D> &Draw2D){
    if(!is_visible) return;
    Draw2D->SetColor(Util::Colors::WHITE);
    if(RUtil::Game_Input::is_down()){
        // Draw2D->draw(Texture,
        //     Util::Input::GetCursorPosition().x+WINDOW_WIDTH/2,Util::Input::GetCursorPosition().y+WINDOW_HEIGHT/2-height,width,height,
        //     15,width/2,height/2);
        Draw2D->draw(Texture, (float)input_x-32.0F+OFFSET, (float)input_y-32.0F-OFFSET, 64.0F, 64.0F, 6.0F, 32.0F, 32.0F, Setting::SCALE, Setting::SCALE);
    }
    else{
        // Draw2D->draw(Texture,
        //     Util::Input::GetCursorPosition().x+WINDOW_WIDTH/2,Util::Input::GetCursorPosition().y+WINDOW_HEIGHT/2-height,width,height);
        Draw2D->draw(Texture, (float)input_x-32.0F+OFFSET, (float)input_y-32.0F-OFFSET, 64.0F, 64.0F, 0.0F, 32.0F, 32.0F, Setting::SCALE, Setting::SCALE);
    }
}
const std::shared_ptr<Draw::ReTexture> &Cursor::Texture=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/cursor/gold2.png");
const int&Cursor::input_x=RUtil::Game_Input::getX(),&Cursor::input_y=RUtil::Game_Input::getY();
bool Cursor::is_visible=true;