cmake_minimum_required(VERSION 3.21.0)
project(Cub3D)

set(CMAKE_C_STANDARD 90)

#add_compile_options(-Wall -Wextra -Werror)
#add_compile_options(-fsanitize=address -fsanitize=leak)
#add_link_options(-fsanitize=address -fsanitize=leak)
add_subdirectory(${CMAKE_SOURCE_DIR}/MLX42)
include_directories(${CMAKE_SOURCE_DIR}/lib42/include)


SET(SOURCES
		minimap.c
		hooks.c
		src/parsing/parsing.c
		src/parsing/parse_textures.c
		src/parsing/parse_map.c
		src/utils/empty_line.c
		src/utils/first_map_line.c
		src/utils/print_data.c
		src/utils/all_digits.c
		src/utils/remove_new_line.c
		src/utils/rgba.c
		src/checkers/check_map.c
		src/calculations/positive_double.c
		src/checkers/check_data.c
		src/graphics/load_walls.c
		findRayAttr.c
		src/utils/init_cub.c
		src/graphics/draw_map.c
		src/graphics/drawing3d.c)

add_executable(cub3d main.c ${SOURCES}
        src/graphics/find_coordinates.c)
set_target_properties(cub3d PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(cub3d ${CMAKE_SOURCE_DIR}/lib42/libft.a mlx42 m)


add_executable(test_cub3d ${SOURCES} testers/test_parser.c)
target_link_libraries(test_cub3d ${CMAKE_SOURCE_DIR}/lib42/libft.a mlx42 m)

#-------------------------------------------------------------------------
#add_custom_target(BuildTheLib ALL
#COMMAND make ...
## (as you have now)
#)
#
#add_library(TheLib STATIC IMPORTED)
#set_target_properties(TheLib
#IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/path/to/lib.a # Make sure to use absolute path here
#INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/lib_include
#INTERFACE_COMPILE_DEFINITIONS "USING_THELIB;THELIB_STATIC"
#)
#add_dependencies(TheLib BuildTheLib) # So that anyone linking against TheLib causes BuildTheLib to build first
#
#target_link_libraries(MY_TARGET PRIVATE TheLib)