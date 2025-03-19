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
        std::vector<glm::vec2> mods_pos={{WINDOW_WIDTH/2-300,WINDOW_HEIGHT/2-50}};
        std::vector<glm::vec2> mods_size={{607,423}};

    };
}
#endif