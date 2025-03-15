#ifndef RUTIL_RANDOM_HPP
#define RUTIL_RANDOM_HPP
namespace RUtil{
class Random{
public:
    Random(long long int seed);
    Random(long long int seed,int counter);
    ~Random()=default;
    int NextInt();
    int NextInt(int range);
    bool Nextboolean();
    int GetCounter()const{return counter;}
private:
    int counter;

    long long int seed0,seed1;
    //from com.badlogic.gdx.math.randomxs128
    static long long int murmurHash3(unsigned long long int x);
    void SetState(long long int seed);
    long long int NextLong();
};
}
#endif