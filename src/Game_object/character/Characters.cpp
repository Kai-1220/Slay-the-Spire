#include "Game_object/character/Characters.hpp"
#include <iostream>
#include "RUtil/Some_Math.hpp"
#include "RUtil/Game_Input.hpp"
namespace Character{
    Characters::Characters(float x, float y, float width, float height) : boss_hitbox(x, y, width, height, false){
        hb_height=HEALTH_BAR_HEIGHT;
        hb_a=1.0F;
        shadow_a = 1.0F;
        bg_a = 1.0F;
        outline_a =  1.0F;
        block_offset = 0.0F;
        DecreaseWaitTimer=1.2F;
        health_width=hb_width;
        health_target_width=hb_width;

    }

    void Characters::update(){
        // current_HP=10;
        health_target_width=hb_width*(current_HP/(float)max_HP);
        if(health_width-health_target_width!=0 && !HPDecrease){
            DecreaseWaitTimer-=RUtil::Game_Input::delta_time();
            if(DecreaseWaitTimer<=0){
                DecreaseWaitTimer=1.2F;
                HPDecrease=true;
            }
        }
        else if (HPDecrease)
        {
            health_width=RUtil::Math::varlerp(health_width,health_target_width,9.0F,Setting::SCALE);
        }
        if(health_width==health_target_width){
            HPDecrease=false;
        }
        boss_hitbox.update();
        
    }
    void Characters::render_HP(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        const float x=hb_cX-hb_width/2.0F,y=hb_cY-hb_height/2.0F;
        //shadow
        r2->SetColor(0,shadow_a);
        r2->draw(_SHADOW_L, x-HEALTH_BAR_HEIGHT, y-HEALTH_BG_OFFSET, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);
        r2->draw(_SHADOW_B, x, y-HEALTH_BG_OFFSET, hb_width, HEALTH_BAR_HEIGHT);
        r2->draw(_SHADOW_R, x+hb_width, y-HEALTH_BG_OFFSET, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);
        if(current_HP!=max_HP){
            //background
            r2->SetColor(0,bg_a);
            r2->draw(HEALTH_BAR_L, x-HEALTH_BAR_HEIGHT, y+HEALTH_BAR_OFFSET_Y, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);
            r2->draw(HEALTH_BAR_B, x, y+HEALTH_BAR_OFFSET_Y, hb_width, HEALTH_BAR_HEIGHT);
            r2->draw(HEALTH_BAR_R, x+hb_width, y+HEALTH_BAR_OFFSET_Y, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);
        }
        if(health_target_width!=0.0F){
            //hp just move //orange
            if(health_width-health_target_width!=0){
                r2->SetColor(ORG_BAR_COLOR,hb_a);
                r2->draw(HEALTH_BAR_B, x+health_target_width, y+HEALTH_BAR_OFFSET_Y, health_width-health_target_width, HEALTH_BAR_HEIGHT);
                r2->draw(HEALTH_BAR_R, x+health_width, y+HEALTH_BAR_OFFSET_Y, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);
            }
            //hp //red //if have block,blue
            r2->SetColor(current_Block>0?BLUE_BAR_COLOR:RED_BAR_COLOR,hb_a);
            r2->draw(HEALTH_BAR_L, x-HEALTH_BAR_HEIGHT, y+HEALTH_BAR_OFFSET_Y, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);
            r2->draw(HEALTH_BAR_B, x, y+HEALTH_BAR_OFFSET_Y, health_target_width, HEALTH_BAR_HEIGHT);
            r2->draw(HEALTH_BAR_R, x+health_target_width, y+HEALTH_BAR_OFFSET_Y, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);

        }
        //check hb_a cuz outline_a != hb_a
        if(current_Block!=0&&hb_a!=0.0F){
            //reder block outline
            r2->SetColor(BLOCK_COLOR,outline_a);
            r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE);
            r2->draw(BLOCK_BAR_L, x-HEALTH_BAR_HEIGHT, y+HEALTH_BAR_OFFSET_Y, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);
            r2->draw(BLOCK_BAR_B, x, y+HEALTH_BAR_OFFSET_Y, hb_width, HEALTH_BAR_HEIGHT);
            r2->draw(BLOCK_BAR_R, x+hb_width, y+HEALTH_BAR_OFFSET_Y, HEALTH_BAR_HEIGHT, HEALTH_BAR_HEIGHT);
            r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        }

        if(current_Block!=0&&hb_a!=0.0F){
            //block icon
            r2->SetColor(BLOCK_COLOR);
            r2->draw(BLOCK_ICON, x+BLOCK_ICON_XY-32.0F, y+BLOCK_ICON_XY-32.0F+block_offset, 64.0F, 64.0F, 0.0F, 32.0F, 32.0F, Setting::SCALE, Setting::SCALE);
        }
    }
    void Characters::setPosition(glm::vec2 vec,int WIDTH){
        pos=vec;
        hb_cX=vec.x+WIDTH*0.5F;
        hb_cY=vec.y; 
    }
    void Characters::setHPBarWidth(float width){
        hb_width=width;
        update();
    };
    
    const std::shared_ptr<Draw::ReTexture>  &Characters::_SHADOW_L=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/leftBg.png"),&Characters::_SHADOW_R=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/rightBg.png"),&Characters::_SHADOW_B=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/bodyBg.png"),
                                            &Characters::HEALTH_BAR_B=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/body7.png"),&Characters::HEALTH_BAR_L=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/left7.png"),&Characters::HEALTH_BAR_R=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/right7.png"),
                                            &Characters::BLOCK_BAR_B=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/blockBody3.png"),&Characters::BLOCK_BAR_R=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/blockRight3.png"),&Characters::BLOCK_BAR_L=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/blockLeft3.png"),
                                            &Characters::BLOCK_ICON=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/combat/block.png");

                                            


}