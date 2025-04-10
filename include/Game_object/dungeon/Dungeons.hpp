#ifndef GAME_OBJECT_DUNGEON_DUNGEONS
#define GAME_OBJECT_DUNGEON_DUNGEONS
#include "Game_object/dungeon/Dungeon_manager.hpp"
#include "Game_object/effect/Effect_group.hpp"
#include "Game_object/scene/Scenes.hpp"
#include "Game_object/map/Map_generator.hpp"
#include "RUtil/Random.hpp"
namespace Dungeon{
class Dungeons
{
public:
    Dungeons();
    virtual ~Dungeons()=default;
    void update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,const std::shared_ptr<Action::Action_group_handler>&action_group_handler,const RUtil::Random_package &random_package);
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
protected:
    Uint32 fade_color=0x1e0f0aff;
private:
    Dungeon_manager m_dungeon_manager;
    std::shared_ptr<Effect::Effect_group> effs,top_effs;
    std::shared_ptr<Scene::Scenes> scene;
    std::vector<std::vector<std::shared_ptr<Map::Map_node>>> m_map;
    std::shared_ptr<RUtil::Random> map_rng;
    std::shared_ptr<Map::Map_node> m_current_node;
};
}
#endif