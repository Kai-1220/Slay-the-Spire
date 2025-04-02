#ifndef GAME_OBJECT_ACTION_GROUP
#define GAME_OBJECT_ACTION_GROUP
#include <memory>
#include<list>
namespace Card{
class Card_group_handler;
}
namespace Action{
class Action_group_handler;
class Actions;
class Action_group
{
public:
    Action_group()=default;
    ~Action_group()=default;
    void AddTop(std::shared_ptr<Action::Actions>&&action);
    void AddBot(std::shared_ptr<Action::Actions>&&action);
    void AddTop(const std::shared_ptr<Action::Actions>&action);
    void AddBot(const std::shared_ptr<Action::Actions>&action);
    void update(const std::shared_ptr<Card::Card_group_handler>&c_handler,Action_group_handler*const action_group_handler);
private:
    std::list<std::shared_ptr<Action::Actions>> box;
};
}
#endif