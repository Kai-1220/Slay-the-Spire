#include "RUtil/Some_Math.hpp"
#include <math.h>
#include "RUtil/Game_Input.hpp"
namespace RUtil{
    template <typename T>
    T Math::lerp(T a, T b, T t) {
        return a + t * (b - a);
    }

    float Math::interpolation_exp(float v, float p, float a){
        float m=(float)std::pow((double)v,(double)(-p)),
              s=1.0F/(1.0F-m);
        return a <= 0.5F ? ((float)std::pow((double)v, (double)(p * (a * 2.0F - 1.0F))) - m) * s / 2.0F : (2.0F - ((float)std::pow((double)v, (double)(-p * (a * 2.0F - 1.0F))) - m) * s) / 2.0F;
    }
    float Math::fadelerp(float start,float target){
        if(start!=target){
            start=lerp(start,target,RUtil::Game_Input::delta_time()*12.0F);
            if(std::abs(start-target)<0.01F||start>target) start=target;
        }
        return start;
    }
    float Math::scrolllerp(float start,float target){
        if(start!=target){
            start=lerp(start,target,RUtil::Game_Input::delta_time()*10.0F);
            if(std::abs(start-target)<SNAP_THRESHOLD||start>target) start=target;
        }
        return start;
    }
    float Math::interpolation_exp10(float start,float target,float a){
        return start+(target-start)*interpolation_exp(2.0F,10.0F,a);
    }
}