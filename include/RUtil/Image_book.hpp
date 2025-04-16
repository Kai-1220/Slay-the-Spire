#pragma once

#include <functional>
#include <map>
#include <string>

//fwd decl
namespace Draw{
    class ReTexture;
}

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
            //use std::map instead of unordered_map to ensure value references remain vaild.
            //std::unordered_map may rehash and re-locate elements, invalidating references.
            std::map<std::string, T> m_Map;
    };
};
}