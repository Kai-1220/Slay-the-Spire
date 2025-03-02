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
    std::shared_ptr<RUtil::Image_magic> Logo=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title6.png",glm::vec2{2, 61},glm::vec2{639, 550});
    // Logo->Set_small_Pos(glm::vec2{2, 61});
    // Logo->Set_small_Size(glm::vec2{639, 550});
    Core::Matrices LogoMaterices=Util::ConvertToUniformBufferData(Util::Transform(), Logo->Get_small_Size(), 0);
    LogoMaterices.m_Model = glm::scale(LogoMaterices.m_Model, glm::vec3{glm::vec2{680.0f*SCALE*0.8,550.0f*SCALE*0.85}/Logo->Get_small_Size(), 1});
    LogoMaterices.m_Model = glm::translate(LogoMaterices.m_Model, glm::vec3(0.0f, 0.0f, -1.0f));
    InitScreenImg.push_back(Logo);
    InitScreenMatrices.push_back(std::make_shared<Core::Matrices>(LogoMaterices));
}

void InitScreen::CreateBackground(){
    std::shared_ptr<RUtil::Image_magic> Background=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title.jpg");
    Background->Set_small_Pos(glm::vec2{2, 2});
    Background->Set_small_Size(glm::vec2{1920, 1469});
    Core::Matrices BackgroundMaterices=Util::ConvertToUniformBufferData(Util::Transform(), Background->Get_small_Size(), 0);
    BackgroundMaterices.m_Model = glm::scale(BackgroundMaterices.m_Model, glm::vec3{glm::vec2{1920.0f*SCALE,1469.0f*SCALE*0.8}/Background->Get_small_Size(), 1});
    BackgroundMaterices.m_Model = glm::translate(BackgroundMaterices.m_Model, glm::vec3(0.0f, 0.0f, -3.0f));
    InitScreenImg.push_back(Background);
    InitScreenMatrices.push_back(std::make_shared<Core::Matrices>(BackgroundMaterices));
}

void InitScreen::CreateTower(){

    std::shared_ptr<RUtil::Image_magic> Tower=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title2.png");

    Tower->Set_small_Pos(glm::vec2{2, 860});
    Tower->Set_small_Size(glm::vec2{1920, 856});
    Core::Matrices TowerMaterices=Util::ConvertToUniformBufferData(Util::Transform(), Tower->Get_small_Size(), 0);
    TowerMaterices.m_Model = glm::scale(TowerMaterices.m_Model, glm::vec3{glm::vec2{1920.0f*SCALE,1266.0f*SCALE*0.85}/Tower->Get_small_Size(), 1});
    TowerMaterices.m_Model = glm::translate(TowerMaterices.m_Model, glm::vec3(0.0f, 0.0f, -2.0f));
    InitScreenImg.push_back(Tower);
    InitScreenMatrices.push_back(std::make_shared<Core::Matrices>(TowerMaterices));
    
}

void InitScreen::Create(){
    CreateBackground();
    CreateTower();
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