#--------------------------------------------------------------------Executable
NAME := cub3d

#----------------------------------------------------------------------Compiler
CC := cc

#-------------------------------------------------------------------------Flags
CFLAGS	+= -Wextra -Wall -Werror -O3 #-fsanitize=address
ASANFLAGS += -fsanitize=address -fsanitize=leak

#----------------------------------------------------------------Libraries path
LIBMLX	:= ./MLX42
LIB42   := ./lib42

#-----------------------------------------------------------------------Headers
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIB42)/include

#---------------------------------------------------------------------Libraries
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -fPIE -lm $(LIB42)/libft.a

#------------------------------------------------------------------------Source
SRC		:= hooks.c \
		main.c \
		src/parsing/parsing.c \
		src/parsing/parse_textures.c \
		src/parsing/parse_map.c \
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
		src/images/images.c \
		minimap.c \
		src/graphics/drawing3d.c \
		src/graphics/draw_map.c \

#-----------------------------------------------------------------------Objects
OBJS	:= ${SRC:.c=.o}

#---------------------------------------------------------------------Directory
OBJ_DIR := objs/
OBJECTS_PREFIXED := $(addprefix $(OBJ_DIR), $(OBJS))

#-------------------------------------------------------------------------Rules
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

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx lib42_build