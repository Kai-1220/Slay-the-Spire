#include "Cursor.hpp"

Cursor::Cursor(){
    Texture=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/cursor/gold2.png");
    
}
std::shared_ptr<Draw::ReTexture> Cursor::GetTexture(){
    return Texture;
}
glm::vec2 Cursor::GetPosition(){
    return Util::Input::GetCursorPosition()+glm::vec2{WINDOW_WIDTH/2,WINDOW_HEIGHT/2}-glm::vec2{width/2,height/2};
}
int Cursor::GetWidth(){
    return width;
}
int Cursor::GetHeight(){
    return height;
}