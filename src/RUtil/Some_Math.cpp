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
            if(std::abs(start-target)<SNAP_THRESHOLD) start=target; //||start>target
        }
        return start;
    }
    float Math::interpolation_exp10(float start,float target,float a){
        return start+(target-start)*interpolation_exp(2.0F,10.0F,a);
    }
    float Math::interpolation_fade(float start,float target,float a){
        //from gdx
        return start+(target-start)*std::clamp(a * a * a * (a * (a * 6.0F - 15.0F) + 10.0F),0.0F,1.0F);
    }
    int Math::StrToInt(const std::string &str){
        int re=0;
        for(const char &c:str)
            if('0'<=c&&c<='9'){
                re=(re<<1)+(re<<3);
                re+=c^48;
            }
        return re;
    }
    int Math::GetIntLength(int x){
        return x<100000?(x<100?(x<10?1:2):(x<1000?3:4)):(x<10000000?(x<1000000?6:7):(x<100000000?8:(x<1000000000?9:10)));
        //        5               [12]        [34]                       [67]                    [8 9 10]
    }
    float Math::GetRandomFloat(float min,float max){
        return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
    }
    float Math::GetRadian(const glm::vec2 &v){
        return glm::acos(glm::dot(glm::normalize(v),glm::vec2(1.0F,0.0F)));
    }

}