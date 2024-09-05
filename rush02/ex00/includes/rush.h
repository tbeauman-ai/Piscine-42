/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:36:49 by nmauvari          #+#    #+#             */
/*   Updated: 2024/09/01 17:37:52 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define DEFAULT_DICTIONARY "./numbers.dict"

typedef struct s_dict	t_dict;
struct	s_dict
{
	union
	{
		char	*load_this;
		char	*nb_key;
		char	*nb_digits;
	};
	char	*nb_str;
	t_dict	*next;
};

# define DIG_GROUP 4
# define DIG_GRP_NUL 3
# define POW0 2
# define POW1 1
# define POW2 0
# define UNASSIGNED_STR "unassigned"

# define BUFFER_SIZE 1024
# define BUF_SZ BUFFER_SIZE

typedef struct s_buffer	t_buf;
struct	s_buffer
{
	char	*p;
	size_t	i;
	size_t	len;
	t_buf	*next;
};

# define SUCCESS 0
# define ERR_ARGNUM 1
# define ERR_ARGVAL 2
# define ERR_ARGVAL_MSG "Error\n"
# define ERR_ARGVAL_LEN 6
# define ERR_MALLOC 3
# define ERR_FOPEN 4
# define ERR_FREAD 5
# define ERR_BADINPUT 6
# define ERR_DICT 7
# define ERRMSG_GENERIC "Error\n"
# define ERRMSG_DICT "Dict error\n"
# define ERR_DONE -1

int		add_dic_node(t_dict *anchor, char *str);
int		do_error(int errcode);
void	init(t_dict *dic_anchor);
t_buf	*fill_string(size_t len, t_buf *segment, char *str);
int		filter_dic_lines(t_dict *previous);
void	free_dic(t_dict *dic);
t_dict	*free_dic_node(t_dict *node);
t_buf	*free_segment(t_buf *seg);
void	free_tbuf_segments(t_buf **strt);
int		get_line(int fd, t_buf **prev);
size_t	line_len(t_buf *segment);
int		load_dic(t_dict *anchor);
int		process_args(int ac, char **av, t_dict *dic_a);
t_buf	*skip_empty_lines(t_buf *seg);

#endif
