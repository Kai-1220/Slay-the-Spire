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
    Image_book()=delete;
    ~Image_book()=delete;
    Image_book(const Image_book &) = delete;
    Image_book(Image_book &&) = delete;
    Image_book &operator=(const Image_book &) = delete;
    Image_book &operator=(Image_book &&) = delete;

    static std::shared_ptr<Draw::ReTexture> GetTexture(const std::string &path);
private:
    static Util::AssetStore<std::shared_ptr<Draw::ReTexture>> s_Store;
};
}

#endif