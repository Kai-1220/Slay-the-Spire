#ifndef INITSCREEN_HPP
#define INITSCREEN_HPP

#include <vector>

#include "Draw/Draw_2D.hpp"
#include "Draw/ReText.hpp"
#include "AppStatus.hpp"

class InitScreen {
public:
    InitScreen();
    ~InitScreen()=default;

    void CreateLogo();
    void CreateBackground();
    void CreateTower();
    void CreateBlackCloud(int i,float posX);
    void CreateWhiteCloud(int i,float posX);
    void CreateText(int i);
    void Create();
    void render(const std::shared_ptr<Draw::Draw_2D> &Draw2D) const;
    void update();
    AppStatus::State GetCurrentState() const { return m_CurrentState; }

private:
    AppStatus::State m_CurrentState = AppStatus::State::INIT;
    std::shared_ptr<Draw::Image_Region> LogoImg;
    glm::vec2 LogoPos,LogoSize;
    std::vector <std::shared_ptr<Draw::Image_Region>> BlackCloudImg;
    std::vector <glm::vec2> BlackCloudPos;
    std::vector <int> BlackCloudCount;

    std::vector <std::shared_ptr<Draw::ReText>> TextObj;

    std::vector <std::shared_ptr<Draw::Image_Region>> WhiteCloudImg;
    std::vector <glm::vec2> WhiteCloudPos;
    std::vector <int> WhiteCloudCount;

    std::vector <std::shared_ptr<Draw::Image_Region>> InitBackgroundImg;
    std::vector <glm::vec2> ShowSize;
    std::vector <glm::vec2> ShowPos;

    unsigned int CloudGenTime=0;

    int BlackCloudImgNum[7]={2,3,4,6,6,6,6};
    std::vector <glm::vec2> BlackCloudSourcePos={{2, 2},{2, 2},{2, 2},{1280,429},{1244,81},{643,111},{643,12}};
    std::vector <glm::vec2> BlackCloudSize={{1299, 856},{1561,374},{1920,350},{558,176},{585,181},{599,151},{411,97}};
    glm::vec2 BlackCloudorigScale={1920.0f,1266.0f};

    int WhiteCloudImgNum[13]={3,3,4,5,5,5,6,6,6,6,6,6,6};
    std::vector <glm::vec2> WhiteCloudSourcePos={{2, 378},{2, 1415},{2, 1083},{2, 2},{2, 642},{2, 928},{1423, 621},{643, 264},
                    {915, 788},{2, 613},{779, 607},{2, 2},{2, 818}};
    std::vector <glm::vec2> WhiteCloudSize={{1683, 1035},{1686, 581},{1519, 595},{1237, 638},{1252, 284},{1293, 372},{452, 165},
                {635, 341},{856, 216},{775, 203},{642, 179},{272, 57},{911, 186}};
    glm::vec2 WhiteCloudorigScale={1920.0f,1266.0f};

    int m_Size=35;
    std::vector <std::string> m_Text={"開始遊戲","百科大全","統計內容","設定","更新內容清單","退出"};
    std::vector <glm::vec2> m_TextPos={{100,275},{100,240},{100,205},{100,170},{100,135},{100,100}};
                                      
    std::vector <glm::vec2> TextScale={{105.0f,35.0f},{105.0f,35.0f},{105.0f,35.0f},{52.5f,35.0f},{157.5f,35.0f},{52.5f,35.0f}};

    bool IsFadeOut=false;
    float fadeTimer,FadeColorA;
    const float fadeColor=0.0F,fadeTime=1.5F;
    AppStatus::State m_NextState=AppStatus::State::INIT;

};

#endif