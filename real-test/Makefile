LIBDIR =../framework/libunit/
LIB = $(LIBDIR)/libunit.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBDIR)

SRCS = main.c 00_launcher.c 01_ok.c 02_ko.c 03_sigsev.c


ODIR = ofiles
OFILES := $(addprefix ofiles/,$(notdir $(SRC:.c=.o)))

NAME = tester

ofiles/%.o: srcs/%.c includes/philo.h | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(OFILES) -o $(NAME) -fsanitize=thread

clean:
	rm -rf ofiles

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(ODIR):
	mkdir -p ofiles

.PHONY: dirs all clean fclean re