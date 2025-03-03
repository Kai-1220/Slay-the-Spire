#include "Draw/ReTexture.hpp"
#include "Util/MissingTexture.hpp"
#include "Core/TextureUtils.hpp"
namespace Draw {
    ReTexture::ReTexture(const std::string &filepath){
        SDL_Surface* temp_surface=IMG_Load(filepath.c_str());
        if (temp_surface == nullptr) {
            temp_surface = GetMissingTextureSDLSurface();
            LOG_ERROR("Failed to load image: '{}'", filepath);
            LOG_ERROR("{}", IMG_GetError());
        }else if((temp_surface->w-1)&temp_surface->w||(temp_surface->h-1)&temp_surface->h){
            LOG_WARN("Image dimensions are not powers of 2");
        }
        
        this->w=temp_surface->w;
        this->h=temp_surface->h;
        glGenTextures(1, &m_TextureId);
        glBindTexture(GL_TEXTURE_2D,m_TextureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D,0,Core::SdlFormatToGlFormat(temp_surface->format->format),w,h,0,temp_surface->format->format,GL_UNSIGNED_BYTE,temp_surface->pixels);
        SDL_FreeSurface(temp_surface);
    }
    ReTexture::~ReTexture(){
        glDeleteTextures(1, &m_TextureId);
    }
    void ReTexture::Bind() const {
        glBindTexture(GL_TEXTURE_2D, m_TextureId);
    }
}