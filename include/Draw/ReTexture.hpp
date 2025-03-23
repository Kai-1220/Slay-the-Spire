#ifndef DRAW_RETEXTURE_HPP
#define DRAW_RETEXTURE_HPP

#include "pch.hpp" // IWYU pragma: export

namespace Draw {
//one Image one Texture and only one.
class ReTexture {
public:
    /**
     * @brief Load texture from filepath.
     *
     * @param filepath The file path.
     */
    explicit ReTexture(const std::string &filepath);
    ReTexture(const ReTexture &) = delete;
    ReTexture(ReTexture &&) = delete;

    virtual ~ReTexture();

    ReTexture &operator=(const ReTexture &) = delete;
    ReTexture &operator=(ReTexture &&)=delete;

    GLuint GetReTextureId() const { return m_TextureId; }
    int GetWidth() const {return w;}
    int GetHeight() const {return h;}
    void Bind() const;
protected:
    //for Retext class
    void SetReTexture(const GLuint m_TextureId,const int w,const int h){this->m_TextureId=m_TextureId;this->w=w;this->h=h;}
    ReTexture(){m_TextureId=w=h=0;}
private:
    GLuint m_TextureId;
    int w,h;
};
} // namespace Core

#endif
