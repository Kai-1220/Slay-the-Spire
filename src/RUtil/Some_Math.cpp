#include "RUtil/Some_Math.hpp"
namespace RUtil{
    template <typename T>
    T Math::lerp(T a, T b, T t) {
        return a + t * (b - a);
    }
    float Math::fadelerp(float start,float target){
        if(start!=target){
            start=lerp(start,target,Util::Time::GetDeltaTimeMs()*12.0F);
            if(std::abs(start-target)<0.01F||start>target) start=target;
        }
        return start;
    }
}