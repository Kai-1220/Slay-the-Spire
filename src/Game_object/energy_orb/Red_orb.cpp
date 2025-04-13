#include "Game_object/energy_orb/Red_orb.hpp"
#include "RUtil/Game_Input.hpp"

namespace EnergyOrb{
    void Red_orb::update(){
        if(energy==0)
            for(int i=0;i<5;i++)
                angle[i]+=RUtil::Game_Input::delta_time()*ANGLE_SLOW[i];
        else
            for(int i=0;i<5;i++)
                angle[i]+=RUtil::Game_Input::delta_time()*ANGLE_QUICK[i];
    }
    void Red_orb::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        r2->SetColor(-1);
        if(energy==0){
            r2->draw(slow1, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[0], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
            r2->draw(slow2, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[1], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
            r2->draw(slow3, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[2], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
            r2->draw(slow4, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[3], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
            r2->draw(slow5, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[4], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
        }else{    
            r2->draw(quick1, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[0], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
            r2->draw(quick2, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[1], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
            r2->draw(quick3, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[2], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
            r2->draw(quick4, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[3], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
            r2->draw(quick5, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, angle[4], 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
        }
        r2->draw(layer6, panel_x-64.0F, panel_y-64.0F, 128.0F, 128.0F, 0.0F, 64.0F, 64.0F, ORB_SCALE, ORB_SCALE);
    }
    
    const std::shared_ptr<Draw::ReTexture> &Red_orb::slow1=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer1d.png"),&Red_orb::slow2=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer2d.png"),&Red_orb::slow3=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer3d.png"),&Red_orb::slow4=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer4d.png"),&Red_orb::slow5=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer5d.png"),
                                           &Red_orb::quick1=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer1.png"),&Red_orb::quick2=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer2.png"),&Red_orb::quick3=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer3.png"),&Red_orb::quick4=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer4.png"),&Red_orb::quick5=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer5.png"),
                                           &Red_orb::layer6=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/red/layer6.png");
}