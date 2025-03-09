#include "RUtil/Game_Input.hpp"
#include "Util/Input.hpp"
namespace RUtil{
    void Game_Input::update(){
        SDL_GetMouseState(&x, &y);
        if(x>(int)WINDOW_WIDTH) x=(int)WINDOW_WIDTH;
        else if(x<0) x=0;
        if(y>(int)WINDOW_HEIGHT) y=(int)WINDOW_HEIGHT;
        else if(y<1) y=1;
        isMouseDown=Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB);
        isMouseDown_R=Util::Input::IsKeyPressed(Util::Keycode::MOUSE_RB);
        justMouseClicked=Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB);
        justMouseClicked_R=Util::Input::IsKeyDown(Util::Keycode::MOUSE_RB);
        justMouseReleased=Util::Input::IsKeyUp(Util::Keycode::MOUSE_LB);
        justMouseReleased_R=Util::Input::IsKeyUp(Util::Keycode::MOUSE_RB);
    }
    int Game_Input::x=0,Game_Input::y=0;
    bool Game_Input::isMouseDown=false,Game_Input::isMouseDown_R=false,
    Game_Input::justMouseClicked=false,Game_Input::justMouseClicked_R=false,
    Game_Input::justMouseReleased=false,Game_Input::justMouseReleased_R=false;
}