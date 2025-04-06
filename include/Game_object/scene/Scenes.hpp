#ifndef GAME_OBJECT_SCENE_SCENES
#define GAME_OBJECT_SCENE_SCENES
#include "Game_object/room/Rooms.hpp"
namespace Scene
{
//The scene will only be drawn when the room exists.
class Scenes
{
public:
    //Scenes(const std::shared_ptr<Room::Rooms> &current_room):current_room(current_room){}
    // virtual void update()=0;
    //If the room does not exist, the scenes should not be rendered.
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    virtual void next_room()=0;
    virtual ~Scenes()=default;
protected:
    static void render_format(const std::shared_ptr<Draw::Draw_2D> &r2,const std::shared_ptr<Draw::Atlas_Region>&img);
    // const std::shared_ptr<Room::Rooms> &current_room;
};
} // namespace Scene
#endif