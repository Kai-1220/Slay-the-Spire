#include "InitScreen.hpp"
#include "WindowSize.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

#include "RUtil/ColorValuesOnly.hpp"
#include "RUtil/Image_book.hpp"
#include "Draw/Image_Region.hpp"
#include "Draw/ReText.hpp"

InitScreen::InitScreen() {
    LOG_TRACE("InitScreen");
    Create();

}
void InitScreen::CreateLogo(){
    LogoImg=(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture
        (RESOURCE_DIR"/Image/Start_screen/title6.png"),2,61,639,550));
    LogoSize=glm::vec2{680*Setting::SCALE*0.8,550*Setting::SCALE*0.8};
    LogoPos=glm::vec2{(Setting::WINDOW_WIDTH-680*Setting::SCALE*0.8)/2,(Setting::WINDOW_HEIGHT-550*Setting::SCALE*0.8)/2};
}

void InitScreen::CreateBackground(){
    InitBackgroundImg.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title.jpg"),2,2,1920,1469));  
    ShowSize.push_back(glm::vec2{Setting::WINDOW_WIDTH,Setting::WINDOW_HEIGHT});
    ShowPos.push_back(glm::vec2{0,0});
}   

void InitScreen::CreateTower(){

    InitBackgroundImg.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/Start_screen/title2.png"),2,860,1920,1140));
    ShowSize.push_back(glm::vec2{Setting::WINDOW_WIDTH,Setting::WINDOW_HEIGHT});
    ShowPos.push_back(glm::vec2{0,0});
}
void InitScreen::CreateBlackCloud(int i){
    BlackCloudImg.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture
        (RESOURCE_DIR"/Image/Start_screen/title"+ std::to_string(BlackCloudImgNum[i]) +".png"),BlackCloudSourcePos[i].x,BlackCloudSourcePos[i].y,BlackCloudSize[i].x,BlackCloudSize[i].y));
    BlackCloudPos.push_back(glm::vec2{-BlackCloudSize[i].x-5, rand()%(Setting::WINDOW_HEIGHT-180)-50});
    BlackCloudCount.push_back(i);
}
void InitScreen::CreateWhiteCloud(int i){

    WhiteCloudImg.push_back(std::make_shared<Draw::Image_Region>(RUtil::Image_book::GetTexture
        (RESOURCE_DIR"/Image/Start_screen/title"+ std::to_string(WhiteCloudImgNum[i]) +".png"),WhiteCloudSourcePos[i].x,WhiteCloudSourcePos[i].y,WhiteCloudSize[i].x,WhiteCloudSize[i].y));
    WhiteCloudPos.push_back(glm::vec2{Setting::WINDOW_WIDTH+WhiteCloudSize[i].x+5, rand()%(Setting::WINDOW_HEIGHT-180)-50});
    WhiteCloudCount.push_back(i);
}
void InitScreen::CreateText(int i){
    std::shared_ptr<Draw::ReText> Text=std::make_shared<Draw::ReText>(RESOURCE_DIR"/font/zht/NotoSansCJKtc-Bold.otf", m_Size, m_Text[i]);
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
void InitScreen::draw(const std::shared_ptr<Draw::Draw_2D> &Draw2D){
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
    Draw2D->SetColor(RUtil::Colors::WHITE);
    for(int i=0;i<InitBackgroundImg.size();i++){
        Draw2D->draw(InitBackgroundImg[i],
            ShowPos[i].x,ShowPos[i].y,
            ShowSize[i].x,ShowSize[i].y);
    }
    for (int i = 0; i < BlackCloudImg.size(); i++) {
        Draw2D->draw(BlackCloudImg[i],BlackCloudPos[i].x++,BlackCloudPos[i].y,BlackCloudSize[BlackCloudCount[i]].x*0.5,BlackCloudSize[BlackCloudCount[i]].y*0.7);
        if(BlackCloudPos[i].x>Setting::WINDOW_WIDTH){
            BlackCloudImg.erase(BlackCloudImg.begin()+i);
            BlackCloudPos.erase(BlackCloudPos.begin()+i);
            BlackCloudCount.erase(BlackCloudCount.begin()+i);
            i--;
        }
    }
    for (int i = 0; i < WhiteCloudImg.size(); i++) {
        Draw2D->draw(WhiteCloudImg[i],WhiteCloudPos[i].x--,WhiteCloudPos[i].y,WhiteCloudSize[WhiteCloudCount[i]].x*0.5,WhiteCloudSize[WhiteCloudCount[i]].y);
        if(WhiteCloudPos[i].x<-WhiteCloudSize[WhiteCloudCount[i]].x){
            WhiteCloudImg.erase(WhiteCloudImg.begin()+i);
            WhiteCloudPos.erase(WhiteCloudPos.begin()+i);
            WhiteCloudCount.erase(WhiteCloudCount.begin()+i);
            i--;
        }
    }
    Draw2D->draw(LogoImg,LogoPos.x,LogoPos.y,LogoSize.x,LogoSize.y);
    
    for(int i=0;i<TextObj.size();i++){
        if(Util::Input::GetCursorPosition().x+Setting::WINDOW_WIDTH/2>m_TextPos[i].x && 
            Util::Input::GetCursorPosition().x+Setting::WINDOW_WIDTH/2<m_TextPos[i].x+TextScale[i].x && 
            Util::Input::GetCursorPosition().y+Setting::WINDOW_HEIGHT/2>m_TextPos[i].y && 
            Util::Input::GetCursorPosition().y+Setting::WINDOW_HEIGHT/2<m_TextPos[i].y+TextScale[i].y){
            Draw2D->SetColor(255, 0, 0);
            if(Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)){
                m_CurrentState=State(i+1);
            }
        }
        else{
            Draw2D->SetColor(255, 255, 255);
        }
        Draw2D->draw(TextObj[i],m_TextPos[i].x,m_TextPos[i].y,TextScale[i].x,TextScale[i].y);
        Draw2D->SetColor(255, 255, 255);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}
