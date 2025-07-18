CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
SRCS = ft_strlcat.c ft_split.c ft_strtrim.c ft_striteri.c ft_strmapi.c ft_strjoin.c \
       ft_itoa.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c \
       ft_strlcpy.c ft_substr.c ft_strdup.c ft_calloc.c ft_memmove.c ft_isdigit.c \
       ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
       ft_bzero.c ft_memcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c \
       ft_memchr.c ft_memcmp.c ft_strrchr.c ft_strnstr.c ft_atoi.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS := $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
             ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
             ft_lstclear_bonus.c ft_lstiter_bonus.c
BONUS_SRCS := $(addprefix $(SRC_DIR)/, $(BONUS_SRCS))
OBJ_B := $(BONUS_SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(OBJ_B)
	ar rcs $(NAME) $(OBJS) $(OBJ_B)

clean:
	rm -f $(OBJS) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
