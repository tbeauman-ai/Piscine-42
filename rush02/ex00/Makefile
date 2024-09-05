CC=cc
CFLAGS= -Wall -Wextra -Werror -g3
SRCFOLDER= ./srcs/
SRCS= $(addprefix $(SRCFOLDER), dictionary.c \
do_error.c \
filter_dic_lines.c \
free_all.c \
free.c \
ft_atoi.c \
ft_strcmp.c \
ft_strncat.c \
get_file_1.c \
get_file.c \
handle_three.c \
init.c \
init_structs.c \
load_dic.c \
main.c \
parse_number.c \
process_args.c \
semi_trim_spaces.c \
strings.c \
utils.c \
write_number.c \
writer_utils.c)
	
OBJS=${SRCS:.c=.o}
NAME=rush02
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

.PHONY: re clean fclean all
