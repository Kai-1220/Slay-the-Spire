#ifndef INITSCREEN_HPP
#define INITSCREEN_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Util/Text.hpp"
#include "Util/Logger.hpp"
#include "Util/GameObject.hpp"
#include "Util/Transform.hpp"
#include "Util/TransformUtils.hpp"
#include "Draw/Draw_2D.hpp"

#include "RUtil/Image_magic.hpp"

#include <SDL.h>
#include <memory>
#include <vector>
#include <iostream>
class InitScreen {
public:
    enum class State {
        INIT,
        STSRT_GAME,
        ENCYCLOPEDIA,
        STATISTICS,
        SETTINGS,
        UPDATE_CONTENT_LIST,
        END
    };
    
    InitScreen();
    ~InitScreen()=default;

    void CreateLogo();
    void CreateBackground();
    void CreateTower();
    void CreateBlackCloud(int i);
    void CreateWhiteCloud(int i);
    void CreateText(int i);
    void Create();
    void draw(std::shared_ptr<Draw::Draw_2D> Draw2D);
    State GetCurrentState() const { return m_CurrentState; }

    glm::vec2 GetTextScreenPosition(int index);


private:
    State m_CurrentState = State::INIT;

    std::vector <std::shared_ptr<RUtil::Image_magic>> InitBackgroundImg;
    std::vector <std::shared_ptr<Core::Matrices>> InitBackgroundMatrices;
    std::shared_ptr<Core::Matrices> LogoMatrices;
    std::shared_ptr<RUtil::Image_magic> LogoImg;
    std::vector <std::shared_ptr<RUtil::Image_magic>> BlackCloudImg;
    std::vector <std::shared_ptr<Core::Matrices>> BlackCloudMatrices;
    std::vector <int> BlackCloudCount;

    std::vector <std::shared_ptr<Util::Text>> TextObj;
    std::vector <std::shared_ptr<Core::Matrices>> TextMatrices;

    std::vector <std::shared_ptr<RUtil::Image_magic>> WhiteCloudImg;
    std::vector <std::shared_ptr<Core::Matrices>> WhiteCloudMatrices;
    std::vector <int> WhiteCloudCount;

    unsigned int CloudGenTime=0;

    int BlackCloudImgNum[7]={2,3,4,6,6,6,6};
    std::vector <glm::vec2> BlackCloudPos={{2, 2},{2, 2},{2, 2},{1280,429},{1244,81},{643,111},{643,12}};
    std::vector <glm::vec2> BlackCloudSize={{1299, 856},{1561,374},{1920,350},{558,176},{585,181},{599,151},{411,97}};
    glm::vec2 BlackCloudorigScale={1920.0f,1266.0f};

    int WhiteCloudImgNum[13]={3,3,4,5,5,5,6,6,6,6,6,6,6};
    std::vector <glm::vec2> WhiteCloudPos={{2, 378},{2, 1415},{2, 1083},{2, 2},{2, 642},{2, 928},{1423, 621},{643, 264},
                    {915, 788},{2, 613},{779, 607},{2, 2},{2, 818}};
    std::vector <glm::vec2> WhiteCloudSize={{1683, 1035},{1686, 581},{1519, 595},{1237, 638},{1252, 284},{1293, 372},{452, 165},
                {635, 341},{856, 216},{775, 203},{642, 179},{272, 57},{911, 186}};
    glm::vec2 WhiteCloudorigScale={1920.0f,1266.0f};

    int m_Size=50;
    std::vector <std::string> m_Text={"開始遊戲","百科大全","統計內容","設定","更新內容清單","退出"};
    std::vector <glm::vec3> m_TextPos={{-5.15f,-3.4f, -1.0f},{-5.15f,-4.4f, -1.0f},{-5.15f,-5.4f, -1.0f},{-10.8f,-6.4f, -1.0f},
                                        {-3.275f,-7.4f, -1.0f},{-10.8f,-8.4f, -1.0f}};
                                      
    std::vector <glm::vec2> TextScale={{150.0f,50.0f},{150.0f,50.0f},{150.0f,50.0f},{75.0f,50.0f},{225.0f,50.0f},{75.0f,50.0f}};
};

#endif