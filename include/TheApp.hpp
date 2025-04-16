#ifndef THEAPP_HPP
#define THEAPP_HPP
#include "Game_object/dungeon/Dungeons.hpp"
#include "Game_object/dungeon/Dungeon_shared.hpp"
#include "InitScreen.hpp"
class TheApp {
public:
    TheApp();
    ~TheApp()=default;
    void update();
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
private:
    std::shared_ptr<InitScreen> m_InitScreen;
    Dungeon::Dungeon_shared m_dungeon_shared;
    std::shared_ptr<Dungeon::Dungeons> m_dungeon;
    RUtil::Random_package random_package;
    unsigned long long int seed;
};

#endif
