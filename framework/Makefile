CC = cc
CFLAGS = -Wall -Wextra -Werror

# Static library
NAME = libunit.a
ARFLAGS = rcs
SRCS = unit.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar $(ARFLAGS) $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

