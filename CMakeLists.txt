cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(LastFMApi)

set(SOURCES
    src/LastFmApi.cpp
    src/album.cpp
    src/artist.cpp
    src/track.cpp
    src/test.cpp
)

set(INCLUDE
    src/LastFmApi.hpp
    src/utils.hpp
)

add_library(${PROJECT_NAME} ${SOURCES} ${INCLUDE})

# add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} -lcurl -ltinyxml2)


