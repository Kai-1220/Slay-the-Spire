#include "Game_object/dungeon/Dungeon_manager.hpp"
#include "Util/Logger.hpp"
namespace Dungeon{
    Dungeon_manager::Dungeon_manager(){
        Current_screen=Interface::Screen::On_map;
        m_dungeon_screen=std::make_shared<Dungeon::Dungeon_screen>();
    }
    void Dungeon_manager::update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,const std::shared_ptr<Action::Action_group_handler>&action_group_handler,const std::shared_ptr<Effect::Effect_group>&effs,const std::shared_ptr<Effect::Effect_group>&top_effs){
        switch (Current_screen) {
            case Interface::Screen::On_map:
                m_dungeon_screen->update(Current_screen);
                break;
            default:
                LOG_ERROR("Something wrong when switch screen");
                break;
        }
    }
    void Dungeon_manager::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        switch (Current_screen) {
            case Interface::Screen::On_map:
                m_dungeon_screen->render(r2);
                break;
            default:
                LOG_ERROR("Something wrong when switch screen");
                break;
        }
    }
}