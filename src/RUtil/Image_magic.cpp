#include "RUtil/Image_magic.hpp"

#include "Util/Logger.hpp"
#include "pch.hpp"

#include "Core/Texture.hpp"
#include "Core/TextureUtils.hpp"

#include "Util/MissingTexture.hpp"
#include "Util/TransformUtils.hpp"

#include "config.hpp"
#include <glm/fwd.hpp>

std::shared_ptr<SDL_Surface> LLoadSurface(const std::string &filepath) {
    auto surface = std::shared_ptr<SDL_Surface>(IMG_Load(filepath.c_str()),
                                                SDL_FreeSurface);

    if (surface == nullptr) {
        surface = {GetMissingTextureSDLSurface(), SDL_FreeSurface};
        LOG_ERROR("Failed to load image: '{}'", filepath);
        LOG_ERROR("{}", IMG_GetError());
    }

    return surface;
}

namespace RUtil{
Image_magic::Image_magic(const std::string &filepath)
    : m_Path(filepath) {
    if (s_Program == nullptr) {
        InitProgram();
    }
    if (s_VertexArray == nullptr) {
        InitVertexArray();
    }

    m_UniformBuffer = std::make_unique<Core::UniformBuffer<Core::Matrices>>(
        *s_Program, "Matrices", 0);

    auto surface = s_Store.Get(filepath);

    m_Texture = std::make_unique<Core::Texture>(
        Core::SdlFormatToGlFormat(surface->format->format), surface->w,
        surface->h, surface->pixels);
    small_Size=m_Size = {surface->w, surface->h};
    small_Pos={0,0};
}
Image_magic::Image_magic(const std::string &filepath,const glm::vec2& small_Pos,const glm::vec2& small_Size):
    m_Path(filepath){
    if (s_Program == nullptr) {
        InitProgram();
    }
    if (s_VertexArray == nullptr) {
        InitVertexArray();
    }
    m_UniformBuffer = std::make_unique<Core::UniformBuffer<Core::Matrices>>(
        *s_Program, "Matrices", 0);
        
    this->small_Pos=small_Pos;
    this->small_Size=small_Size;
    if(small_Pos.x<0||small_Pos.y<0||small_Size.x<0||small_Size.y<0||small_Pos.x+small_Size.x>m_Size.x||small_Pos.y+small_Size.y>m_Size.y){
        auto surface = s_Store.Get(filepath);
        m_Texture = std::make_unique<Core::Texture>(
            Core::SdlFormatToGlFormat(surface->format->format), surface->w,
            surface->h, surface->pixels);
    }else{
        Reload_texture();
    }
}
void Image_magic::Set_small_Size(const glm::vec2& small_Size){
    if(small_Size.x<0||small_Size.y<0) return;
    this->small_Size=small_Size;
    if(small_Pos.x+small_Size.x>m_Size.x||small_Pos.y+small_Size.y>m_Size.y) return;
    Reload_texture();
}
void Image_magic::Set_small_Pos(const glm::vec2& small_Pos){
    if(small_Pos.x<0||small_Pos.y<0) return;
    this->small_Pos=small_Pos;
    // if (x + subWidth > surface->w || y + subHeight > surface->h) return;
    if(small_Pos.x+small_Size.x>m_Size.x||small_Pos.y+small_Size.y>m_Size.y) return;
    Reload_texture();
}
void Image_magic::Reload_texture(){
    auto surface = s_Store.Get(m_Path);
    auto sub_surface=std::shared_ptr<SDL_Surface>(SDL_CreateRGBSurface(0, small_Size[0], small_Size[1], surface->format->BitsPerPixel,
        surface->format->Rmask, surface->format->Gmask,
        surface->format->Bmask, surface->format->Amask));
    if (!sub_surface) {
        LOG_ERROR("SDL could not create surface!");
        LOG_ERROR("{}", SDL_GetError());
        return;
    }
    SDL_Rect sub_rect={0,0,int(small_Size[0]),int(small_Size[1])},
             srcRect={int(small_Pos.x),int(small_Pos.y),int(small_Size[0]),int(small_Size[1])};
    if (SDL_BlitSurface(surface.get(), &srcRect, sub_surface.get(), &sub_rect) != 0) {
        LOG_ERROR("SDL_BlitSurface failed! SDL_Error");
        LOG_ERROR("{}", SDL_GetError());
        return;
    }
    m_Texture = std::make_unique<Core::Texture>(
        Core::SdlFormatToGlFormat(sub_surface->format->format), sub_surface->w,
        sub_surface->h, sub_surface->pixels);
}
void Image_magic::SetImage(const std::string &filepath) {
    auto surface = s_Store.Get(filepath);

    m_Texture->UpdateData(Core::SdlFormatToGlFormat(surface->format->format),
                          surface->w, surface->h, surface->pixels);
    m_Size = {surface->w, surface->h};
}

void Image_magic::Draw(const Core::Matrices &data) {
    m_UniformBuffer->SetData(0, data);

    m_Texture->Bind(UNIFORM_SURFACE_LOCATION);
    s_Program->Bind();
    s_Program->Validate();

    s_VertexArray->Bind();
    s_VertexArray->DrawTriangles();
}

void Image_magic::InitProgram() {
    // TODO: Create `BaseProgram` from `Program` and pass it into `Drawable`
    s_Program =
        std::make_unique<Core::Program>(PTSD_ASSETS_DIR "/shaders/Base.vert",
                                        PTSD_ASSETS_DIR "/shaders/Base.frag");
    s_Program->Bind();

    GLint location = glGetUniformLocation(s_Program->GetId(), "surface");
    glUniform1i(location, UNIFORM_SURFACE_LOCATION);
}

void Image_magic::InitVertexArray() {
    s_VertexArray = std::make_unique<Core::VertexArray>();

    // NOLINTBEGIN
    // These are vertex data for the rectangle but clang-tidy has magic
    // number warnings

    // Vertex
    s_VertexArray->AddVertexBuffer(std::make_unique<Core::VertexBuffer>(
        std::vector<float>{
            -0.5F, 0.5F,  //
            -0.5F, -0.5F, //
            0.5F, -0.5F,  //
            0.5F, 0.5F,   //
        },
        2));

    // UV
    s_VertexArray->AddVertexBuffer(std::make_unique<Core::VertexBuffer>(
        std::vector<float>{
            0.0F, 0.0F, //
            0.0F, 1.0F, //
            1.0F, 1.0F, //
            1.0F, 0.0F, //
        },
        2));

    // Index
    s_VertexArray->SetIndexBuffer(
        std::make_unique<Core::IndexBuffer>(std::vector<unsigned int>{
            0, 1, 2, //
            0, 2, 3, //
        }));
    // NOLINTEND
}

std::unique_ptr<Core::Program> Image_magic::s_Program = nullptr;
std::unique_ptr<Core::VertexArray> Image_magic::s_VertexArray = nullptr;

Util::AssetStore<std::shared_ptr<SDL_Surface>> Image_magic::s_Store(LLoadSurface);
}// namespace RUtil
