#ifndef THEAPP_HPP
#define THEAPP_HPP
#include "Game_object/dungeon/Dungeons.hpp"
#include "InitScreen.hpp"
#include "AppStatus.hpp"
class TheApp {
public:
    TheApp();
    ~TheApp()=default;
    void update();
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
private:
    std::shared_ptr<InitScreen> m_InitScreen;
    std::shared_ptr<Action::Action_group_handler> action_group_handler;
    std::shared_ptr<Card::Card_group_handler> card_group_handler;
    std::shared_ptr<Dungeon::Dungeons> m_dungeon;
    RUtil::Random_package random_package;
    unsigned long long int seed;
    AppStatus::State m_CurrentState=AppStatus::State::INIT;
};

#endif
