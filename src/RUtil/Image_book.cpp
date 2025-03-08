#include "RUtil/Image_book.hpp"
namespace RUtil{
    std::shared_ptr<Image_book> Image_book::GetBook(){
        if(s_Book==nullptr){
            s_Book=std::make_shared<Image_book>();
        }
        return s_Book;
    }
    std::shared_ptr<Draw::ReTexture> Image_book::GetTexture(const std::string &path){
        return s_Store.Get(path);
    }
    std::shared_ptr<Image_book> Image_book::s_Book=nullptr;
    Util::AssetStore<std::shared_ptr<Draw::ReTexture>> Image_book::s_Store([](const std::string&path){return std::make_shared<Draw::ReTexture>(path);});
}