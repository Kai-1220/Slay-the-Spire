# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/qsqss/Downloads/Slay-the-Spire/PTSD/lib/sdl2_image")
  file(MAKE_DIRECTORY "C:/Users/qsqss/Downloads/Slay-the-Spire/PTSD/lib/sdl2_image")
endif()
file(MAKE_DIRECTORY
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/sdl2_image-build"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/sdl2_image-subbuild/sdl2_image-populate-prefix"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/sdl2_image-subbuild/sdl2_image-populate-prefix/tmp"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/sdl2_image-subbuild/sdl2_image-populate-prefix/src/sdl2_image-populate-stamp"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/sdl2_image-subbuild/sdl2_image-populate-prefix/src"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/sdl2_image-subbuild/sdl2_image-populate-prefix/src/sdl2_image-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/sdl2_image-subbuild/sdl2_image-populate-prefix/src/sdl2_image-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/sdl2_image-subbuild/sdl2_image-populate-prefix/src/sdl2_image-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
