// #include "App.hpp"
#include "InitScreen.hpp"
#include <SDL_image.h>
#include <iostream>
#include "Core/Context.hpp"
#include "RUtil/Game_Input.hpp"
//the include below this line is test
#include "Draw/Draw_2D.hpp"//test_Draw_2D
#include "draw_test.hpp"
#include "Draw/ReText.hpp"
#include "RUtil/Image_book.hpp"
#include "Util/Input.hpp"
#include "Game_object/dungeon/Dungeon_manager.hpp"
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
    
    // std::shared_ptr<Draw::ReTexture> test_image=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title6.png");
    // std::shared_ptr<Draw::ReTexture> same_image=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title6.png");
    // std::shared_ptr<Draw::ReTexture> same_image_two=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title5.png");
    // std::shared_ptr<Draw::ReTexture> same2_image=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title6.png");
    // std::shared_ptr<Draw::ReTexture> same_image_two2=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title5.png");
    //Draw::Image_Region test_region(test_image,2,61,639,550);
    // std::shared_ptr<Draw::ReTexture> test_image=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/cards/cards2.png");
    // std::shared_ptr<Draw::ReText> text_test=std::make_shared<Draw::ReText>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf",23,"HELLO WORLD");
    // std::shared_ptr<Draw::ReText> text_test2=std::make_shared<Draw::ReText>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf",64,"HELLO WORLD",Util::Color(255,255,255));
    auto ttt=std::make_shared<Object::Dungeon_manager>();
    printf("OK");
    

    InitScreen initScreen;
    // draw_test(test_image->GetReTextureId(),context);
    // printf("\n(%d,%d),(%d,%d)\n",text_test->GetWidth(),text_test->GetHeight(),text_test2->GetWidth(),text_test2->GetHeight());
    //(180,35),(476,95)

    while (!context->GetExit()) {
        RUtil::Game_Input::update();
        initScreen.draw(Draw2D);
        ttt->update();
        Draw2D->begin();
        // Draw2D->SetColor(Util::Colors::WHITE);
        // 字體縮小測試&顏色測試
        // Draw2D->SetColor(Util::Colors::RED);
        // Draw2D->draw(text_test,0.0F,0.0F);
        // Draw2D->draw(text_test2,text_test->GetWidth(),0.0F,text_test->GetWidth(),text_test->GetHeight());
        // 字體放大測試
        // Draw2D->SetColor(Util::Colors::BLUE);
        // Draw2D->draw(text_test,0.0F,(float)text_test->GetHeight(),text_test2->GetWidth(),text_test2->GetHeight());
        // Draw2D->draw(text_test2,text_test2->GetWidth(),(float)text_test->GetHeight());
        //測試book
        // Draw2D->draw(same2_image,0,0);
        ttt->render(Draw2D);
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
