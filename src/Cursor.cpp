#include "Cursor.hpp"

Cursor::Cursor(){
    Texture=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/cursor/gold2.png");
    
}
std::shared_ptr<Draw::ReTexture> Cursor::GetTexture(){
    return Texture;
}
glm::vec2 Cursor::GetPosition(){
    return Util::Input::GetCursorPosition()+glm::vec2{WINDOW_WIDTH/2,WINDOW_HEIGHT/2};
}
int Cursor::GetWidth(){
    return width;
}
int Cursor::GetHeight(){
    return height;
}
void Cursor::Draw(std::shared_ptr<Draw::Draw_2D> Draw2D){
    Draw2D->SetColor(Util::Colors::WHITE);
    Draw2D->draw(Texture,
        Util::Input::GetCursorPosition().x+WINDOW_WIDTH/2,Util::Input::GetCursorPosition().y+WINDOW_HEIGHT/2-height,width,height);
}