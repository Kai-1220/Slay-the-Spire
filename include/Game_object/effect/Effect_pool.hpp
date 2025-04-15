#pragma once

#include <vector>

namespace Effect{
//Caches instances of "Reusable" effect in a static box for reuse.
//If the class defines the static UseAutoRelease() function and returns true,
//the box size will be reduced after a period of inactivity.
template <typename T>
class Effect_pool:{
public:
    Effect_pool()=delete;~Effect_pool()=delete;Effect_pool(const Effect_pool &) = delete;Effect_pool(Effect_pool &&) = delete;Effect_pool &operator=(const Effect_pool &) = delete;Effect_pool &operator=(Effect_pool &&) = delete;
    template <typename...Args>
    static const T &GetEffect(Args&&...args);
private:
    static void CheckBoxRelease();
    static std::vector<T> box;
    static int n;
    static int curr_pos,curr_n;
    static bool in_use;
    static int constexpr MIN=2;
    static int constexpr MAX=1<<20;
};

};