#include "App.hpp"
#include "WindowSize.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include <iostream>
#include <vector>
void App::Start() {
    LOG_TRACE("InitScreen");

    // test=std::make_shared<Util::Image>(RESOURCE_DIR"/Image/cards/cards2.png");
    // data=Util::ConvertToUniformBufferData(Util::Transform(), test->GetSize(), 0);
    // test2=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/cards/cards.png");
    // test2->Set_small_Pos(glm::vec2{491, 1831});
    // test2->Set_small_Size(glm::vec2{10, 10});
    
    
    // data.m_Model = glm::scale(data.m_Model, glm::vec3{0.2,0.2, 1});
    // data.m_Model=glm::translate(data.m_Model,glm::vec3{1,0,0});


    // data.m_Model = glm::scale(data.m_Model, glm::vec3{0.2,0.2, 1});
    // data.m_Model=glm::translate(data.m_Model,glm::vec3{1,0,0});

    // data2=Util::ConvertToUniformBufferData(Util::Transform(), test2->GetSize(), 0);
    // data2.m_Model = glm::scale(data2.m_Model, glm::vec3{0.2,0.2, 1});

 

    // m_CurrentState = State::UPDATE;

    // Logo=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/Start_screen/title6.png");
    // Logo->Set_small_Pos(glm::vec2{2, 61});
    // Logo->Set_small_Size(glm::vec2{639, 550});
    // LogoMaterices=Util::ConvertToUniformBufferData(Util::Transform(), Logo->Get_small_Size(), 0);
    // LogoMaterices.m_Model = glm::scale(LogoMaterices.m_Model, glm::vec3{glm::vec2{680*WindowMultwidth,550*WindowMultheight}/Logo->Get_small_Size(), 0});
    // Logo->Draw(LogoMaterices);

    // vector <std::shared_ptr<RUtil::Image_magic>> StartScreen;


    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}
