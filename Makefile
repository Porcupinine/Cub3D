NAME	:= cub3d
CFLAGS	:= #-Wextra -Wall -Werror 
LIBMLX	:= ./MLX42
LIBS_NAME	:= $(LIBMLX)/build/libmlx42.a 
LFT_NAME = libft.a
LFT_DIR = ./lib42
LFT = $(LFT_DIR)/$(LFT_NAME)

HEADERS	:= -I ./includes -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS =	hooks.c \
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
		src/calculations/positive_double.c \
		lib42/get_next_line/get_next_line.c \
		lib42/get_next_line/get_next_line_utils.c \
		lib42/get_next_line/get_next_line_exit.c \
		minimap.c \
		
OBJS	:= ${SRCS:.c=.o}

#---------------------------------------------------------------------Directory
OBJ_DIR := objs/
OBJECTS_PREFIXED := $(addprefix $(OBJ_DIR), $(OBJS))

#-------------------------------------------------------------------------Rules
all: $(NAME)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

LFT_O := $(shell find $(LFT_DIR) -iname "*.o") 

$(LIBS_NAME):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -sC $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "Compiling.. "

$(NAME): $(LFT) $(LIBS_NAME) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(LFT) $(HEADERS) -o $(NAME)

$(LFT):
	make all -sC $(LFT_DIR) 

clean:
	@rm -f $(OBJS)
	@rm -f $(LIBMLX)/build/libmlx42.a
	@rm -f $(LFT_O)
	@rm -f $(LFT)

fclean: clean
	@rm -f $(NAME)

debug:	
	-fsanitize=address ./cub3d

norm:
	norminette ./src ./libs/libft fdf.c

re: clean all

.PHONY: all, clean, fclean, re