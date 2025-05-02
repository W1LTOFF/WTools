cmake_minimum_required(VERSION 3.30)

# Variables
set(CMAKE_CXX_STANDARD 23)

# Define source
file(GLOB WTOOLS_SRC
  src/*.cpp
)

# Project
project(Wtools)
add_library(${PROJECT_NAME} ${WTOOLS_SRC})

# Includes
target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# Linking
target_link_libraries(${PROJECT_NAME}
)