#ifndef GAME_OBJECT_DUNGEON_DUNGEON_MANAGER
#define GAME_OBJECT_DUNGEON_DUNGEON_MANAGER
#include "Game_object/dungeon/Dungeon_screen.hpp"
#include "Game_object/interface/Is_screen.hpp"
#include "Game_object/card/Card_group_handler.hpp"
namespace Dungeon{
    //This class will auto update
    class Dungeon_manager
    {
    public:
        Dungeon_manager();
        ~Dungeon_manager()=default;
        void update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,const std::shared_ptr<Action::Action_group_handler>&action_group_handler,const std::shared_ptr<Effect::Effect_group>&effs,const std::shared_ptr<Effect::Effect_group>&top_effs);
        void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
        void set_display_map(const std::vector<std::vector<std::shared_ptr<Map::Map_node>>>&map)const{m_dungeon_screen->set_display_map(map);}
    private:
        Interface::Screen Current_screen;
        std::shared_ptr<Dungeon::Dungeon_screen> m_dungeon_screen;
    };
}
#endif