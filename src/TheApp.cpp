#include "TheApp.hpp"
#include "Game_object/card/red/Strike_red.hpp"
TheApp::TheApp(){
    seed=std::random_device()();
    random_package.SetAllSeed(seed);
    m_dungeon=std::make_shared<Dungeon::Dungeons>(random_package,seed);
    card_group_handler=std::make_shared<Card::Card_group_handler>();
    action_group_handler=std::make_shared<Action::Action_group_handler>();
    for(int i=0;i<6;i++)//for test
        card_group_handler->add_to_master_deck(std::make_shared<Card::Red::Strike_red>());
}
void TheApp::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
    //assume that now in the room
    m_dungeon->render(r2);
}
void TheApp::update(){
    m_dungeon->update(card_group_handler,action_group_handler,random_package);
}