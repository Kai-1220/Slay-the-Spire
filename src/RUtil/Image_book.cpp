#include "RUtil/Image_book.hpp"
#include <functional>
namespace RUtil{
    const std::shared_ptr<Draw::ReTexture> &Image_book::GetTexture(const std::string &path){
        return s_Store.Get(path);
    }
    Image_book::RStore<std::shared_ptr<Draw::ReTexture>> Image_book::s_Store([](const std::string&path){return std::make_shared<Draw::ReTexture>(path);});
    
    template <typename T>
    Image_book::RStore<T>::RStore(std::function<T(const std::string &)> loader):m_Loader(loader){}
    template <typename T>
    const T &Image_book::RStore<T>::Get(const std::string &filepath){
        auto result = m_Map.find(filepath);
        if (result != m_Map.end()) {
            return result->second;
        }
        return m_Map[filepath]=m_Loader(filepath);
    }
}