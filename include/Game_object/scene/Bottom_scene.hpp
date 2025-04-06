#ifndef GAME_OBJECT_SCENE_BOTTOM_SCENE
#define GAME_OBJECT_SCENE_BOTTOM_SCENE
#include "Game_object/scene/Scenes.hpp"
namespace Scene{
//remember to add the effect.
class Bottom_scene final:public Scenes
{
public:
    // Bottom_scene(const std::shared_ptr<Room::Rooms> &current_room);
    Bottom_scene()=default;
    ~Bottom_scene()override=default;
    // void update()override;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const override;
    void next_room()override;
private:
    bool render_hollow_mid,render_solid_mid,render_left_wall;
    bool render_ceiling_mod[6];
    glm::vec3 color;
    void render_combat_room_bg(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    static const std::shared_ptr<Draw::Atlas_Region> &fg,&mg,&left_wall,
                                                     &hollow_wall,&solid_wall,&ceiling,
                                                     &ceiling_mod1,&ceiling_mod2,&ceiling_mod3,
                                                     &ceiling_mod4,&ceiling_mod5,&ceiling_mod6,
                                                     &bg;
    static const std::shared_ptr<Draw::ReTexture> &white_square;
};
}
#endif