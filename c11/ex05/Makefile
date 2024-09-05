CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=main.c ft_putnbr.c ft_atoi.c ops.c
OBJS=main.o ft_putnbr.o ft_atoi.o ops.o
NAME=do-op
HEADERS= includes/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADERS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
