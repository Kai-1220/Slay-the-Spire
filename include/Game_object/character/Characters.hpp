#ifndef GAME_OBJECT_CHARACTER_CHARACTERS
#define GAME_OBJECT_CHARACTER_CHARACTERS
#include "Draw/Draw_2D.hpp"
#include "RUtil/Hitbox.hpp"
#include "RUtil/Image_book.hpp"
#include "WindowSize.hpp"
#include "RUtil/Some_Math.hpp"
namespace Character{
class Characters
{
public:
    Characters();
    virtual ~Characters()=default;
    virtual void damage(int num)=0;
    void render(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    void setPosition(glm::vec2 vec);
protected:
    int max_HP,current_HP,current_Block;
    void render_HP(const std::shared_ptr<Draw::Draw_2D> &r2)const;
    glm::vec2 pos;
private:
    float hb_height,hb_width,hb_cX,hb_cY,hb_a;
    float shadow_a,bg_a,outline_a,health_width,health_target_width,block_offset;
    static const std::shared_ptr<Draw::ReTexture>  &_SHADOW_L,&_SHADOW_R,&_SHADOW_B,
                                                &HEALTH_BAR_B,&HEALTH_BAR_L,&HEALTH_BAR_R,
                                                &BLOCK_BAR_B,&BLOCK_BAR_R,&BLOCK_BAR_L,
                                                &BLOCK_ICON;
    static constexpr int ORG_BAR_COLOR=RUtil::Math::GetColorUint32_RGB(1.0F,0.5F,0.0F),BLUE_BAR_COLOR=0x31568c00,RED_BAR_COLOR=RUtil::Math::GetColorUint32_RGB(0.8F,0.05F,0.05F),BLOCK_COLOR=RUtil::Math::GetColorUint32_RGB(0.6F,0.93F,0.98F);
    static constexpr float HEALTH_BAR_HEIGHT=20.0F*Setting::SCALE,HEALTH_BAR_OFFSET_Y=-28.0F*Setting::SCALE,HEALTH_BG_OFFSET=28.0F*Setting::SCALE,BLOCK_ICON_XY=-14.0F*Setting::SCALE;
    
};
}
#endif