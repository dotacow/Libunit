LIBUDIR   = ../framework
LIBFTDIR  = ../libft
ODIR      = ofiles

LIBU      = $(LIBUDIR)/libunit.a
LIBFT     = $(LIBFTDIR)/libft.a

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -I$(LIBUDIR) -I$(LIBFTDIR) -g

SRCS      = gnl.c main.c 00_launcher.c 01_empty_file.c 08_big_file.c 07_single_character_nl.c 09_buffer_size_less_zero.c 10_buffer_size_zero.c 11_buffer_size_one.c
OBJS      = $(addprefix $(ODIR)/,$(SRCS:.c=.o))
NAME      = tester

all: $(LIBU) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBU) $(LIBFT) -o $(NAME)

$(ODIR)/%.o: %.c tests.h | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $(ODIR)

$(LIBU):
	$(MAKE) -C $(LIBUDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

test: all
	./$(NAME)

clean:
	rm -rf $(ODIR)
	$(MAKE) -C $(LIBUDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBUDIR) fclean
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all test clean fclean re
