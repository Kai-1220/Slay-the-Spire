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
protected:
    int max_HP,current_HP,current_Block;
    void render_HP(const std::shared_ptr<Draw::Draw_2D> &r2)const;
private:
    float hb_height,hb_width,hb_cX,hb_cY,hb_a;
    float shadow_a,bg_a,outline_a,health_width,health_target_width,block_offset;
    const std::shared_ptr<Draw::ReTexture>  &_SHADOW_L=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/leftBg.png"),&_SHADOW_R=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/rightBg.png"),&_SHADOW_B=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/bodyBg.png"),
                                            &HEALTH_BAR_B=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/body7.png"),&HEALTH_BAR_L=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/left7.png"),&HEALTH_BAR_R=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/right7.png"),
                                            &BLOCK_BAR_B=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/blockBody3.png"),&BLOCK_BAR_R=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/blockRight3.png"),&BLOCK_BAR_L=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/blockLeft3.png"),
                                            &BLOCK_ICON=RUtil::Image_book::GetTexture(RESOURCE_DIR"Image/combat/block.png");
    static constexpr int ORG_BAR_COLOR=RUtil::Math::GetColorUint32_RGB(1.0F,0.5F,0.0F),BLUE_BAR_COLOR=0x31568c00,RED_BAR_COLOR=RUtil::Math::GetColorUint32_RGB(0.8F,0.05F,0.05F),BLOCK_COLOR=RUtil::Math::GetColorUint32_RGB(0.6F,0.93F,0.98F);
    static constexpr float HEALTH_BAR_HEIGHT=20.0F*Setting::SCALE,HEALTH_BAR_OFFSET_Y=-28.0F*Setting::SCALE,HEALTH_BG_OFFSET=28.0F*Setting::SCALE,BLOCK_ICON_XY=-14.0F*Setting::SCALE;
};
}
#endif