# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 17:34:21 by tbeauman          #+#    #+#              #
#    Updated: 2024/09/04 17:34:24 by tbeauman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Wextra -Werror -g3
SRCFOLDER= ./srcs/
SRCS= $(addprefix $(SRCFOLDER),	\
atoi.c \
free_tools.c \
ft_utils2.c \
ft_utils.c \
get_next_line.c \
init_map.c \
main.c \
mem_utils.c \
parse_files.c \
solver.c)

OBJS=${SRCS:.c=.o}
NAME=bsq
HEADERS= includes/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o ${<:.c=.o} $< -I $(HEADERS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
