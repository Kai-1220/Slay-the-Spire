// #include "App.hpp"
#include "InitScreen.hpp"
#include <SDL_image.h>
#include <iostream>
#include "Core/Context.hpp"
#include "RUtil/Game_Input.hpp"
//the include below this line is test
#include "Draw/Draw_2D.hpp"//test_Draw_2D
#include "draw_test.hpp"
#include "Game_object/card/Cards.hpp"
#include "RUtil/Atlas_Reader.hpp"
#include "Util/Input.hpp"
#include "Game_object/dungeon/Dungeon_manager.hpp"
#include "Cursor.hpp"
#include "Game_object/dungeon/Dungeon_BottomScene.hpp"
int main(int, char**) {
    srand(static_cast<unsigned int>(time(0)));//set the rand seed,it will affect the entire program.
    auto context = Core::Context::GetInstance();
    context->SetWindowIcon(RESOURCE_DIR"/Image/assets/icon.png");
    SDL_ShowCursor(SDL_DISABLE);

    std::shared_ptr<Draw::Draw_2D> Draw2D =std::make_shared<Draw::Draw_2D>() ;
    
    
    auto ttt=std::make_shared<Object::Dungeon_manager>();
    
    auto test_layout=std::make_shared<Draw::Text_layout>("TTT!M!GG#nG!D!T#nT!B!TT");
    test_layout->set_damage(123);
    test_layout->set_fontsize(17);
    test_layout->set_middle();
    test_layout->set_fontsize(32);
    printf("%f %f\n",test_layout->GetWidth(),test_layout->GetHeight());
    
    printf("OK");
    // auto tye_draw=RUtil::Atlas_Reader(RESOURCE_DIR"/Image/cardui/cardui.atlas");
    // auto tty=tye_draw.Find_Atlas_Region("1024/frame_power_rare");
    // auto tte=std::make_shared<Card::Cards>(Card::Name::anger,Card::Rarity::rare,Card::Type::attack,Card::Color::red);
    InitScreen initScreen;
    Object::Dungeon_BottomScene BottomScene;
    Cursor cursor;
    // draw_test(test_image->GetReTextureId(),context);
    // float rot=90.0F;
    while (!context->GetExit()) {
        RUtil::Game_Input::update();
        Draw2D->begin();
        // initScreen.draw(Draw2D);
        // ttt->update();
        // Draw2D->begin();
        // Draw2D->SetColor(Util::Colors::RED);
        
        
        // ttt->render(Draw2D);

        //test BottomScene;
        BottomScene.render(Draw2D);

        test_layout->render(Draw2D,500,WINDOW_HEIGHT);
        // ttt->render(Draw2D);
        // Draw2D->draw(tty,0,0);
        // tte->render(Draw2D);
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
