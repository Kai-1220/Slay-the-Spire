// #include "App.hpp"
#include "InitScreen.hpp"
#include <SDL_image.h>
#include <iostream>
#include "Core/Context.hpp"
#include "RUtil/Game_Input.hpp"
//the include below this line is test
#include "Draw/Draw_2D.hpp"//test_Draw_2D
#include "draw_test.hpp"
#include "Game_object/card/Red/Strike_red.hpp"
#include "RUtil/Atlas_Reader.hpp"
#include "Util/Input.hpp"
#include "Game_object/dungeon/Dungeon_manager.hpp"
#include "Cursor.hpp"
#include "Game_object/dungeon/Dungeon_BottomScene.hpp"

#include "Game_object/map/Map_generator.hpp"
#include "Game_object/map/Map_node.hpp"
#include "RUtil/All_Image.hpp"
int main(int, char**) {
    srand(static_cast<unsigned int>(time(0)));//set the rand seed,it will affect the entire program.
    auto context = Core::Context::GetInstance();
    RUtil::All_Image::InitImage();
    context->SetWindowIcon(RESOURCE_DIR"/Image/assets/icon.png");
    SDL_ShowCursor(SDL_DISABLE);

    std::shared_ptr<Draw::Draw_2D> Draw2D =std::make_shared<Draw::Draw_2D>() ;
    
    
    auto ttt=std::make_shared<Object::Dungeon_manager>();
    
    // printf("OK");
    // auto tye_draw=RUtil::Atlas_Reader(RESOURCE_DIR"/Image/cardui/cardui.atlas");
    // auto tty=tye_draw.Find_Atlas_Region("1024/frame_power_rare");
    // auto tte=std::make_shared<Card::Red::Strike_red>();
    InitScreen initScreen;
    // Object::Dungeon_BottomScene BottomScene;
    Cursor cursor;
    // testfun(context);
    // float rot=90.0F;
    // auto random_generator = std::make_shared<RUtil::Random>(rand());
    // auto map_nodes = Map::Map_generator::Get_Map(720, 500, 6, random_generator);
    // auto dungeon_map = std::make_shared<Map::Dungeon_map>();
    while (!context->GetExit()) {
        RUtil::Game_Input::update();
        Draw2D->begin();
        initScreen.draw(Draw2D);
        // ttt->update();
        // Draw2D->begin();
        // Draw2D->SetColor(Util::Colors::RED);
        // dungeon_map->render(Draw2D, 0);
        // ttt->render(Draw2D);

        //test BottomScene;
        // BottomScene.render(Draw2D);

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
