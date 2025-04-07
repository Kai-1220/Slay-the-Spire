#ifndef GAME_OBJECT_ACTION_GROUP
#define GAME_OBJECT_ACTION_GROUP
#include <memory>
#include<list>
#include "Game_object/Group_template.hpp"
namespace Card{
class Card_group_handler;
}
namespace Action{
class Actions;
class Action_group:public Template::Group_template<std::list<std::shared_ptr<Action::Actions>>>
{
public:
    Action_group()=default;
    ~Action_group() override=default;
    bool empty()const{return box.empty();}
};
}
#endif