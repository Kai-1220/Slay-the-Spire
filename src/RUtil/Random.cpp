#include "RUtil/Random.hpp"
namespace RUtil{
    Random::Random(unsigned long long int seed,int counter):m_gen(seed),counter(counter),seed(seed){
       m_gen.discard(counter);
    }
    float Random::GetRandomFloat(const float min,const float max){
        return min + static_cast<float>((static_cast<double>(s_gen()) - static_cast<double>(Random::min())) / (static_cast<double>(Random::max()) - static_cast<double>(Random::min()))) * (max - min);
    }
    std::mt19937 Random::s_gen{std::random_device()()};
}