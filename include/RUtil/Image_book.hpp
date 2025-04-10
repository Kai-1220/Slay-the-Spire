#ifndef RUTIL_IMAGE_BOOK_HPP
#define RUTIL_IMAGE_BOOK_HPP
#include "Draw/ReTexture.hpp"
#include <memory>
#include <functional>
namespace RUtil{
// Store Texture//Don't need to worry that texture is not exist.
class Image_book
{
public:
    Image_book()=delete;
    ~Image_book()=delete;
    Image_book(const Image_book &) = delete;
    Image_book(Image_book &&) = delete;
    Image_book &operator=(const Image_book &) = delete;
    Image_book &operator=(Image_book &&) = delete;
    static const std::shared_ptr<Draw::ReTexture> &GetTexture(const std::string &path);
private:
    template <typename T>
    class RStore{
        public:
            RStore(std::function<T(const std::string &)> loader);
            const T &Get(const std::string &filepath);
        private:
            std::function<T(const std::string &)> m_Loader;
            std::unordered_map<std::string, T> m_Map;
    };
};
}

#endif