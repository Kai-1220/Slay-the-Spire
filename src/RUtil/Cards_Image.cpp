#include "RUtil/Cards_Image.hpp"
#include "pch.hpp"
const char * const card_paths[] = {
    RESOURCE_DIR"/Image/cards/cards.png",
    RESOURCE_DIR"/Image/cards/cards2.png",
    RESOURCE_DIR"/Image/cards/cards3.png",
    RESOURCE_DIR"/Image/cards/cards4.png",
    RESOURCE_DIR"/Image/cards/cards5.png"
};
namespace RUtil {
void RUtil::Cards_Image::InitProgram(){
    s_Program =
        std::make_unique<Core::Program>(PTSD_ASSETS_DIR "/shaders/Base.vert",
                                        PTSD_ASSETS_DIR "/shaders/Base.frag");
    s_Program->Bind();

    GLint location = glGetUniformLocation(s_Program->GetId(), "surface");
    glUniform1i(location, UNIFORM_SURFACE_LOCATION);
}
void RUtil::Cards_Image::Init_Card_Textures(){
    for(const char * it:card_paths){
        auto card_surface=std::make_shared<SDL_Surface>(IMG_Load(it),SDL_FreeSurface);
        s_Card_Textures.push_back(std::make_unique<Core::Texture>(card_surface->format,card_surface->w,card_surface->h,card_surface->pixels));
    }
}
}