#include "App.hpp"


void App::Start() {
    LOG_TRACE("Start");

    test=std::make_shared<Util::Image>(RESOURCE_DIR"/Image/cards/cards.png");
    data=Util::ConvertToUniformBufferData(Util::Transform(), test->GetSize(), 0);
    data.m_Model = glm::translate(data.m_Model, glm::vec3{0,0, 0});
    
    m_CurrentState = State::UPDATE;
}
