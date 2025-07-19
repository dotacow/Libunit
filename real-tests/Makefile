LIBUDIR   = ../framework
LIBFTDIR  = ../libft
ODIR      = ofiles

LIBU      = $(LIBUDIR)/libunit.a
LIBFT     = $(LIBFTDIR)/libft.a

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -I$(LIBUDIR) -I$(LIBFTDIR) -g

SRCS      = main.c 00_launcher.c 01_empty_file.c 02_alternating_lines.c 03_alternating_nl.c 04_no_newline.c 05_only_newline.c 06_newline_at_start.c \
			07_single_character_nl.c 08_big_file.c 09_invalid_file.c 10_invalid_perms.c 11_long_line_no_nl.c 12_long_line_nl.c \
			 13_only_whitespaces.c 14_literal_nl.c 15_single_character.c
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
