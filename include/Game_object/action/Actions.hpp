#ifndef GAME_OBJECT_ACTION_ACTIONS
#define GAME_OBJECT_ACTION_ACTIONS
#include "Game_object/card/Card_group_handler.hpp"
#include "Game_object/character/Characters.hpp"
namespace Action{
class Action_group;
class Actions
{
public:
    virtual ~Actions()=default;
    virtual void update(const std::shared_ptr<Card::Card_group_handler>&c_handler,const Action_group* action_group)=0;
    bool IsDone()const{return is_done;}
protected:
    void TimeGo();
    bool is_done;
    float duration;
    const float &DT=RUtil::Game_Input::delta_time();
    constexpr static float ACTION_DUR_XFAST=0.1F,ACTION_DUR_FASTER = 0.2F,ACTION_DUR_FAST = 0.25F,ACTION_DUR_MED = 0.5F,ACTION_DUR_LONG = 1.0F,ACTION_DUR_XLONG = 1.5F;
};   
}
#endif