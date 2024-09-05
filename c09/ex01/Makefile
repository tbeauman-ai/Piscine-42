CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRCS= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS= srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
NAME= libft.a
HEADERS= includes/

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADERS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
