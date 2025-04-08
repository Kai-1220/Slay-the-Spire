#include "Game_object/dungeon/Dungeons.hpp"
#include "Game_object/scene/Bottom_scene.hpp"
namespace Dungeon{
    Dungeons::Dungeons(){
        effs=std::make_shared<Effect::Effect_group>();
        top_effs=std::make_shared<Effect::Effect_group>();
        scene=std::make_shared<Scene::Bottom_scene>();
        scene->next_room();
        map_rng=std::make_shared<RUtil::Random>(time(0));
        m_map=Map::Map_generator::Get_Map(15,7,6,map_rng);
        m_dungeon_manager.set_display_map(m_map);
        m_current_node=nullptr;
    }
    void Dungeons::update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,const std::shared_ptr<Action::Action_group_handler>&action_group_handler,const RUtil::Random_package &random_package){
        effs->update();
        top_effs->update();
        if(m_current_node!=nullptr) m_current_node->GetRoom()->update(action_group_handler,card_group_handler,random_package);
        m_dungeon_manager.update(card_group_handler,action_group_handler,effs,top_effs);
    }
    void Dungeons::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        scene->render(r2);
        if(m_current_node!=nullptr) m_current_node->GetRoom()->render(r2);
        effs->render(r2);
        m_dungeon_manager.render(r2);
        top_effs->render(r2);
    }
}