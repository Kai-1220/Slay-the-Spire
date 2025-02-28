#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Util/Text.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp"
#include "Util/GameObject.hpp"
#include "Util/Transform.hpp"
#include "Util/TransformUtils.hpp"

#include "RUtil/Image_magic.hpp"
class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

private:


    State m_CurrentState = State::START;
    Util::Renderer m_Root;
    //----
    std::shared_ptr<Util::Image>test;
    std::shared_ptr<RUtil::Image_magic>test2;
    Core::Matrices data,data2;
    //----
};

#endif
