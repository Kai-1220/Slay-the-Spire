#include "RUtil/Image_book.hpp"
namespace RUtil{
    std::shared_ptr<Draw::ReTexture> Image_book::GetTexture(const std::string &path){
        return s_Store.Get(path);
    }
    Util::AssetStore<std::shared_ptr<Draw::ReTexture>> Image_book::s_Store([](const std::string&path){return std::make_shared<Draw::ReTexture>(path);});
}