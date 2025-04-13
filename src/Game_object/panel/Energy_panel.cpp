#include "Game_object/panel/Energy_panel.hpp"
#include "Game_object/energy_orb/Energy_orb.hpp"
#include "Game_object/energy_orb/Red_orb.hpp"
#include "Game_object/character/Player.hpp"
#include "Game_object/effect/Effect_group.hpp"
#include "Game_object/effect/Refresh_energy_effect.hpp"
#include "RUtil/Image_book.hpp"
#include "RUtil/Game_Input.hpp"
#include "WindowSize.hpp"

namespace Panel
{
    Energy_panel::Energy_panel():Panels(198.0F*Setting::SCALE, 190.0F*Setting::SCALE, -480.0F*Setting::SCALE, 200.0F*Setting::SCALE, true),m_font(FONTSIZE){
        vfx_angle=0.0F;
        vfx_scale=Setting::SCALE;
        vfx_color_a=0.0F;
        vfx_timer=0.0F;
        font_scale=1.0F;
    }
    void Energy_panel::update(){
        this->update_position();
        if(energy_orb==nullptr) LOG_ERROR("Forget to set player to energy panel.");
        else energy_orb->update();
        update_vfx();
        if(font_scale!=1.0F){
            font_scale=RUtil::Math::varlerp(font_scale,1.0F,8.0F,0.003F);
        }
    }
    void Energy_panel::update_vfx(){
        if(vfx_timer!=0.0F){
            vfx_color_a=RUtil::Math::interpolation_exp10in(0.5F,0.0F,1.0F-vfx_timer/2.0F);
            vfx_angle-=RUtil::Game_Input::delta_time()*30.0F;
            vfx_scale=Setting::SCALE*RUtil::Math::interpolation_exp10in(1.0F,0.1F,1.0F-vfx_timer/2.0F);
            vfx_timer-=RUtil::Game_Input::delta_time();
            if(vfx_timer<0.0F){
                vfx_timer=0.0F;
                vfx_color_a=0.0F;
            }
        }
    }
    void Energy_panel::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        if(energy_orb!=nullptr)energy_orb->render(r2);
        render_vfx(r2);
        r2->SetColor(TEXTCOLOR,1.0F);
        if(m_player.expired()) LOG_ERROR("Forget to set or reset player in Energy_panel");
        else m_font.render(r2,std::to_string(*current_energy)+"/"+std::to_string(*max_energy),current_x,current_y,font_scale);
    }
    void Energy_panel::render_vfx(const std::shared_ptr<Draw::Draw_2D> &r2)const{
        if(vfx_timer!=0.0F){
            r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE);
            r2->SetColor(-1,vfx_color_a);
            r2->draw(vfx_img, current_x-128.0F, current_y-128.0F, 256.0F, 256.0F, -vfx_angle+50.0F, 128.0F, 128.0F, vfx_scale, vfx_scale);
            r2->draw(vfx_img, current_x-128.0F, current_y-128.0F, 256.0F, 256.0F, vfx_angle, 128.0F, 128.0F, vfx_scale, vfx_scale);
            r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        }
    }
    void Energy_panel::on_use_energy(){
        font_scale=2.0F;
        vfx_timer=2.0F;
    }
    void Energy_panel::on_add_energy(const std::shared_ptr<Effect::Effect_group>&effs){
        effs->AddTop(std::make_shared<Effect::Refresh_energy_effect>(this->current_x,this->current_y));
        font_scale=2.0F;
        vfx_timer=2.0F;
    }
    void Energy_panel::set_player(const std::shared_ptr<Character::Player> &player){
        m_player=player;
        current_energy=&player->GetCurrEnergy();
        max_energy=&player->GetMaxEnergy();
        switch (player->player_type)
        {
            default:
                vfx_img=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/topPanel/energyRedVFX.png");
                energy_orb=std::make_shared<EnergyOrb::Red_orb>(player->GetCurrEnergy(),current_x,current_y);
                break;
        }
    }
} // namespace Panel
