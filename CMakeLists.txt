cmake_minimum_required(VERSION 3.6)

if (NOT ANDROID)
  enable_language(CXX) # SINCE Compiler/Platform variables do not normally exist before a project command in CMake.
endif ()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(../cmake-tools/scripts/generator-key.cmake)

if (NOT MINGW)
  project(minkey)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif ()

include(../cmake-tools/cmake-tools.cmake)

add_subdirectory(projects/minkey)
add_subdirectory(projects/minkey_cli)

finish_mythic()
