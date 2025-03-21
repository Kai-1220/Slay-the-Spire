#include "RUtil/Random.hpp"
namespace RUtil{
    Random::Random(long long int seed){
        SetState(seed);
        counter=0;
    }
    Random::Random(long long int seed,int counter):counter(counter){
        SetState(seed);
        for(int i=0;i<counter;i++) NextLong();
    }
    int Random::NextInt(int min,int max){
        return min+NextInt(max-min);
    }
    int Random::NextInt(int range){
        return NextInt()%range;//分布が偏るだろうが、それは問題ないと思う。
    }
    int Random::NextInt(){
        counter++;
        return static_cast<int>(NextLong()&0x7fffffff);
    }
    bool Random::Nextboolean(){
        counter++;
        return static_cast<bool>(NextLong()&1L);
    }
    //from com.badlogic.gdx.math.randomxs128
    void Random::SetState(long long int seed){
        seed0=seed==0L?(1LL<<63):seed;
        seed1=murmurHash3(seed0);
    }
    long long int Random::murmurHash3(unsigned long long int x){
        x ^= x >> 33;
        x *= -49064778989728563LL;
        x ^= x >> 33;
        x *= -4265267296055464877LL;
        x ^= x >> 33;
        return (long long int)x;
    }
    long long int Random::NextLong(){
        long long int  s1 = this->seed0,s0=this->seed1;
        this->seed0 = s0;
        s1 ^= s1 << 23;
        return (this->seed1 = s1 ^ s0 ^ (((unsigned long long int )s1) >> 17) ^ ((unsigned long long int )s0) >> 26) + s0;
    }
}