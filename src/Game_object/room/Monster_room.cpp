#include "Game_object/room/Monster_room.hpp"
#include "RUtil/Image_book.hpp"
#include "Game_object/character/Monster/TempMonster.hpp"
#include "Game_object/action/Draw_card_action.hpp"
#include "Game_object/dungeon/Overlay.hpp"

#include "Util/Input.hpp"//for test

namespace Room{
Monster_room::Monster_room():Rooms(Room_type::Monster){
    m_wait_timer=0.0F;
}
void Monster_room::init_room(){
    this->m_monster=std::make_shared<Monster::TempMonster>();
    this->m_acid_slime_l=std::make_shared<Monster::AcidSlimeL>();
    this->m_fat_gremlin=std::make_shared<Monster::FatGremlin>();
    this->m_jaw_worm=std::make_shared<Monster::JawWorm>();
    this->m_player=std::make_shared<Character::Player>();
    m_wait_timer=0.1F;
}
void Monster_room::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
    //moster render
    m_acid_slime_l->render(r2);
    m_fat_gremlin->render(r2);
    m_jaw_worm->render(r2);
    //player render
    m_player->render(r2);
}
void Monster_room::update(Action::Action_group_handler &action_group_handler,Card::Card_group_handler &card_group_handler,Dungeon::Overlay &overlay,const RUtil::Random_package &random_package){
    //remember monster update
    // m_fat_gremlin->hovered();
    m_fat_gremlin->update();
    m_acid_slime_l->update();
    m_jaw_worm->update();
    if(m_wait_timer<=0.0F){//Loop until end turn. //Idle also loop here.
        action_group_handler.update(card_group_handler,random_package);
        card_group_handler.update(action_group_handler);
        
        if(Util::Input::IsKeyDown(Util::Keycode::A)){//for test
            action_group_handler.AddActionTop(std::make_shared<Action::Draw_card_action>(5));
        }
        if(Util::Input::IsKeyDown(Util::Keycode::S)){//for test
            card_group_handler.discard_all();
        }
        if(Util::Input::IsKeyDown(Util::Keycode::D)){//for test
            m_acid_slime_l->damage(10);
            m_fat_gremlin->damage(10);
            m_jaw_worm->damage(10);
        }
        
    }else{
        if(action_group_handler.is_nothing_to_do()){
            m_wait_timer-=RUtil::Game_Input::delta_time();
        }else{
            action_group_handler.update(card_group_handler,random_package);
        }
        if(m_wait_timer<=0.0F){//ready to start turn
            if(/*first*/true){
                //battle start effect
                overlay.show_combat_panel();
            }
            //energy
            action_group_handler.AddActionBot(std::make_shared<Action::Draw_card_action>(5));//temporary 5
            //end turn button
            //panel?
        }
    }
}

const std::shared_ptr<Draw::ReTexture> &Monster_room::IMG=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/monster.png"),
                                       &Monster_room::IMG_O=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/map/monsterOutline.png");
}