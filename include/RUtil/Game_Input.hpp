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
    static const int& getX(){return x;}
    static const int& getY(){return y;}
    static const bool &is_down(){return MS.isMouseDown;}
    static const bool &is_down_R(){return MS.isMouseDown_R;}
    static bool is_scroll_down(){return MS.isScrollDown;}
    static bool is_scroll_up(){return MS.isScrollUp;}
    static const bool &just_clicked(){return MS.justMouseClicked;}
    static const bool &just_clicked_R(){return MS.justMouseClicked_R;}
    static const bool &just_released(){return MS.justMouseReleased;}
    static const bool &just_released_R(){return MS.justMouseReleased_R;}
    static const float &delta_time(){return delta_time_s;}
private:
    struct MouseState {
        bool isMouseDown = false;
        bool isMouseDown_R = false;
        bool justMouseClicked = false;
        bool justMouseClicked_R = false;
        bool justMouseReleased = false;
        bool justMouseReleased_R = false;
        bool isScrollUp = false;
        bool isScrollDown = false;
    };
    static int x,y;
    static MouseState MS;
    static float delta_time_s;// I don't know if it's good to put it here
};
}
#endif