cmake_minimum_required(VERSION 3.30)

# Variables
set(CMAKE_CXX_STANDARD 23)

# Define source
file(GLOB PROJECT_SRC
  src/*.cpp
)

# Project
project(WTools)
add_library(${PROJECT_NAME} ${PROJECT_SRC})

# Includes
target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# Linking
target_link_libraries(${PROJECT_NAME}
)