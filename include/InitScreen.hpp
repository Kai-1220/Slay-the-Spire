#ifndef INITSCREEN_HPP
#define INITSCREEN_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Util/Text.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp"
#include "Util/GameObject.hpp"
#include "Util/Transform.hpp"
#include "Util/TransformUtils.hpp"

#include "RUtil/Image_magic.hpp"

#include <SDL.h>
#include <memory>
#include <vector>
#include <iostream>
class InitScreen {
public:
    enum class State {
        INIT,
        END
    };
    
    InitScreen();
    ~InitScreen()=default;

    void CreateLogo();
    void CreateBackground();
    void CreateTower();
    void CreateTopCloud1();
    void Create();
    void draw();
    State GetCurrentState() const { return m_CurrentState; }

private:
    State m_CurrentState = State::INIT;

    std::vector <std::shared_ptr<RUtil::Image_magic>> InitScreenImg;
    std::vector <std::shared_ptr<Core::Matrices>> InitScreenMatrices;
};

#endif
