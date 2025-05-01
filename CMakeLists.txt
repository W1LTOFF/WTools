cmake_minimum_required(VERSION 3.30)

# Variables
set(CMAKE_CXX_STANDARD 23)

# Define source
file(GLOB WTOOLS_SRC
  src/*.cpp
)

# Project
project(wtools)
add_library(${PROJECT_NAME} ${WTOOLS_SRC})

# Subdirectories
# add_subdirectory(external/fmt)
# add_subdirectory(external/glm)
# add_subdirectory(external/SDL EXCLUDE_FROM_ALL)

# Found packages
# find_package(Vulkan REQUIRED)

# Check vulkan version

# Lib directories
link_directories(${PROJECT_SOURCE_DIR}/lib)

# Includes
target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/src
)

# Linking
target_link_libraries(${PROJECT_NAME}
)