#include "RUtil/Cards_Image.hpp"
#include "pch.hpp"

namespace RUtil {
void RUtil::Cards_Image::InitProgram(){
    s_Program =
        std::make_unique<Core::Program>(PTSD_ASSETS_DIR "/shaders/Base.vert",
                                        PTSD_ASSETS_DIR "/shaders/Base.frag");
    s_Program->Bind();
    
    GLint location = glGetUniformLocation(s_Program->GetId(), "surface");
    glUniform1i(location, UNIFORM_SURFACE_LOCATION);
}
}