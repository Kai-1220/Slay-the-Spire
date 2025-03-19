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
#include "Cursor.hpp"
#include "Game_object/dungeon/Dungeon_BottomScene.hpp"
int main(int, char**) {
    auto context = Core::Context::GetInstance();
    context->SetWindowIcon(RESOURCE_DIR"/Image/assets/icon.png");
    SDL_ShowCursor(SDL_DISABLE);

    std::shared_ptr<Draw::Draw_2D> Draw2D =std::make_shared<Draw::Draw_2D>() ;
    
    // std::shared_ptr<Draw::ReTexture> test_image=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title6.png");
    // std::shared_ptr<Draw::ReTexture> same_image=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title6.png");
    // std::shared_ptr<Draw::ReTexture> same_image_two=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title5.png");
    // std::shared_ptr<Draw::ReTexture> same2_image=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title6.png");
    // std::shared_ptr<Draw::ReTexture> same_image_two2=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title5.png");
    //Draw::Image_Region test_region(test_image,2,61,639,550);
    // std::shared_ptr<Draw::ReTexture> test_image=std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/cards/cards2.png");
    // std::shared_ptr<Draw::ReText> text_test=std::make_shared<Draw::ReText>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf",23,"HELLO WORLD");
    // std::shared_ptr<Draw::ReText> text_test2=std::make_shared<Draw::ReText>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf",64,"龍鳳世測五",Util::Color(255,255,255));
    auto ttt=std::make_shared<Object::Dungeon_manager>();
    printf("OK");
    

    InitScreen initScreen;
    Object::Dungeon_BottomScene BottomScene;
    Cursor cursor;
    // draw_test(test_image->GetReTextureId(),context);
    while (!context->GetExit()) {
        RUtil::Game_Input::update();
        Draw2D->begin();
        // initScreen.draw(Draw2D);
        // ttt->update();
        // Draw2D->begin();
        // Draw2D->draw(rr[idx++],0,0);
        // if(idx>=rr.size()) idx=0;
        // Draw2D->SetColor(Util::Colors::WHITE);
        // 字體縮小測試&顏色測試
        // Draw2D->SetColor(Util::Colors::RED);
        // Draw2D->draw(text_test,0.0F,0.0F);
        // Draw2D->draw(text_test2,text_test->GetWidth(),0.0F,text_test->GetWidth(),text_test->GetHeight());
        // 字體放大測試
        // Draw2D->SetColor(Util::Colors::BLUE);
        // Draw2D->draw(text_test,0.0F,(float)text_test->GetHeight(),text_test2->GetWidth(),text_test2->GetHeight());
        
        //測試book
        // Draw2D->draw(same2_image,0,0);
        // ttt->render(Draw2D);

        //test BottomScene;
        BottomScene.render(Draw2D);

        cursor.Draw(Draw2D);
        
        Draw2D->end();
        context->Update();
        if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
            context->SetExit(true);
        }
        // if(initScreen.GetCurrentState()==InitScreen::State::END){
        //     context->SetExit(true);
        // } 
    }
    

    return 0;
}
