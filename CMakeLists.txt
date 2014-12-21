cmake_minimum_required( VERSION 2.6 )

project( spacerocks2 )
file( GLOB SOURCE_FILES src/*.c )
set( CMAKE_CXX_FLAGS_DEBUG )
set( CMAKE_C_FLAGS_DEBUG )
set( CMAKE_BUILD_TYPE Debug )
add_executable( spacerocks2 ${SOURCE_FILES} )
target_link_libraries( spacerocks2 -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer )
