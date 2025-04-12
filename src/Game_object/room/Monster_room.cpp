#include "Game_object/room/Monster_room.hpp"
#include "RUtil/Image_book.hpp"
#include "Game_object/character/Monster/TempMonster.hpp"
#include "Game_object/action/Draw_card_action.hpp"
namespace Room{
Monster_room::Monster_room():Rooms(Room_type::Monster){
    m_wait_timer=0.0F;
}
void Monster_room::init_room(){
    this->m_monster=std::make_shared<Monster::TempMonster>();
    m_wait_timer=0.1F;
}
void Monster_room::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
    //moster render
    //player render
}
void Monster_room::update(const std::shared_ptr<Action::Action_group_handler> &action_group_handler,const std::shared_ptr<Card::Card_group_handler> &card_group_handler,const RUtil::Random_package &random_package){
    //remember monster update
    action_group_handler->update(card_group_handler,random_package);
    if(m_wait_timer<=0.0F){//Loop until end turn. //Idle also loop here.
        action_group_handler->update(card_group_handler,random_package);
        card_group_handler->update(action_group_handler);
        
    }else{
        if(action_group_handler->is_nothing_to_do()){
            m_wait_timer-=RUtil::Game_Input::delta_time();
        }else{
            action_group_handler->update(card_group_handler,random_package);
        }
        if(m_wait_timer<=0.0F){//ready to start turn
            //battle start effect
            //energy
            action_group_handler->AddActionBot(std::make_shared<Action::Draw_card_action>(5));//temporary 5
            //end turn button
            //panel?
        }
    }

}

const std::shared_ptr<Draw::ReTexture> &Monster_room::IMG=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/monster.png"),
                                       &Monster_room::IMG_O=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/monsterOutline.png");
}