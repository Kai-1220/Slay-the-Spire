#ifndef GAME_OBJECT_MAP_GENERATOR_MAP
#define GAME_OBJECT_MAP_GENERATOR_MAP
#include "RUtil/Random.hpp"
#include "Map_node.hpp"

namespace Map{
class Map_generator
{
public:
    Map_generator()=delete;~Map_generator()=delete;Map_generator(const Map_generator &) = delete;Map_generator(Map_generator &&) = delete;Map_generator &operator=(const Map_generator &) = delete;Map_generator &operator=(Map_generator &&) = delete;
    static std::vector<std::vector<std::shared_ptr<Map_node>>> Get_Map(int height,int width,int density,const std::shared_ptr<RUtil::Random> &rng);
    static void SetChance(float value,Room::Room_type type);
private:
    static float s_monster_chance;
    static void AssignRoom(const std::vector<std::vector<std::shared_ptr<Map_node>>>&map);
};
}
#endif