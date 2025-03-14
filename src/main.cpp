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
    auto test_layout=std::make_shared<Draw::Text_layout>("1234[R]1323Test[R][G][B][W][C][P][T][S]");
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
        test_layout->render(Draw2D,0,0);
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
