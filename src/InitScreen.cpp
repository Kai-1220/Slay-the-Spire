#include "InitScreen.hpp"
#include "WindowSize.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Draw\ReTexture.hpp"
#include <iostream>
#include <vector>


InitScreen::InitScreen() {
    LOG_TRACE("InitScreen");
    Create();

}
void InitScreen::CreateLogo(){
    std::shared_ptr<RUtil::Image_magic> Logo=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title6.png",glm::vec2{2, 61},glm::vec2{639, 550});
    // Logo->Set_small_Pos(glm::vec2{2, 61});
    // Logo->Set_small_Size(glm::vec2{639, 550});
    Core::Matrices Matrices=Util::ConvertToUniformBufferData(Util::Transform(), Logo->Get_small_Size(), 0);
    Matrices.m_Model = glm::scale(Matrices.m_Model, glm::vec3{glm::vec2{680.0f*SCALE*0.8,550.0f*SCALE*0.85}/Logo->Get_small_Size(), 1});
    Matrices.m_Model = glm::translate(Matrices.m_Model, glm::vec3(0.0f, 0.0f, -1.0f));
    LogoImg=Logo;
    LogoMatrices=std::make_shared<Core::Matrices>(Matrices);
}

void InitScreen::CreateBackground(){
    std::shared_ptr<RUtil::Image_magic> Background=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title.jpg");
    Background->Set_small_Pos(glm::vec2{2, 2});
    Background->Set_small_Size(glm::vec2{1920, 1469});
    Core::Matrices Matrices=Util::ConvertToUniformBufferData(Util::Transform(), Background->Get_small_Size(), 0);
    Matrices.m_Model = glm::scale(Matrices.m_Model, glm::vec3{glm::vec2{1920.0f*SCALE,1469.0f*SCALE*0.8}/Background->Get_small_Size(), 1});
    Matrices.m_Model = glm::translate(Matrices.m_Model, glm::vec3(0.0f, 0.0f, -5.0f));
    InitBackgroundImg.push_back(Background);
    InitBackgroundMatrices.push_back(std::make_shared<Core::Matrices>(Matrices));
}

void InitScreen::CreateTower(){

    std::shared_ptr<RUtil::Image_magic> Tower=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title2.png");

    Tower->Set_small_Pos(glm::vec2{2, 860});
    Tower->Set_small_Size(glm::vec2{1920, 856});
    Core::Matrices Matrices=Util::ConvertToUniformBufferData(Util::Transform(), Tower->Get_small_Size(), 0);
    Matrices.m_Model = glm::scale(Matrices.m_Model, glm::vec3{glm::vec2{1920.0f*SCALE,1266.0f*SCALE*0.85}/Tower->Get_small_Size(), 1});
    Matrices.m_Model = glm::translate(Matrices.m_Model, glm::vec3(0.0f, 0.0f, -4.0f));
    InitBackgroundImg.push_back(Tower);
    InitBackgroundMatrices.push_back(std::make_shared<Core::Matrices>(Matrices));
    
}
void InitScreen::CreateBlackCloud(int i){
    printf("BlackCloud\n");
    std::shared_ptr<RUtil::Image_magic> BlackCloud=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title"+ std::to_string(BlackCloudImgNum[i]) +".png");
    BlackCloud->Set_small_Pos(BlackCloudPos[i]);
    BlackCloud->Set_small_Size(BlackCloudSize[i]);
    Core::Matrices BlackCloudMaterices=Util::ConvertToUniformBufferData(Util::Transform(), BlackCloud->Get_small_Size(), 0);
    BlackCloudMaterices.m_Model = glm::scale(BlackCloudMaterices.m_Model, glm::vec3{BlackCloudorigScale*glm::vec2{SCALE,SCALE}*glm::vec2{0.3,0.3}/BlackCloud->Get_small_Size(), 1});
    BlackCloudMaterices.m_Model = glm::translate(BlackCloudMaterices.m_Model, glm::vec3(-2.25f, -rand()%18/10.0f, -3.0f));
    BlackCloudImg.push_back(BlackCloud);
    BlackCloudMatrices.push_back(std::make_shared<Core::Matrices>(BlackCloudMaterices));
    BlackCloudCount.push_back(0);

}
void InitScreen::CreateWhiteCloud(int i){
    printf("WhiteCloud\n");
    std::shared_ptr<RUtil::Image_magic> WhiteCloud=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title"+ std::to_string(WhiteCloudImgNum[i]) +".png");
    WhiteCloud->Set_small_Pos(WhiteCloudPos[i]);
    WhiteCloud->Set_small_Size(WhiteCloudSize[i]);
    Core::Matrices WhiteCloudMaterices=Util::ConvertToUniformBufferData(Util::Transform(), WhiteCloud->Get_small_Size(), 0);
    WhiteCloudMaterices.m_Model = glm::scale(WhiteCloudMaterices.m_Model, glm::vec3{WhiteCloudorigScale*glm::vec2{SCALE,SCALE}*glm::vec2{0.3,0.3}/WhiteCloud->Get_small_Size(), 1});
    WhiteCloudMaterices.m_Model = glm::translate(WhiteCloudMaterices.m_Model, glm::vec3(2.25f, -rand()%18/10.0f, -2.0f));
    WhiteCloudImg.push_back(WhiteCloud);
    WhiteCloudMatrices.push_back(std::make_shared<Core::Matrices>(WhiteCloudMaterices));
    WhiteCloudCount.push_back(0);
}
void InitScreen::CreateText(int i){
    std::shared_ptr<Util::Text> Text=std::make_shared<Util::Text>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf", m_Size, m_Text[i],
        Util::Color::FromRGB(255, 255, 255));
    Core::Matrices Matrices=Util::ConvertToUniformBufferData(Util::Transform(), TextScale[i]*SCALE, 0);
    Matrices.m_Model = glm::translate(Matrices.m_Model, m_TextPos[i]);
    TextMatrices.push_back(std::make_shared<Core::Matrices>(Matrices));
    TextObj.push_back(Text);
}

void InitScreen::Create(){
    CreateBackground();
    CreateTower();
    CreateLogo();
    for (int i = 0; i < m_Text.size(); i++) {
        CreateText(i);
    }
}
void InitScreen::draw(std::shared_ptr<Draw::Draw_2D> Draw2D){
    // std::cout<<Util::Input::GetCursorPosition().x<<" "<<Util::Input::GetCursorPosition().y<<std::endl;
    // std::cout<<GetTextScreenPosition(3).x<<" "<<GetTextScreenPosition(3).y<<std::endl;
    for (int i = 0; i < InitBackgroundImg.size(); i++) {
        InitBackgroundImg[i]->Draw(*InitBackgroundMatrices[i]);
    }
    srand(time(NULL));
    if(rand()%100<45 && CloudGenTime>500){
        if(rand()%2==0){
            CreateBlackCloud(rand()%7);
        }
        else{
            CreateWhiteCloud(rand()%13);
        }
        CloudGenTime=1;

    }
    else{
        if(CloudGenTime<600){
            CloudGenTime++;
        }
        
    }

 
    for (int i = 0; i < BlackCloudImg.size(); i++) {
        BlackCloudMatrices[i]->m_Model = glm::translate(BlackCloudMatrices[i]->m_Model, glm::vec3(0.001f, 0.0f, 0.0f));
        BlackCloudImg[i]->Draw(*BlackCloudMatrices[i]);
        BlackCloudCount[i]++;
        if(BlackCloudCount[i]>4400){
            BlackCloudImg.erase(BlackCloudImg.begin()+i);
            BlackCloudMatrices.erase(BlackCloudMatrices.begin()+i);
            BlackCloudCount.erase(BlackCloudCount.begin()+i);
        }
    }
    for (int i = 0; i < WhiteCloudImg.size(); i++) {
        WhiteCloudMatrices[i]->m_Model = glm::translate(WhiteCloudMatrices[i]->m_Model, glm::vec3(-0.001f, 0.0f, 0.0f));
        WhiteCloudImg[i]->Draw(*WhiteCloudMatrices[i]);
        WhiteCloudCount[i]++;
        if(WhiteCloudCount[i]>4400){
            WhiteCloudImg.erase(WhiteCloudImg.begin()+i);
            WhiteCloudMatrices.erase(WhiteCloudMatrices.begin()+i);
            WhiteCloudCount.erase(WhiteCloudCount.begin()+i);
        }
    }
    
    LogoImg->Draw(*LogoMatrices);

    for(int i=0;i<TextObj.size();i++){
        TextObj[i]->Draw(*TextMatrices[i]);
        if(Util::Input::GetCursorPosition().x<GetTextScreenPosition(i).x-TextScale[i].x/2.0f || 
            Util::Input::GetCursorPosition().x>GetTextScreenPosition(i).x+TextScale[i].x/2.0f || 
            Util::Input::GetCursorPosition().y<GetTextScreenPosition(i).y-TextScale[i].y/2.0f+15 || 
            Util::Input::GetCursorPosition().y>GetTextScreenPosition(i).y+TextScale[i].y/2.0f-15){
            TextObj[i]->SetColor(Util::Color::FromRGB(255, 255, 255));
        }
        else{
            TextObj[i]->SetColor(Util::Color::FromRGB(255, 0, 0));
            if(Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)){
                m_CurrentState=State(i+1);
            }
        }
    }

    
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}


// 在 InitScreen.hpp 中添加此方法
glm::vec2 InitScreen::GetTextScreenPosition(int index) {
    if (index < 0 || index >= TextMatrices.size()) {
        return glm::vec2(0.0f);
    }
    
    // 使用存儲在文字矩陣中的模型矩陣
    glm::mat4 model = TextMatrices[index]->m_Model;
    
    // 從模型矩陣第四列提取平移部分
    glm::vec3 worldPos = glm::vec3(model[3]);
    
    // 根據實際測量計算轉換係數
    // 比較 (-329600, -40800) 和 (-520, -115) 的比例關係
    float scaleFactorX = 634.0f*2;
    float scaleFactorY = 355.0f*2;
    
    // 直接從世界座標轉換到螢幕座標
    float screenX = worldPos.x / scaleFactorX * WINDOW_WIDTH;
    float screenY = worldPos.y / scaleFactorY * WINDOW_HEIGHT;
    
    return glm::vec2(screenX, screenY);
}
