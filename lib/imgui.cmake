#---------------------------------------------------------------------------------------------------------------------
#   XMidiCtrl - A MIDI Controller plugin for X-Plane 11
#   Copyright (c) 2021 Marco Auer <marco@marcoauer.de>
#
#   MIT License
#
#   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
#   documentation files (the "Software"), to deal in the Software without restriction, including without limitation
#   the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
#   to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be included in all copies or substantial portions of
#   the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
#   THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
#   CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
#   IN THE SOFTWARE.
#---------------------------------------------------------------------------------------------------------------------

# Static library for Dear ImGui
message("-- Configuring build scripts for Dear ImGui")

# Find OpenGL
include(FindOpenGL)

# Add sources
set(IMGUI_SRC ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui.cpp
              ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_demo.cpp
              ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_draw.cpp
              ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_tables.cpp
              ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_widgets.cpp
              ${CMAKE_CURRENT_LIST_DIR}/imgui/misc/cpp/imgui_stdlib.cpp)

# Set global variable with include directory
set(IMGUI_INCLUDEDIR ${CMAKE_CURRENT_LIST_DIR}/imgui PARENT_SCOPE)

# Build static library
add_library(imgui STATIC ${IMGUI_SRC})

# Add custom config file
message("---- Set config file to ${CMAKE_CURRENT_LIST_DIR}/imgui_config.h")
target_compile_definitions(imgui PRIVATE -DIMGUI_USER_CONFIG="${CMAKE_CURRENT_LIST_DIR}/imgui_config.h")

# Link required libraries
target_link_libraries(imgui PUBLIC OpenGL::GL)

# Include directories to target
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_LIST_DIR}/imgui)
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_LIST_DIR}/imgui/misc/cpp)