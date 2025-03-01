#include "App.hpp"


void App::Start() {
    LOG_TRACE("Start");

    test=std::make_shared<Util::Image>(RESOURCE_DIR"/Image/cards/cards2.png");
    data=Util::ConvertToUniformBufferData(Util::Transform(), test->GetSize(), 0);
    test2=std::make_shared<RUtil::Image_magic>(RESOURCE_DIR"/Image/cards/cards.png");
    test2->Set_small_Pos(glm::vec2{491, 1831});
    test2->Set_small_Size(glm::vec2{10, 10});
    
    
    data.m_Model = glm::scale(data.m_Model, glm::vec3{0.2,0.2, 1});
    data.m_Model=glm::translate(data.m_Model,glm::vec3{1,0,0});

    data2=Util::ConvertToUniformBufferData(Util::Transform(), test2->GetSize(), 0);
    data2.m_Model = glm::scale(data2.m_Model, glm::vec3{0.2,0.2, 1});

    m_CurrentState = State::UPDATE;
}
