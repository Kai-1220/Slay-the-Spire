#include"Draw/ReText.hpp"
#include"Util/Logger.hpp"
#include "Util/MissingTexture.hpp"
#include "Core/TextureUtils.hpp"
namespace Draw {
    ReText::ReText(const std::string &font, int fontSize, const std::string &text,
        const Util::Color &color):ReTexture(){
        auto m_Font = TTF_OpenFont(font.c_str(), fontSize);
        SDL_Surface* surface = TTF_RenderUTF8_Blended_Wrapped(m_Font, text.c_str(),
                            color.ToSdlColor(), 0);
        GLuint textureID;
        int the_w,the_h; 
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D,textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        if (surface == nullptr) {
            LOG_ERROR("Failed to create text");
            LOG_ERROR("{}", TTF_GetError());
            surface = GetMissingTextureSDLSurface();
            the_w=surface->w,
            the_h=surface->h;
        }else{
            the_w=surface->pitch / surface->format->BytesPerPixel;
            the_h=surface->h;
        }
        glTexImage2D(GL_TEXTURE_2D,0,Core::GlFormatToGlInternalFormat(Core::SdlFormatToGlFormat(surface->format->format)),the_w,the_h,0,Core::SdlFormatToGlFormat(surface->format->format),GL_UNSIGNED_BYTE,surface->pixels);
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            LOG_ERROR("OpenGL Error: {}", error);
        }
        SetReTexture(textureID,the_w,the_h);
        SDL_FreeSurface(surface);
        TTF_CloseFont(m_Font);
    }
}