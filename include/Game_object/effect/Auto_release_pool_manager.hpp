#pragma once

#include <vector>

namespace Effect{
class Auto_release_pool_manager
{
public:
    Auto_release_pool_manager()=delete;~Auto_release_pool_manager()=delete;Auto_release_pool_manager(const Auto_release_pool_manager &) = delete;Auto_release_pool_manager(Auto_release_pool_manager &&) = delete;Auto_release_pool_manager &operator=(const Auto_release_pool_manager &) = delete;Auto_release_pool_manager &operator=(Auto_release_pool_manager &&) = delete;
    static void JoinToAutoCheck(void(*check_function)()){check_box.emplace_back(check_function);}
    static void update();
private:
    static float timer;
    static std::vector<void(*)()> check_box;
    static constexpr float CHECK_TIME=600.0F;//10min
};
}