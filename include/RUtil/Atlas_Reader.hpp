#pragma once

#include <unordered_map>
#include <string>
#include <memory>

//fwd decl
namespace Draw{
    class Atlas_Region;
}

namespace RUtil{
class Atlas_Reader
{
public:
    Atlas_Reader(const std::string &atlas_path);
    void ChangeAtlas(const std::string &atlas_path);
    std::shared_ptr<Draw::Atlas_Region> Find_Atlas_Region(const std::string& region_name);
    ~Atlas_Reader()=default;
private:
    void BuildMap(const std::string &atlas_path);
    std::unordered_map<std::string,std::shared_ptr<Draw::Atlas_Region>> reg_map;

};
}