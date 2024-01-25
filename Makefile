NAME	:= cub3d
CFLAGS	:= #-Wextra -Wall -Werror 
LIBMLX	:= ./libs/MLX42
LIBS_NAME	:= $(LIBMLX)/build/libmlx42.a 
LFT_NAME = libft.a
LFT_DIR = ./libs/libft
LFT = $(LFT_DIR)/$(LFT_NAME)

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS = cub3d.c parsing.c get_next_line.c \
		get_next_line_utils.c hooks.c \
		find_positions.c minimap.c
OBJS	:= ${SRCS:.c=.o}
LFT_O := $(shell find $(LFT_DIR) -iname "*.o") 

all: $(NAME)

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