#include "RUtil/Some_Math.hpp"
#include <math.h>
#include "RUtil/Game_Input.hpp"
namespace RUtil{
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
    float Math::varlerp(float start,const float target,const float speed,const float threshold){
        if(start!=target){
            start=lerp(start,target,RUtil::Game_Input::delta_time()*speed);
            if(std::abs(start-target)<threshold||start>target) start=target;
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
    //t is[0,1)
    glm::vec2 Math::CatmullRomSpline(const std::vector<glm::vec2> &controls,const float t,const int len,const int vec_start_pos){
        float u=t*(len-3);
        int i=(t>=1.0F?(len-4):(int)u);//because the Catmull-Rom curve is defined by four points, so -3.
        u-=i;
        i+=vec_start_pos;
        const float u2=u*u,u3=u2*u;
        return controls[SimpleRangeChange(i,len)]*(-0.5F*u3+u2-0.5F*u)+controls[SimpleRangeChange(i+1,len)]*(1.5F*u3-2.5F*u2+1.0F)+controls[SimpleRangeChange(i+2,len)]*(-1.5F*u3+2.0F*u2+0.5F*u)+controls[SimpleRangeChange(i+3,len)]*(0.5F*u3-0.5F*u2);
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