#ifndef RUTIL_CARDS_IMAGE_HPP
#define RUTIL_CARDS_IMAGE_HPP

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
class Cards_Image{
public:
    
private:
    void InitProgram();
    void InitVertexArray();
    static constexpr int UNIFORM_SURFACE_LOCATION = 0;
    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    std::unique_ptr<Core::UniformBuffer<Core::Matrices>> m_UniformBuffer;
    static std::unique_ptr<std::vector<Core::Texture>> m_Card_Textures = nullptr;
};
}
#endif