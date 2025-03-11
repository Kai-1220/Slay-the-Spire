#ifndef RUTIL_SOME_MATH_HPP
#define RUTIL_SOME_MATH_HPP
#include "Util/Time.hpp"
#include "WindowSize.hpp"
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

    template <typename T>
    static T lerp(T a, T b, T t);
    static float interpolation_exp(float v, float p, float a);
    static float fadelerp(float start,float target);
    static float scrolllerp(float start,float target);
    static float interpolation_exp10(float start,float target,float a);
private:
    static constexpr float SNAP_THRESHOLD=1.0F*Setting::SCALE;
};
}
#endif