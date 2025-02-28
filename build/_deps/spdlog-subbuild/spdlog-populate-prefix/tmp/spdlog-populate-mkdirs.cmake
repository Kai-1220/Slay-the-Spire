# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/qsqss/Downloads/Slay-the-Spire/PTSD/lib/spdlog")
  file(MAKE_DIRECTORY "C:/Users/qsqss/Downloads/Slay-the-Spire/PTSD/lib/spdlog")
endif()
file(MAKE_DIRECTORY
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/spdlog-build"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/spdlog-subbuild/spdlog-populate-prefix"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/spdlog-subbuild/spdlog-populate-prefix/tmp"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src"
  "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/qsqss/Downloads/Slay-the-Spire/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
