#ifndef GAME_OBJECT_LAZY_PACKAGE
#define GAME_OBJECT_LAZY_PACKAGE
#include<memory>
namespace Card{
    class Card_group_handler;
}
namespace Action{
    class Action_group_handler;
}
namespace Effect{
    class Effect_group;
}
struct Lazy_package
{
    const std::shared_ptr<Card::Card_group_handler>&card_group_handler;
    const std::shared_ptr<Action::Action_group_handler>&action_group_handler;
    const std::shared_ptr<Effect::Effect_group>&effs;
    const std::shared_ptr<Effect::Effect_group>&top_effs;
};
#endif