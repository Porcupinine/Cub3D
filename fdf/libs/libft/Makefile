CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

SPARKLE_COLOUR = \u001b[35m
SUNNY_COLOUR = \u001b[33m
BACK_TO_NORMAL = \u001b[0m


SRCS = ft_tolower.c	ft_toupper.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_strlcat.c ft_strchr.c ft_memmove.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c
	
OBJS = ft_tolower.o	ft_toupper.o ft_isalnum.o ft_isalpha.o \
	ft_isascii.o ft_isdigit.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o \
	ft_memcpy.o ft_strlcat.o ft_strchr.o ft_memmove.o ft_strrchr.o ft_strncmp.o ft_strlcpy.o \
	ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o \
	ft_strjoin.o ft_strtrim.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putendl_fd.o ft_putnbr_fd.o ft_itoa.o ft_split.o

B_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

B_OBJS = ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o \
	ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo "${SPARKLE_COLOR} Done LIBFT compilation"

%.o: %.c
	@echo $< "done"
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(NAME) $(B_OBJS)
	@ar -rc $(NAME) $(B_OBJS)
	@echo "DONEEEEE BONUS"

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all bonus