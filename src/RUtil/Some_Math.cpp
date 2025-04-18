#include <algorithm>

#include "RUtil/Some_Math.hpp"
#include "RUtil/Game_Input.hpp"
#include "WindowSize.hpp"

namespace RUtil{
    inline float Math::interpolation_exp(float v, float p, float a){
        const float m=(float)std::pow((double)v,(double)(-p));
        const float s=1.0F/(1.0F-m);
        return a <= 0.5F ? ((float)std::pow((double)v, (double)(p * (a * 2.0F - 1.0F))) - m) * s / 2.0F : (2.0F - ((float)std::pow((double)v, (double)(-p * (a * 2.0F - 1.0F))) - m) * s) / 2.0F;
    }
    inline float Math::interpolation_expin(float v, float p, float a){
        //v^p(a-1)  ->  [v^-p, 1]     //(v^p(a-1) - v^-p) / (1 - v^-p)  ->  [0,1]
        const float m=(float)std::pow((double)v,(double)(-p));
        return ((float)std::pow((double)v,(double)(p*(a-1.0F)))-m)/(1.0F-m);
    }
    inline float Math::interpolation_powout(int p, float a){
        return (float)std::pow(a-1,p)*(bool(p&1)?1:-1)+1;
    }
    float Math::fadelerp(float start,float target){
        if(start!=target){
            start=Apply(start,target,RUtil::Game_Input::delta_time()*12.0F);
            if(std::abs(start-target)<0.01F) start=target;
        }
        return start;
    }
    float Math::varlerp(float start,const float target,const float speed,const float threshold){
        if(start!=target){
            start=Apply(start,target,RUtil::Game_Input::delta_time()*speed);
            if(std::abs(start-target)<threshold) start=target;
        }
        return start;
    }
    float Math::scrolllerp(float start,float target){
        if(start!=target){
            start=Apply(start,target,RUtil::Game_Input::delta_time()*10.0F);
            if(std::abs(start-target)<Setting::SCALE) start=target;
        }
        return start;
    }
    float Math::interpolation_exp10(float start,float target,float a){
        return start+(target-start)*interpolation_exp(2.0F,10.0F,a);
    }
    float Math::interpolation_exp10in(float start,float target,float a){
        return Apply(start,target,interpolation_expin(2.0F,10.0F,a));
    }
    float Math::interpolation_powout2(float start,float target,float a){
        return start+(target-start)*interpolation_powout(2,a);
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
    glm::vec2 Math::BezierQuadratic(const glm::vec2 p0,const glm::vec2 p1,const glm::vec2 p2,const float t){
        const float tt=1.0F-t;
        return p0*tt*tt+p1*2.0F*tt*t+p2*t*t;
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
    float Math::BounceOut(float t){
        if (t < 0.36363637F) {
            return 7.5625F * t * t;
        } else if (t < 0.72727275F) {
            t -= 0.54545456F;
            return 7.5625F * t * t + 0.75F;
        } else if (t < 0.90909094F) {
            t -= 0.8181818F;
            return 7.5625F * t * t + 0.9375F;
        } else {
            t -= 0.95454544F;
            return 7.5625F * t * t + 0.984375F;
        }
    }
    float Math::BounceIn(float t){return 1.0F-BounceOut(t);}
    Uint32 Math::color_lerp_rgb(Uint32 start,Uint32 target,float t){
        Uint32 re=0;
        for(int i=1;i<4;i++)
            re|=Apply(start>>(i<<3)&0xff,target>>(i<<3)&0xff,t)<<(i<<3);
        return re;
    }
}