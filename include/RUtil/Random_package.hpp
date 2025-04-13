#pragma once

#include "RUtil/Random.hpp"
#include <memory>

namespace RUtil{
struct Random_package
{
    std::shared_ptr<Random> map_rng;//Used for generating the map.
    std::shared_ptr<Random> monster_rng;//Used for designing mosters in rooms.
    std::shared_ptr<Random> card_reward_rng;//Used for generating card rewards.

    //The following RNGs are refreshed when entering each room.
    
    std::shared_ptr<Random> card_get_rng;//Used for generating temporacy battle-only cards.
    std::shared_ptr<Random> card_shuffle_rng;//Used for shuffling the cards.
    std::shared_ptr<Random> monster_hp_rng;//Used for randomizing the monster HP.
    std::shared_ptr<Random> monster_ai_rng;//Used for randomizing the monster AI.
    Random_package(){
        map_rng=nullptr;
        monster_rng=nullptr;
        card_reward_rng=nullptr;
        card_get_rng=nullptr;
        card_shuffle_rng=nullptr;
        monster_hp_rng=nullptr;
        monster_ai_rng=nullptr;
    }
    void SetAllSeed(unsigned long long int seed){
        map_rng=std::make_shared<Random>(seed);
        monster_rng=std::make_shared<Random>(seed);
        card_reward_rng=std::make_shared<Random>(seed);
        card_get_rng=std::make_shared<Random>(seed);
        card_shuffle_rng=std::make_shared<Random>(seed);
        monster_hp_rng=std::make_shared<Random>(seed);
        monster_ai_rng=std::make_shared<Random>(seed);
    }
    void ResetRoomRNGs(unsigned long long int seed)const{
        card_get_rng->SetNewSeed(seed);
        card_shuffle_rng->SetNewSeed(seed);
        monster_hp_rng->SetNewSeed(seed);
        monster_ai_rng->SetNewSeed(seed);
    }
};
}