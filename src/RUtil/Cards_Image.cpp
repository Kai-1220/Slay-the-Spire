// #include "RUtil/Cards_Image.hpp"
// #include "pch.hpp"
// #define card1_path RESOURCE_DIR"/Image/cards/cards.png
// #define card2_path RESOURCE_DIR"/Image/cards/cards2.png
// #define card3_path RESOURCE_DIR"/Image/cards/cards3.png
// #define card4_path RESOURCE_DIR"/Image/cards/cards4.png
// #define card5_path RESOURCE_DIR"/Image/cards/cards5.png
// namespace RUtil {
// void RUtil::Cards_Image::InitProgram(){
//     s_Program =
//         std::make_unique<Core::Program>(PTSD_ASSETS_DIR "/shaders/Base.vert",
//                                         PTSD_ASSETS_DIR "/shaders/Base.frag");
//     s_Program->Bind();

//     GLint location = glGetUniformLocation(s_Program->GetId(), "surface");
//     glUniform1i(location, UNIFORM_SURFACE_LOCATION);
// }
// void RUtil::Cards_Image::Init_Card_Textures(){
//     s_Card_Textures.push_back(std::make_unique<)
// }
// }