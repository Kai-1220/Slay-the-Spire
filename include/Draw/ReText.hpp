#ifndef DRAW_RETEXT_HPP
#define DRAW_RETEXT_HPP
#include "pch.hpp"
#include "Util/Color.hpp"
#include "Draw/ReTexture.hpp"
#include <functional>
namespace Draw {
class ReText:public ReTexture{
public:
    /**
     * @brief Load text from filepath.
     * 
     * This class is able to be converted into "Retexture" class.
     * Can't change anything after created.
     * If you want chage color or font size,
     * please use draw function in "Draw_2D"
     */
    ReText(const std::string &font, int size, const std::string &text,
        const Util::Color &color = Util::Color(255, 255, 255));
    ReText(const ReText &) = delete;
    ReText(ReText &&) = delete;

    ~ReText()=default;

    ReText &operator=(const ReText &) = delete;
    ReText &operator=(ReText &&)=delete;
private:
    // constexpr int size=64;
    
    std::unique_ptr<TTF_Font, std::function<void(TTF_Font *)>> m_Font;
};
} // namespace Core
    
#endif