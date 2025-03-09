#ifndef RUTIL_GAME_INPUT_HPP
#define RUTIL_GAME_INPUT_HPP
#include <SDL_events.h>
#include "config.hpp"
namespace RUtil{
//do some limit for input
class Game_Input
{
public:
    Game_Input()= delete;
    ~Game_Input()= delete;
    Game_Input(const Game_Input &) = delete;
    Game_Input(Game_Input &&) = delete;
    Game_Input &operator=(const Game_Input &) = delete;
    Game_Input &operator=(Game_Input &&) = delete;
    static void update();
private:
    static int x,y;
    static bool isMouseDown,isMouseDown_R,
                justMouseClicked,justMouseClicked_R,
                justMouseReleased,justMouseReleased_R;
};
}
#endif