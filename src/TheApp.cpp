#include "TheApp.hpp"
#include "Game_object/card/red/Strike_red.hpp"
#include "Core/Context.hpp"
TheApp::TheApp(){
    seed=std::random_device()();
    random_package.SetAllSeed(seed);
    m_dungeon=std::make_shared<Dungeon::Dungeons>(random_package,seed);
    m_InitScreen=std::make_shared<InitScreen>();
    card_group_handler=std::make_shared<Card::Card_group_handler>();
    action_group_handler=std::make_shared<Action::Action_group_handler>();
    for(int i=0;i<6;i++)//for test
        card_group_handler->add_to_master_deck(std::make_shared<Card::Red::Strike_red>());
}
void TheApp::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
    switch (m_CurrentState) {
    case  AppStatus::State::INIT:
        m_InitScreen->render(r2);
        break;
    case  AppStatus::State::PLAYING:
        m_dungeon->render(r2);
        break;
    default:
        break;
    }
}
void TheApp::update(){
    switch (m_CurrentState) {
    case AppStatus::State::INIT:
        m_InitScreen->update();
        if(m_InitScreen->GetCurrentState()!=AppStatus::State::INIT){
            m_CurrentState=m_InitScreen->GetCurrentState();
        }
        break;
    case AppStatus::State::PLAYING:
        m_dungeon->update(card_group_handler,action_group_handler,random_package);
        break;
    case AppStatus::State::END:
        Core::Context::GetInstance()->SetExit(true);
        break;
    default:
        break;
    }
    
}