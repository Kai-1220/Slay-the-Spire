// #include "App.hpp"
#include "InitScreen.hpp"
#include <SDL_image.h>
#include <iostream>
#include "Core/Context.hpp"
#include "RUtil/Game_Input.hpp"
//the include below this line is test
#include "Draw/Draw_2D.hpp"//test_Draw_2D
#include "draw_test.hpp"
#include "Draw/Text_layout.hpp"
#include "RUtil/Image_book.hpp"
#include "Util/Input.hpp"
#include "Game_object/dungeon/Dungeon_manager.hpp"
#include "Cursor.hpp"
int main(int, char**) {
    auto context = Core::Context::GetInstance();
    context->SetWindowIcon(RESOURCE_DIR"/Image/assets/icon.png");
    SDL_ShowCursor(SDL_DISABLE);

    std::shared_ptr<Draw::Draw_2D> Draw2D =std::make_shared<Draw::Draw_2D>() ;
    
    
    auto ttt=std::make_shared<Object::Dungeon_manager>();
    auto test_layout=std::make_shared<Draw::Text_layout>("TTT!M!GG#nG!D!T#nT!B!TT");
    test_layout->set_damage(123);
    test_layout->set_fontsize(10);
    test_layout->set_middle();
    test_layout->set_fontsize(32);
    printf("OK");
    

    InitScreen initScreen;
    Cursor cursor;
    // draw_test(test_image->GetReTextureId(),context);
    while (!context->GetExit()) {
        RUtil::Game_Input::update();
        Draw2D->begin();
        initScreen.draw(Draw2D);
        ttt->update();
        // Draw2D->begin();
        // Draw2D->draw(rr[idx++],0,0);
        // if(idx>=rr.size()) idx=0;
        // Draw2D->SetColor(Util::Colors::WHITE);
        test_layout->render(Draw2D,500,WINDOW_HEIGHT);
        // ttt->render(Draw2D);
        cursor.Draw(Draw2D);
        Draw2D->end();
        context->Update();
        if(initScreen.GetCurrentState()==InitScreen::State::END){
            context->SetExit(true);
        } 
    }
    

    return 0;
}
