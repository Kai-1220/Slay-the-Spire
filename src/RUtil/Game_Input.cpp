#include <SDL_mouse.h>

#include "RUtil/Game_Input.hpp"
#include "WindowSize.hpp"

#include "Util/Input.hpp"
#include "Util/Time.hpp"

namespace RUtil{
    void Game_Input::update(){
        SDL_GetMouseState(&x, &y);
        if(x>(int)WINDOW_WIDTH) x=(int)WINDOW_WIDTH;
        else if(x<0) x=0;
        y=WINDOW_HEIGHT-y;
        if(y>(int)WINDOW_HEIGHT) y=(int)WINDOW_HEIGHT;
        else if(y<1) y=1;
        MS.isMouseDown=Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB);
        MS.isMouseDown_R=Util::Input::IsKeyPressed(Util::Keycode::MOUSE_RB);
        MS.justMouseClicked=Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB);
        MS.justMouseClicked_R=Util::Input::IsKeyDown(Util::Keycode::MOUSE_RB);
        MS.justMouseReleased=Util::Input::IsKeyUp(Util::Keycode::MOUSE_LB);
        MS.justMouseReleased_R=Util::Input::IsKeyUp(Util::Keycode::MOUSE_RB);
        MS.isScrollDown=Util::Input::IfScroll()&&Util::Input::GetScrollDistance().y<0;
        MS.isScrollUp=Util::Input::IfScroll()&&Util::Input::GetScrollDistance().y>0;
        delta_time_s=Util::Time::GetDeltaTimeMs()/1000;
    }
    int Game_Input::x=0,Game_Input::y=0;
    Game_Input::MouseState Game_Input::MS;
    float Game_Input::delta_time_s=0.0F;
}