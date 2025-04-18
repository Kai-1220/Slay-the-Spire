#pragma once

#include <SDL_stdinc.h>//Uint
#include <glm/vec2.hpp>//vec2
#include <glm/glm.hpp>//glm::degress
#include <vector>
#include <string>

//if template not good for using,
//it will change to float.
namespace RUtil{
class Math{
public:
    Math() = delete;
    Math(const Math &) = delete;
    Math(Math &&) = delete;
    ~Math() = delete;
    Math &operator=(const Math &) = delete;
    Math &operator=(Math&&)=delete;
    template <typename... Args>
    static void Normalize(Args&... args){
        const auto Sum=(args+...);
        ((args/=Sum),...);
    }
    static float interpolation_exp(float v, float p, float a);
    static float interpolation_expin(float v, float p, float a);
    static float interpolation_powout(int p, float a);
    static float fadelerp(float start,float target);
    static float scrolllerp(float start,float target);
    static float varlerp(float start,const float target,const float speed,const float threshold);
    static Uint32 color_lerp_rgb(Uint32 start,Uint32 target,float t);
    static float interpolation_exp10(float start,float target,float a);
    static float interpolation_exp10in(float start,float target,float a);
    static float interpolation_fade(float start,float target,float a);
    static float interpolation_powout2(float start,float target,float a);
    static int StrToInt(const std::string &str);
    static int GetIntLength(int x);
    static constexpr float GetRadian(const glm::vec2 &v){return atan2f(v.y,v.x);}
    static constexpr float GetDegress(const glm::vec2 &v){return glm::degrees(atan2f(v.y,v.x));}
    static float BounceOut(float t);
    static float BounceIn(float t);
    template <typename T>
    static constexpr T Apply(const T start,const T target,const float t){return start+(target-start)*t;}
    static glm::vec2 BezierQuadratic(const glm::vec2 p0,const glm::vec2 p1,const glm::vec2 p2,const float t);
    static glm::vec2 CatmullRomSpline(const std::vector<glm::vec2> &controls,float t,const int len,const int vec_start_pos=0);
    static constexpr Uint32 GetColorUint32_RGB(int r,int g,int b){return r<<24|g<<16|b<<8;};
    static constexpr Uint32 GetColorUint32_RGB(float r,float g,float b){return static_cast<Uint32>(r*255.0F)<<24|static_cast<Uint32>(g*255.0F)<<16|static_cast<Uint32>(b*255.0F)<<8;};
    //only work if value not bigger or smaller than 2*len
    static constexpr int SimpleRangeChange(const int value,const int len){return len<=value?value-len:(value<0?value+len:value);}
};
}