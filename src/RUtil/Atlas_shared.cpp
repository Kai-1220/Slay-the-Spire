#include "RUtil/Atlas_shared.hpp"
namespace RUtil
{
std::shared_ptr<Atlas_Reader> Atlas_shared::GetAtlas(const std::string &path){
    return path==LastPath?LastAtlas:LastAtlas=s_Store.Get(LastPath=path);
}
std::shared_ptr<Draw::Atlas_Region> Atlas_shared::GetRegion(const std::string &path,const std::string &region_name){
    return path==LastPath?LastAtlas->Find_Atlas_Region(region_name):(LastAtlas=s_Store.Get(LastPath=path),LastAtlas->Find_Atlas_Region(region_name));
}
Util::AssetStore<std::shared_ptr<Atlas_Reader>> Atlas_shared::s_Store([](const std::string&path){return std::make_shared<Atlas_Reader>(path);});   
std::shared_ptr<Atlas_Reader>Atlas_shared::LastAtlas=nullptr;
std::string Atlas_shared::LastPath;
} // namespace RUtil
