#ifndef GAME_OBJECT_ACTION_ACTIONS
#define GAME_OBJECT_ACTION_ACTIONS
#include "Game_object/card/Card_group_handler.hpp"
#include "Game_object/action/Action_group_handler.hpp"
#include "Game_object/character/Characters.hpp"
namespace Action{
class Actions
{
public:
    virtual ~Actions()=default;
    virtual void update(const std::shared_ptr<Card::Card_group_handler>&card_group_handler,Action_group_handler*const action_group_handler,const RUtil::Random_package &random_package)=0;
    bool IsDone()const{return is_done;}
protected:
    void TimeGo();
    bool is_done=false;
    float duration=0.0F;
    static const float &DT;
    constexpr static float ACTION_DUR_XFAST=0.1F,ACTION_DUR_FASTER = 0.2F,ACTION_DUR_FAST = 0.25F,ACTION_DUR_MED = 0.5F,ACTION_DUR_LONG = 1.0F,ACTION_DUR_XLONG = 1.5F;
};   
}
#endif