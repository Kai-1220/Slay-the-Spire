#include "TheApp.hpp"
#include "Game_object/card/red/Strike_red.hpp"
#include "Core/Context.hpp"
TheApp::TheApp(){
    seed=std::random_device()();
    random_package.SetAllSeed(seed);
    m_dungeon=std::make_shared<Dungeon::Dungeons>(m_dungeon_shared,random_package,seed);
    m_InitScreen=std::make_shared<InitScreen>();
    for(int i=0;i<6;i++)//for test
        m_dungeon_shared.card_group_handler.add_to_master_deck(std::make_shared<Card::Red::Strike_red>());
}
void TheApp::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
    //assume that now in the room
    // switch (m_InitScreen->GetCurrentState()) {
    // case InitScreen::State::INIT:
    //     m_InitScreen->draw(r2);
    //     break;
    // case  InitScreen::State::STSRT_GAME:
        m_dungeon->render(r2);
    //     break;
    // default:
    //     break;
    // }
}
void TheApp::update(){
    // switch (m_InitScreen->GetCurrentState()) {
    // case  InitScreen::State::STSRT_GAME:
        m_dungeon->update();
    //     break;
    // case InitScreen::State::END:
    //     Core::Context::GetInstance()->SetExit(true);
    //     break;
    // default:
    //     break;
    // }
    
}