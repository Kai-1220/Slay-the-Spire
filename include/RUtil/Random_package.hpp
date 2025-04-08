#ifndef RUTIL_RANDOM_PACKAGE
#define RUTIL_RANDOM_PACKAGE
#include "RUtil/Random.hpp"
#include <memory>
namespace RUtil{
struct Random_package
{
    std::shared_ptr<Random> card_battle_rng,
                            map_rng,
                            card_reward_rng;

};
}
#endif