#include "InitScreen.hpp"
#include "WindowSize.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include <iostream>
#include <vector>

InitScreen::InitScreen() {
    // LOG_TRACE("InitScreen");
    Create();

}
void InitScreen::CreateLogo(){
    
    std::shared_ptr<RUtil::Image_magic> Logo=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title6.png");
    
    Logo->Set_small_Pos(glm::vec2{2, 61});
    Logo->Set_small_Size(glm::vec2{639, 550});
    
    Core::Matrices LogoMaterices=Util::ConvertToUniformBufferData(Util::Transform(), Logo->Get_small_Size(), 0);
    LogoMaterices.m_Model = glm::scale(LogoMaterices.m_Model, glm::vec3{glm::vec2{680.0f*WindowMultwidth*0.8,550.0f*WindowMultheight*0.85}/Logo->Get_small_Size(), 1});
    LogoMaterices.m_Model = glm::translate(LogoMaterices.m_Model, glm::vec3(0.0f, 0.0f, -1.0f));
    InitScreenImg.push_back(Logo);
    InitScreenMatrices.push_back(std::make_shared<Core::Matrices>(LogoMaterices));
}

void InitScreen::CreateBackground(){
    std::shared_ptr<RUtil::Image_magic> Background=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title.jpg");
    Background->Set_small_Pos(glm::vec2{2, 2});
    Background->Set_small_Size(glm::vec2{1920, 1469});
    Core::Matrices BackgroundMaterices=Util::ConvertToUniformBufferData(Util::Transform(), Background->Get_small_Size(), 0);
    BackgroundMaterices.m_Model = glm::scale(BackgroundMaterices.m_Model, glm::vec3{glm::vec2{1920.0f*WindowMultwidth,1469.0f*WindowMultheight*0.8}/Background->Get_small_Size(), 1});
    BackgroundMaterices.m_Model = glm::translate(BackgroundMaterices.m_Model, glm::vec3(0.0f, 0.0f, -4.0f));
    InitScreenImg.push_back(Background);
    InitScreenMatrices.push_back(std::make_shared<Core::Matrices>(BackgroundMaterices));
}

void InitScreen::CreateTower(){

    std::shared_ptr<RUtil::Image_magic> Tower=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title2.png");

    Tower->Set_small_Pos(glm::vec2{2, 860});
    Tower->Set_small_Size(glm::vec2{1920, 856});
    Core::Matrices TowerMaterices=Util::ConvertToUniformBufferData(Util::Transform(), Tower->Get_small_Size(), 0);
    TowerMaterices.m_Model = glm::scale(TowerMaterices.m_Model, glm::vec3{glm::vec2{1920.0f*WindowMultwidth,1266.0f*WindowMultheight*0.85}/Tower->Get_small_Size(), 1});
    TowerMaterices.m_Model = glm::translate(TowerMaterices.m_Model, glm::vec3(0.0f, 0.0f, -3.0f));
    InitScreenImg.push_back(Tower);
    InitScreenMatrices.push_back(std::make_shared<Core::Matrices>(TowerMaterices));
    
}
void InitScreen::CreateTopCloud1(){
    std::shared_ptr<RUtil::Image_magic> TopCloud1=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title6.png");
    TopCloud1->Set_small_Pos(glm::vec2{1280, 429});
    TopCloud1->Set_small_Size(glm::vec2{558, 176});
    Core::Matrices TopCloud1Materices=Util::ConvertToUniformBufferData(Util::Transform(), TopCloud1->Get_small_Size(), 0);
    TopCloud1Materices.m_Model = glm::scale(TopCloud1Materices.m_Model, glm::vec3{glm::vec2{1920.0f*WindowMultwidth*0.3,1266.0f*WindowMultheight*0.3}/TopCloud1->Get_small_Size(), 1});
    TopCloud1Materices.m_Model = glm::translate(TopCloud1Materices.m_Model, glm::vec3(1.5f, 0.0f, -2.0f));
    InitScreenImg.push_back(TopCloud1);
    InitScreenMatrices.push_back(std::make_shared<Core::Matrices>(TopCloud1Materices));

}

void InitScreen::Create(){
    CreateBackground();
    CreateTower();
    CreateTopCloud1();
    CreateLogo();

}
void InitScreen::draw(){
    for (int i = 0; i < InitScreenImg.size(); i++) {
        InitScreenImg[i]->Draw(*InitScreenMatrices[i]);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}
