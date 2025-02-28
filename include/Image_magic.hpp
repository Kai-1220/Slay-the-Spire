#ifndef UTIL_IMAGE_MAGIC_HPP
#define UTIL_IMAGE_MAGIC_HPP

#include "pch.hpp" // IWYU pragma: export

#include <glm/fwd.hpp>

#include "Core/Drawable.hpp"
#include "Core/Program.hpp"
#include "Core/Texture.hpp"
#include "Core/UniformBuffer.hpp"
#include "Core/VertexArray.hpp"

#include "Util/AssetStore.hpp"
#include "Util/Transform.hpp"

namespace RUtil {
class Image_magic : public Core::Drawable {
public:
    /**
     * @brief Constructor that takes a file path to the image.
     *
     * @param filepath The file path to the image.
     */
    explicit Image_magic(const std::string &filepath);

    /**
     * @brief Retrieves the size of the image.
     *
     * This function returns the size of the image.
     *
     * @return The size of the image as a vec2(x, y).
     */
    glm::vec2 GetSize() const override { return m_Size; };

    /**
     * @brief Retrieves the size of the inside image.
     */
    glm::vec2 Get_small_Size() const { return small_Size; };
    /**
     * @brief Retrieves the start position of the inside image.
     */
    glm::vec2 Get_small_Pos() const { return small_Pos; };
    /**
     * @brief Sets the inside image size.
     * @param small_Size The size of the inside image.
     */
    void Set_small_Size(const glm::vec2& small_Size);
    /**
     * @brief Sets the where the inside image start.
     * @param small_Pos The start position of the inside image.
     */
    void Set_small_Pos(const glm::vec2& small_Pos);
    /**
     * @brief Sets the image to the specified file path.
     *
     * This function sets the image to the specified file path.
     *
     * @param filepath The file path to the image.
     */
    void SetImage(const std::string &filepath);

    /**
     * @brief Draws the image with a given transform and z-index.
     *
     * This function draws the image at the specified z-index and applies the
     * given transform.
     *
     * @param transform The transform to apply to the image.
     * @param zIndex The z-index at which to draw the image.
     */
    void Draw(const Core::Matrices &data) override;

private:
    void InitProgram();
    void InitVertexArray();
    void InitUniformBuffer();
    
    void Reload_texture();

    static constexpr int UNIFORM_SURFACE_LOCATION = 0;

    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    std::unique_ptr<Core::UniformBuffer<Core::Matrices>> m_UniformBuffer;

    static Util::AssetStore<std::shared_ptr<SDL_Surface>> s_Store;

private:
    std::unique_ptr<Core::Texture> m_Texture = nullptr;
    
    std::string m_Path;
    glm::vec2 m_Size,small_Size,small_Pos;
};
}

#endif
