#pragma once

#include "Game_object/effect/Effect_group.hpp"
#include "Game_object/action/Action_group_handler.hpp"
#include "Game_object/card/Card_group_handler.hpp"

namespace Dungeon{
struct Dungeon_shared
{
    Effect::Effect_group effs;
    Effect::Effect_group top_effs;
    Action::Action_group_handler action_group_handler;
    Card::Card_group_handler card_group_handler;
};
}