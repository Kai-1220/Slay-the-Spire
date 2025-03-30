#include "Game_object/room/Monster_room.hpp"
#include "RUtil/Image_book.hpp"
#include "Game_object/character/Monster/TempMonster.hpp"
namespace Room{
Monster_room::Monster_room(){
    this->is_waiting_player=false;
}
void Monster_room::init_room(){
    this->m_monster=std::make_shared<Monster::TempMonster>();
}
void Monster_room::update(const std::shared_ptr<Action::Action_group> action_group,const std::shared_ptr<Card::Card_group_handler> c_handler){
    
    //monster update
    if(is_waiting_player){
        //input update
        c_handler->update();
    }else{
        //exexuting

    }
}
const std::shared_ptr<Draw::ReTexture> &Monster_room::IMG=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/map/monster.png"),
                                       &Monster_room::IMG_O=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/map/monsterOutline.png");
}