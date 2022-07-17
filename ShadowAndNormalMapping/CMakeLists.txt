cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME Graphics)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(WINDOW_NAME )
set(WINDOW_WIDTH 960)
set(WINDOW_HEIGHT 540)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
endif()

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp src/common.cpp src/shader.cpp src/program.h src/program.cpp src/context.h src/context.cpp src/buffer.h src/buffer.cpp src/vertex_layout.h src/vertex_layout.cpp src/image.h src/image.cpp src/texture.h src/texture.cpp src/mesh.h src/mesh.cpp src/model.h src/model.cpp src/framebuffer.h src/framebuffer.cpp src/shadow_map.h src/shadow_map.cpp)

include(Dependency.cmake)

# 우리 프로젝트에 include / lib 관련 옵션 추가
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

target_compile_definitions(${PROJECT_NAME} PUBLIC
        WINDOW_NAME="${WINDOW_NAME}"
        WINDOW_WIDTH=${WINDOW_WIDTH}
        WINDOW_HEIGHT=${WINDOW_HEIGHT}
        )

# Dependency들이 먼저 build 될 수 있게 관계 설정
add_dependencies(${PROJECT_NAME} ${DEP_LIST})