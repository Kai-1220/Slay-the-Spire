#pragma once

#include <string>

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

    unsigned int GetReTextureId() const { return m_TextureId; }
    int GetWidth() const {return w;}
    int GetHeight() const {return h;}
    void Bind() const;
protected://for Retext class
    ReTexture()=default;
    unsigned int m_TextureId;
    int w,h;
};
} // namespace Core