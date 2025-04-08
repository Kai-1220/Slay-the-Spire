#ifndef RUTIL_RANDOM_HPP
#define RUTIL_RANDOM_HPP
#include<random>
namespace RUtil{
class Random{
public:
    Random(unsigned long long int seed,int counter=0);
    ~Random()=default;

    using result_type = std::mt19937::result_type;
    static constexpr auto max(){return std::mt19937::max();}
    static constexpr auto min(){return std::mt19937::min();}
    auto operator()(){counter++;return m_gen();}

    //not include max
    int NextInt(const int min,const int max){return min+NextInt(max-min);}
    int NextInt(const int range){return NextInt()%range;/*分布が偏るだろうが、それは問題ないと思う。*/}
    int NextInt(){return static_cast<int>((*this)()&0x7fffffff);}
    bool Nextboolean(){return static_cast<bool>((*this)()&1);}
    auto GetCounter()const{return counter;}

    static bool GetRandomBoolean(){return static_cast<bool>(s_gen()&1);}
    static float GetRandomFloat(const float min,const float max);
private:
    std::mt19937 m_gen;
    unsigned int counter;
    unsigned long long int seed;

    static std::mt19937 s_gen;
};
}
#endif