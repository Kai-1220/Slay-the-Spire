// #include "App.hpp"
#include "InitScreen.hpp"
#include <SDL_image.h>
#include <iostream>
#include "Core/Context.hpp"
//the include below this line is test
#include "Draw/Draw_2D.hpp"//test_Draw_2D
#include "draw_test.hpp"
#include "Draw/ReText.hpp"
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
    // std::shared_ptr<Draw::ReTexture> test_image=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/Start_screen/title6.png");
    // std::shared_ptr<Draw::Image_Region> test_region=std::make_shared<Draw::Image_Region>(test_image,2,61,639,550);
    // std::shared_ptr<Draw::ReTexture> test_image=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/cards/cards2.png");
    // std::shared_ptr<Draw::ReText> text_test=std::make_shared<Draw::ReText>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf",23,"HELLO WORLD");
    // std::shared_ptr<Draw::ReText> text_test2=std::make_shared<Draw::ReText>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf",64,"HELLO WORLD",Util::Color(255,255,255));
    
    printf("OK");
    

    InitScreen initScreen;
    // draw_test(test_image->GetReTextureId(),context);
    // printf("\n(%d,%d),(%d,%d)\n",text_test->GetWidth(),text_test->GetHeight(),text_test2->GetWidth(),text_test2->GetHeight());
    //(180,35),(476,95)
    while (!context->GetExit()) {
        initScreen.draw();
        the_test.begin();
        // the_test.SetColor(Util::Colors::WHITE);
        //字體縮小測試&顏色測試
        // the_test.SetColor(Util::Colors::RED);
        // the_test.draw(text_test,0.0F,0.0F);
        // the_test.draw(text_test2,text_test->GetWidth(),0.0F,text_test->GetWidth(),text_test->GetHeight());
        //字體放大測試
        // the_test.SetColor(Util::Colors::BLUE);
        // the_test.draw(text_test,0.0F,(float)text_test->GetHeight(),text_test2->GetWidth(),text_test2->GetHeight());
        // the_test.draw(text_test2,text_test2->GetWidth(),(float)text_test->GetHeight());
        the_test.end();
        context->Update();     
        if(initScreen.GetCurrentState()==InitScreen::State::END){
            context->SetExit(true);
        } 
    }

    return 0;
}
