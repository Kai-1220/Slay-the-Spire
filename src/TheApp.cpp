#include "TheApp.hpp"

TheApp::TheApp(){
    m_dungeon=std::make_shared<Dungeon::Dungeons>();
}
void TheApp::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
    //assume that now in the room
    m_dungeon->render(r2);
}
void TheApp::update(){
    m_dungeon->update(card_group_handler,action_group_handler);
}