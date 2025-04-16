#include <memory>
#include <GL/glew.h>

#include "Game_object/effect/Effect_group.hpp"
#include "Game_object/effect/Effects.hpp"
#include "Draw/Draw_2D.hpp"

namespace Effect
{
    void Effect_group::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        for(const auto &it:box)
            it->render(r2);
        for(const auto &it:box2)
            it->render(r2);
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    }

    template <typename T>
    static void _update(T &_box){
        for (auto it = _box.begin(); it != _box.end();) {
            (*it)->update();
            if ((*it)->IsDone())
                it = _box.erase(it);
            else
                ++it;
        }
    }
    
    void Effect_group::update(){
        _update(box);
        _update(box2);
    }
} // namespace Effect