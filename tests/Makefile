LIBUDIR   = ../framework
LIBFTDIR  = ../libft
ODIR      = ofiles

LIBU      = $(LIBUDIR)/libunit.a
LIBFT     = $(LIBFTDIR)/libft.a

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -I$(LIBUDIR) -I$(LIBFTDIR) -g

SRCS      = main.c 00_launcher.c 01_ok.c 02_ko.c 03_sigsev.c
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
