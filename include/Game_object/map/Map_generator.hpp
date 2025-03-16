#ifndef GAME_OBJECT_MAP_GENERATOR_MAP
#define GAME_OBJECT_MAP_GENERATOR_MAP
#include "RUtil/Random.hpp"
#include "Map_node.hpp"

namespace Map{
class Map_generator
{
public:
    Map_generator()=delete;~Map_generator()=delete;Map_generator(const Map_generator &) = delete;Map_generator(Map_generator &&) = delete;Map_generator &operator=(const Map_generator &) = delete;Map_generator &operator=(Map_generator &&) = delete;
    static std::vector<std::vector<Map_node>> Get_Map(int height,int width,int density,const std::shared_ptr<RUtil::Random> &rng);
private:
    static void Path_create(std::vector<std::vector<Map_node>>&map,int height,int width,int density,const std::shared_ptr<RUtil::Random> &rng);
};
}
#endif