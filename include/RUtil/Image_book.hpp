#ifndef RUTIL_IMAGE_BOOK_HPP
#define RUTIL_IMAGE_BOOK_HPP
#include"pch.hpp"
#include "Util/AssetStore.hpp"
#include "Draw/ReTexture.hpp"
namespace RUtil{
// Store Texture
class Image_book
{
public:
    Image_book(){};
    static std::shared_ptr<Image_book> GetBook();
    std::shared_ptr<Draw::ReTexture> GetTexture(const std::string &path);
private:
    
    static std::shared_ptr<Image_book> s_Book;
    static Util::AssetStore<std::shared_ptr<Draw::ReTexture>> s_Store;
};
}

#endif