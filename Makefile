#--------------------------------------------------------------------Executable
NAME := cub3d

#----------------------------------------------------------------------Compiler
CC := cc

#-------------------------------------------------------------------------Flags
CFLAGS	+= -Wextra -Wall -Werror -O3 -fsanitize=address
ASANFLAGS += -fsanitize=address -fsanitize=leak

#----------------------------------------------------------------Libraries path
LIBMLX	:= ./MLX42
LIB42   := ./lib42

#-----------------------------------------------------------------------Headers
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIB42)/include

#---------------------------------------------------------------------Libraries
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -fPIE -lm $(LIB42)/libft.a

#------------------------------------------------------------------------Source
SRC		:= main.c \
				src/utils/empty_line.c \
        		src/utils/first_map_line.c \
        		src/utils/print_data.c \
        		src/utils/all_digits.c \
        		src/utils/remove_new_line.c \
        		src/utils/rgba.c \
        		src/checkers/check_map.c \
        		src/checkers/check_data.c \
        		src/raycasting/positive_double.c \
        		src/raycasting/raycasting.c \
        		src/raycasting/findRayAttr.c \
        		src/graphics/images.c \
        		src/hooks/rotate.c \
        		src/hooks/hooks.c \
        		src/hooks/move.c \
        		src/graphics/minimap.c \
        		src/graphics/draw_map.c \
        		src/graphics/load_walls.c \
        		src/graphics/find_coordinates.c \
        		src/utils/free.c \
        		src/utils/copy_file.c \
        		src/utils/clean_up.c \
        		src/parsing/parsing.c \
        		src/parsing/parse_textures.c \
        		src/parsing/parse_map.c

#-----------------------------------------------------------------------Objects
OBJS	:= ${SRC:.c=.o}

#---------------------------------------------------------------------Directory
OBJ_DIR := objs/
OBJECTS_PREFIXED := $(addprefix $(OBJ_DIR), $(OBJS))

#-------------------------------------------------------------------------Rulall: $(NAME)

all: $(NAME)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ -c $< $(HEADERS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

lib42_build:
	@$(MAKE) -C $(LIB42)

$(NAME): libmlx lib42_build $(OBJECTS_PREFIXED)
	@$(CC) $(OBJECTS_PREFIXED) $(LIBS) $(CFLAGS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIB42)/objs

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB42)/libft.a

re: clean all

.PHONY: all, clean, fclean, re, libmlx lib42_build