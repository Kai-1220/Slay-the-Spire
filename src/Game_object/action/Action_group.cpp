#include "Game_object/action/Action_group.hpp"
#include "Game_object/action/Actions.hpp"
namespace Action
{
    std::shared_ptr<Action::Actions> Action_group::PopTop(){
        auto&& temp=std::move(box.back());
        box.pop_back();
        return temp;
    }
    void Action_group::AddTop(std::shared_ptr<Actions>&&action){box.emplace_back(std::move(action));}
    void Action_group::AddBot(std::shared_ptr<Actions>&&action){box.emplace_front(std::move(action));}
    void Action_group::AddTop(const std::shared_ptr<Actions>&action){box.emplace_back(action);}
    void Action_group::AddBot(const std::shared_ptr<Actions>&action){box.emplace_front(action);}  
} // namespace Action
