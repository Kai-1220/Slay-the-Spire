#include "Game_object/effect/Effect_group.hpp"
namespace Effect
{
    void Effect_group::AddEffect(std::shared_ptr<Effects> &&eff){
        box.emplace_back(std::move(eff));
    }
    void Effect_group::AddEffect(const std::shared_ptr<Effects> &eff){
        box.emplace_back(eff);
    }
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