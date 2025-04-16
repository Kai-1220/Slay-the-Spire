#pragma once

//fwd decl
namespace Dungeon{
    class Dungeon_shared;
}
namespace Draw{
    class Draw_2D;
}

namespace Interface{
enum class Screen{
    On_map,
    On_battle
};

class Is_screen
{
public:  
    virtual ~Is_screen()=default;
    virtual void update(Dungeon::Dungeon_shared &dungeon_shared)=0;
    virtual void render(const std::shared_ptr<Draw::Draw_2D> &r2)const=0;
    void set_on_top(bool value){on_top=value;}
protected:
    bool on_top=false;
};
}