#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Util/Image.hpp"
#include "Draw/Draw_2D.hpp"
#include "Util/Renderer.hpp"
#include "Util/Input.hpp"
#include "WindowSize.hpp"
#include "RUtil/Image_book.hpp"

class Cursor{
public:
    Cursor();
    ~Cursor()=default;
    std::shared_ptr<Draw::ReTexture> GetTexture();
    glm::vec2 GetPosition();
    int GetWidth();
    int GetHeight();
    void Draw(std::shared_ptr<Draw::Draw_2D> Draw2D);
private:
    std::shared_ptr<Draw::ReTexture> Texture;
    const int width=50,height=50;
};

#endif