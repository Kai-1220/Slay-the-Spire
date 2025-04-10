#include "Game_object/scene/Bottom_scene.hpp"
namespace Scene
{
// Bottom_scene::Bottom_scene(const std::shared_ptr<Room::Rooms> &current_room):Scenes(current_room){
// }
// void Bottom_scene::update(){}
void Bottom_scene::render(const std::shared_ptr<Draw::Draw_2D> &r2)const{
    render_combat_room_bg(r2);
}
void Bottom_scene::next_room(){
    //reset scene
    if(RUtil::Random::GetRandomBoolean()){
        render_solid_mid=false;
        render_left_wall=false;
        render_hollow_mid=true;
        if(RUtil::Random::GetRandomBoolean()){
            render_solid_mid=true;
            if(RUtil::Random::GetRandomBoolean()){
                render_left_wall=true;
            }
        }
    }else{
        render_solid_mid=true;
        render_left_wall=false;
        render_hollow_mid=false;
        if(RUtil::Random::GetRandomBoolean())
            render_left_wall=true;
    }
    for(int i=0;i<6;i++)
        render_ceiling_mod[i]=RUtil::Random::GetRandomBoolean();
    color.r=RUtil::Random::GetRandomFloat(0.0F,0.05F);
    color.g=RUtil::Random::GetRandomFloat(0.0F,0.2F);
    color.b=RUtil::Random::GetRandomFloat(0.0F,0.2F);
}
void Bottom_scene::render_combat_room_bg(const std::shared_ptr<Draw::Draw_2D> &r2)const{
    r2->SetColor(-1);
    render_format(r2,bg);
    render_format(r2,mg);
    render_format(r2,fg);
    if(render_hollow_mid&&render_solid_mid)
        r2->SetColor(Util::Colors::GRAY);
    if(render_solid_mid) render_format(r2 ,solid_wall);
    r2->SetColor(-1);
    if(render_hollow_mid) render_format(r2,hollow_wall);
    if(render_left_wall) render_format(r2,left_wall);
    render_format(r2,ceiling);
    if(render_ceiling_mod[0]) render_format(r2,ceiling_mod1);
    if(render_ceiling_mod[1]) render_format(r2,ceiling_mod2);
    if(render_ceiling_mod[2]) render_format(r2,ceiling_mod3);
    if(render_ceiling_mod[3]) render_format(r2,ceiling_mod4);
    if(render_ceiling_mod[4]) render_format(r2,ceiling_mod5);
    if(render_ceiling_mod[5]) render_format(r2,ceiling_mod6);
    r2->SetBlendFunc(GL_SRC_COLOR,GL_ONE);
    r2->SetColor(color.r,color.g,color.b);
    r2->draw(white_square,0.0F,0.0F,(float)WINDOW_WIDTH,(float)WINDOW_HEIGHT);
    r2->SetBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}
const std::shared_ptr<Draw::Atlas_Region> &Bottom_scene::fg=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_fg),&Bottom_scene::mg=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_mg),&Bottom_scene::left_wall=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_mod1),
                                          &Bottom_scene::hollow_wall=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_mod2),&Bottom_scene::solid_wall=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_midWall),&Bottom_scene::ceiling=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_ceiling),
                                          &Bottom_scene::ceiling_mod1=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_ceilingMod1),&Bottom_scene::ceiling_mod2=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_ceilingMod2),&Bottom_scene::ceiling_mod3=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_ceilingMod3),
                                          &Bottom_scene::ceiling_mod4=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_ceilingMod4),&Bottom_scene::ceiling_mod5=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_ceilingMod5),&Bottom_scene::ceiling_mod6=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_mod_ceilingMod6),
                                          &Bottom_scene::bg=RUtil::All_Image::GetAtlasRegion(RUtil::AtlasRegionID::bottom_scene_bg);                                        
const std::shared_ptr<Draw::ReTexture> &Bottom_scene::white_square=RUtil::Image_book::GetTexture(RESOURCE_DIR"/Image/other/whiteSquare32.png");
} // namespace Scene