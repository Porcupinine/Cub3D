cmake_minimum_required(VERSION 3.21.0)
project(Cub3D)

set(CMAKE_C_STANDARD 90)

#add_compile_options(-fsanitize=address -fsanitize=leak)
#add_link_options(-fsanitize=address -fsanitize=leak)
add_subdirectory(${CMAKE_SOURCE_DIR}/MLX42)
include_directories(${CMAKE_SOURCE_DIR}/lib42/include)

SET(SOURCES
      src/parsing/parsing.c)

add_executable(cub3d main.c ${SOURCES} )
set_target_properties(cub3d PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(cub3d ${CMAKE_SOURCE_DIR}/lib42/libft.a mlx42)


add_executable(test_cub3d ${SOURCES} test/main.c)
target_link_libraries(test_cub3d ${CMAKE_SOURCE_DIR}/lib42/libft.a mlx42)
