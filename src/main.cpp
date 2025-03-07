// #include "App.hpp"
#include "InitScreen.hpp"
#include <SDL_image.h>
#include <iostream>
#include "Core/Context.hpp"
#include "Draw/Draw_2D.hpp"//test_Draw_2D
#include "Util/Input.hpp"
int main(int, char**) {
    auto context = Core::Context::GetInstance();
    context->SetWindowIcon(RESOURCE_DIR"/Image/assets/icon.png");
    SDL_ShowCursor(SDL_DISABLE);
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


    std::shared_ptr<Draw::Draw_2D> Draw2D =std::make_shared<Draw::Draw_2D>() ;
    
    // std::shared_ptr<Draw::ReTexture> test_image=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/Start_screen/title6.png");
    //Draw::Image_Region test_region(test_image,2,61,639,550);
    std::shared_ptr<Draw::ReTexture> test_image=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/cards/cards2.png");
    printf("OK");
    

    InitScreen initScreen;
    // draw_test(test_image->GetReTextureId(),context);
    while (!context->GetExit()) {
        // the_test.begin();
        // the_test.draw(test_image,0,WINDOW_HEIGHT-100,100,100);
        // the_test.end();
        
        
        initScreen.draw(Draw2D);
        Draw2D->draw(std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/cursor/gold2.png"),
            Util::Input::GetCursorPosition().x+WINDOW_WIDTH/2-25,Util::Input::GetCursorPosition().y+WINDOW_HEIGHT/2-25,50,50);
        Draw2D->end();
        context->Update();     
        if(initScreen.GetCurrentState()==InitScreen::State::END){
            context->SetExit(true);
        } 
    }
    

    return 0;
}
