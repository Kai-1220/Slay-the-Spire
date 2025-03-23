#ifndef RUTIL_ATLAS_SHARED_HPP
#define RUTIL_ATLAS_SHARED_HPP
#include "Util/AssetStore.hpp"
#include "RUtil/Atlas_Reader.hpp"
namespace RUtil
{
//This class will save the atlas that needs to be used by multiple classes.
class Atlas_shared
{
public:
    Atlas_shared()=delete;~Atlas_shared()=delete;Atlas_shared(const Atlas_shared &) = delete;Atlas_shared(Atlas_shared &&) = delete;Atlas_shared &operator=(const Atlas_shared &) = delete;Atlas_shared &operator=(Atlas_shared &&) = delete;
    static std::shared_ptr<Atlas_Reader> GetAtlas(const std::string &path);
    static std::shared_ptr<Draw::Atlas_Region> GetRegion(const std::string &path,const std::string &region_name);
private:
    static Util::AssetStore<std::shared_ptr<Atlas_Reader>> s_Store;
    static std::shared_ptr<Atlas_Reader>LastAtlas;
    static std::string LastPath;
};

} // namespace RUtil

#endif