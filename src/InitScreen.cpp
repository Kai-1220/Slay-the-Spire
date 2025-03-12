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
    // std::shared_ptr<RUtil::Image_magic> Logo=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title6.png",glm::vec2{2, 61},glm::vec2{639, 550});
    // Logo->Set_small_Pos(glm::vec2{2, 61});
    // Logo->Set_small_Size(glm::vec2{639, 550});
    // Core::Matrices Matrices=Util::ConvertToUniformBufferData(Util::Transform(), Logo->Get_small_Size(), 0);
    // Matrices.m_Model = glm::scale(Matrices.m_Model, glm::vec3{glm::vec2{680.0f*Setting::SCALE*0.8,550.0f*Setting::SCALE*0.85}/Logo->Get_small_Size(), 1});
    // Matrices.m_Model = glm::translate(Matrices.m_Model, glm::vec3(0.0f, 0.0f, -1.0f));
    // LogoImg=Logo;
    // LogoMatrices=std::make_shared<Core::Matrices>(Matrices);
    
    // Util::Input::GetCursorPosition().x+WINDOW_WIDTH/2-25,Util::Input::GetCursorPosition().y+WINDOW_HEIGHT/2-25,50,50);
    LogoImg=(std::make_shared<Draw::Image_Region>(std::make_shared<Draw::ReTexture>
        (RESOURCE_DIR"/Image/Start_screen/title6.png"),2,61,639,550));
    LogoSize=glm::vec2{680*Setting::SCALE*0.8,550*Setting::SCALE*0.8};
    LogoPos=glm::vec2{(WINDOW_WIDTH-680*Setting::SCALE*0.8)/2,(WINDOW_HEIGHT-550*Setting::SCALE*0.8)/2};
}

void InitScreen::CreateBackground(){
    InitBackgroundImg.push_back(std::make_shared<Draw::Image_Region>(std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/Start_screen/title.jpg"),2,2,1920,1469));  
    ShowSize.push_back(glm::vec2{WINDOW_WIDTH,WINDOW_HEIGHT});
    ShowPos.push_back(glm::vec2{0,0});
}   

void InitScreen::CreateTower(){

    InitBackgroundImg.push_back(std::make_shared<Draw::Image_Region>(std::make_shared<Draw::ReTexture>(RESOURCE_DIR"/Image/Start_screen/title2.png"),2,860,1920,1140));
    ShowSize.push_back(glm::vec2{WINDOW_WIDTH,WINDOW_HEIGHT});
    ShowPos.push_back(glm::vec2{0,0});
}
void InitScreen::CreateBlackCloud(int i){
    BlackCloudImg.push_back(std::make_shared<Draw::Image_Region>(std::make_shared<Draw::ReTexture>
        (RESOURCE_DIR"/Image/Start_screen/title"+ std::to_string(BlackCloudImgNum[i]) +".png"),BlackCloudSourcePos[i].x,BlackCloudSourcePos[i].y,BlackCloudSize[i].x,BlackCloudSize[i].y));
    BlackCloudPos.push_back(glm::vec2{-BlackCloudSize[i].x-5, rand()%(WINDOW_HEIGHT-180)});
    BlackCloudCount.push_back(i);
}
void InitScreen::CreateWhiteCloud(int i){

    WhiteCloudImg.push_back(std::make_shared<Draw::Image_Region>(std::make_shared<Draw::ReTexture>
        (RESOURCE_DIR"/Image/Start_screen/title"+ std::to_string(WhiteCloudImgNum[i]) +".png"),WhiteCloudSourcePos[i].x,WhiteCloudSourcePos[i].y,WhiteCloudSize[i].x,WhiteCloudSize[i].y));
    WhiteCloudPos.push_back(glm::vec2{WINDOW_WIDTH+WhiteCloudSize[i].x+5, rand()%(WINDOW_HEIGHT-180)});
    WhiteCloudCount.push_back(i);
}
void InitScreen::CreateText(int i){
    // std::shared_ptr<Util::Text> Text=std::make_shared<Util::Text>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf", m_Size, m_Text[i],
    //     Util::Color::FromRGB(255, 255, 255));
    // Core::Matrices Matrices=Util::ConvertToUniformBufferData(Util::Transform(), TextScale[i]*Setting::SCALE, 0);
    // Matrices.m_Model = glm::translate(Matrices.m_Model, m_TextPos[i]);
    // TextMatrices.push_back(std::make_shared<Core::Matrices>(Matrices));
    // TextObj.push_back(Text);
}

void InitScreen::Create(){
    CreateBackground();
    CreateTower();
    CreateLogo();
    srand(time(NULL));
    // for (int i = 0; i < m_Text.size(); i++) {
    //     CreateText(i);
    // }
}
void InitScreen::draw(std::shared_ptr<Draw::Draw_2D> Draw2D){
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
        if(CloudGenTime<1000){
            CloudGenTime++;
        }
        
    }

 
    // for (int i = 0; i < BlackCloudImg.size(); i++) {
    //     BlackCloudMatrices[i]->m_Model = glm::translate(BlackCloudMatrices[i]->m_Model, glm::vec3(0.001f, 0.0f, 0.0f));
    //     BlackCloudImg[i]->Draw(*BlackCloudMatrices[i]);
    //     BlackCloudCount[i]++;
    //     if(BlackCloudCount[i]>4400){
    //         BlackCloudImg.erase(BlackCloudImg.begin()+i);
    //         BlackCloudMatrices.erase(BlackCloudMatrices.begin()+i);
    //         BlackCloudCount.erase(BlackCloudCount.begin()+i);
    //     }
    // }
    // for (int i = 0; i < WhiteCloudImg.size(); i++) {
    //     WhiteCloudMatrices[i]->m_Model = glm::translate(WhiteCloudMatrices[i]->m_Model, glm::vec3(-0.001f, 0.0f, 0.0f));
    //     WhiteCloudImg[i]->Draw(*WhiteCloudMatrices[i]);
    //     WhiteCloudCount[i]++;
    //     if(WhiteCloudCount[i]>4400){
    //         WhiteCloudImg.erase(WhiteCloudImg.begin()+i);
    //         WhiteCloudMatrices.erase(WhiteCloudMatrices.begin()+i);
    //         WhiteCloudCount.erase(WhiteCloudCount.begin()+i);
    //     }
    // }
    
    // LogoImg->Draw(*LogoMatrices);

    // for(int i=0;i<TextObj.size();i++){
    //     TextObj[i]->Draw(*TextMatrices[i]);
    //     if(Util::Input::GetCursorPosition().x<GetTextScreenPosition(i).x-TextScale[i].x/2.0f || 
    //         Util::Input::GetCursorPosition().x>GetTextScreenPosition(i).x+TextScale[i].x/2.0f || 
    //         Util::Input::GetCursorPosition().y<GetTextScreenPosition(i).y-TextScale[i].y/2.0f+15 || 
    //         Util::Input::GetCursorPosition().y>GetTextScreenPosition(i).y+TextScale[i].y/2.0f-15){
    //         TextObj[i]->SetColor(Util::Color::FromRGB(255, 255, 255));
    //     }
    //     else{
    //         TextObj[i]->SetColor(Util::Color::FromRGB(255, 0, 0));
    //         if(Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)){
    //             m_CurrentState=State(i+1);
    //         }
    //     }
    // }
    for(int i=0;i<InitBackgroundImg.size();i++){
        Draw2D->draw(InitBackgroundImg[i],
            ShowPos[i].x,ShowPos[i].y,
            ShowSize[i].x,ShowSize[i].y);
    }
    for (int i = 0; i < BlackCloudImg.size(); i++) {
        Draw2D->draw(BlackCloudImg[i],BlackCloudPos[i].x++,BlackCloudPos[i].y,BlackCloudSize[BlackCloudCount[i]].x*0.7,BlackCloudSize[BlackCloudCount[i]].y*0.7);
        if(BlackCloudPos[i].x>WINDOW_WIDTH){
            BlackCloudImg.erase(BlackCloudImg.begin()+i);
            BlackCloudPos.erase(BlackCloudPos.begin()+i);
            BlackCloudCount.erase(BlackCloudCount.begin()+i);
        }
    }
    for (int i = 0; i < WhiteCloudImg.size(); i++) {
        Draw2D->draw(WhiteCloudImg[i],WhiteCloudPos[i].x--,WhiteCloudPos[i].y,WhiteCloudSize[WhiteCloudCount[i]].x*0.7,WhiteCloudSize[WhiteCloudCount[i]].y);
        if(WhiteCloudPos[i].x<-WhiteCloudSize[WhiteCloudCount[i]].x){
            WhiteCloudImg.erase(WhiteCloudImg.begin()+i);
            WhiteCloudPos.erase(WhiteCloudPos.begin()+i);
            WhiteCloudCount.erase(WhiteCloudCount.begin()+i);
        }
    }
    Draw2D->draw(LogoImg,LogoPos.x,LogoPos.y,LogoSize.x,LogoSize.y);

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}


// 在 InitScreen.hpp 中添加此方法
// glm::vec2 InitScreen::GetTextScreenPosition(int index) {
//     if (index < 0 || index >= TextMatrices.size()) {
//         return glm::vec2(0.0f);
//     }
    
//     // 使用存儲在文字矩陣中的模型矩陣
//     glm::mat4 model = TextMatrices[index]->m_Model;
    
//     // 從模型矩陣第四列提取平移部分
//     glm::vec3 worldPos = glm::vec3(model[3]);
    
//     // 根據實際測量計算轉換係數
//     // 比較 (-329600, -40800) 和 (-520, -115) 的比例關係
//     float scaleFactorX = 634.0f*2;
//     float scaleFactorY = 355.0f*2;
    
//     // 直接從世界座標轉換到螢幕座標
//     float screenX = worldPos.x / scaleFactorX * WINDOW_WIDTH;
//     float screenY = worldPos.y / scaleFactorY * WINDOW_HEIGHT;
    
//     return glm::vec2(screenX, screenY);
// }
