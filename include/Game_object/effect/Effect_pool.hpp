#pragma once

#include <vector>
#include <memory>

namespace Effect{
//Caches instances of "Reusable" effect in a static box for reuse.
//If the class defines the static UseAutoRelease() function and returns true,
//the box size will be reduced after a period of inactivity.
template <typename T>
class Effect_pool{
public:
    Effect_pool()=delete;~Effect_pool()=delete;Effect_pool(const Effect_pool &) = delete;Effect_pool(Effect_pool &&) = delete;Effect_pool &operator=(const Effect_pool &) = delete;Effect_pool &operator=(Effect_pool &&) = delete;
    //Return T* for performance.
    //This Effect_pool guarantees the object will not be released,
    //as long as is_done is false.
    template <typename...Args>
    static T* GetEffect(Args&&...args);
private:
    static void CheckBoxRelease();
    //store T as shared_ptr<T> to ensure heap stability even vector reorders.
    static std::vector<std::shared_ptr<T>> box;
    static int n;
    static int curr_pos,curr_n;
    static bool in_use;
    static int constexpr MIN=2;
    static int constexpr MAX=1<<20;
};

};

#include "Effect_pool.inl"
