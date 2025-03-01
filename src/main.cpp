// #include "App.hpp"
#include "InitScreen.hpp"
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "Core/Context.hpp"

int main(int, char**) {
    auto context = Core::Context::GetInstance();
    context->SetWindowIcon(RESOURCE_DIR"/Image/assets/icon.png");
    // App app;
    // while (!context->GetExit()) {
    //     switch (app.GetCurrentState()) {
    //         case App::State::START:
    //             app.Start();
    //             break;
    //         case App::State::UPDATE:
    //             app.Update();
    //             break;

    //         case App::State::END:
    //             app.End();
    //             context->SetExit(true);
    //             break;
    //         default:
    //             app.End();
    //             context->SetExit(true);
    //             break;
        // }

    
    //     context->Update();
    // }
    InitScreen initScreen;
    while (!context->GetExit()) {
        initScreen.draw();
        context->Update();     
        if(initScreen.GetCurrentState()==InitScreen::State::END){
            context->SetExit(true);
        }

    }

    return 0;
}
