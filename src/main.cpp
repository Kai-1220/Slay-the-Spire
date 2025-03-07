// #include "App.hpp"
#include "InitScreen.hpp"
#include <SDL_image.h>
#include <iostream>
#include "Core/Context.hpp"
#include "Draw/Draw_2D.hpp"//test_Draw_2D
#include "draw_test.hpp"
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


    Draw::Draw_2D the_test;
    std::shared_ptr<Draw::ReTexture> test_image=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/Start_screen/title6.png");
    std::shared_ptr<Draw::Image_Region> test_region=std::make_shared<Draw::Image_Region>(test_image,2,61,639,550);
    // std::shared_ptr<Draw::ReTexture> test_image=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/cards/cards2.png");
    printf("OK");
    

    InitScreen initScreen;
    // draw_test(test_image->GetReTextureId(),context);
    while (!context->GetExit()) {
        // the_test.begin();
        // the_test.draw(test_region,0.0F,0.0F,680.0F*((float)WINDOW_WIDTH / 1920.0F),550.0F*((float)WINDOW_WIDTH / 1920.0F));
        // the_test.end();
        initScreen.draw();
        context->Update();     
        if(initScreen.GetCurrentState()==InitScreen::State::END){
            context->SetExit(true);
        } 
    }

    return 0;
}
