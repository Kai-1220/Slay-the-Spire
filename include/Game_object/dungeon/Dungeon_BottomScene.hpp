#ifndef GAME_OBJECT_DUNGEON_DUNGEON_BUTTONSCENE
#define GAME_OBJECT_DUNGEON_DUNGEON_BUTTONSCENE
#include "pch.hpp"
#include "WindowSize.hpp"
#include "RUtil/Image_book.hpp"
#include "Draw/ReTexture.hpp"
#include "Draw/Draw_2D.hpp"
#include "WindowSize.hpp"

namespace Object{
    class Dungeon_BottomScene
    {
    public:
        Dungeon_BottomScene();
        ~Dungeon_BottomScene()=default;
        void update();
        void render(std::shared_ptr<Draw::Draw_2D> r2);
    private:
        std::shared_ptr<Draw::Image_Region> Background;
        std::vector<std::shared_ptr<Draw::Image_Region>> mods;
        std::shared_ptr<Draw::Image_Region> deckButton;
        std::shared_ptr<Draw::Image_Region> discardButton;
        std::shared_ptr<Draw::Image_Region> buttonL;
        std::vector<glm::vec2> mods_pos={{WINDOW_WIDTH/2-300,WINDOW_HEIGHT/2-50},{0,WINDOW_HEIGHT/2-110},{0,0}};
        std::vector<glm::vec2> mods_size={{607,423},{1920*Setting::SCALE,1136*Setting::SCALE},{1920*Setting::SCALE,1136*Setting::SCALE*0.3}};
        std::vector<std::shared_ptr<Draw::Image_Region>> layers;
        std::vector<std::shared_ptr<Draw::Image_Region>> layersd;
        glm::vec2 layerPos={150,130};
        glm::vec2 layerSize={128*0.8,128*0.8};
    };
}
#endif