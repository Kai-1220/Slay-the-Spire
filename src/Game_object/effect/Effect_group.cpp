#include <memory>
#include <GL/glew.h>

#include "Game_object/effect/Effect_group.hpp"
#include "Game_object/effect/Effects.hpp"
#include "Draw/Draw_2D.hpp"

namespace Effect
{
    void Effect_group::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        for(const auto &it:box){
            it->render(r2);
        }
        r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    }
    void Effect_group::update(){
        for (auto it = box.begin(); it != box.end();) {
            (*it)->update();
            if ((*it)->IsDone()) {
              it = box.erase(it);
            }else{
              ++it;
            }
        }
    }
} // namespace Effect