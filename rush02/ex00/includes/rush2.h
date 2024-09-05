/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:26:55 by ande-vat          #+#    #+#             */
/*   Updated: 2024/09/01 21:29:51 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH2_H
# define RUSH2_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "rush.h"

typedef struct s_number
{
	char			str[3];
	int				pow;
	struct s_number	*next;
}					t_number;

typedef struct s_write
{
	char			*trim;
	char			tmp[3];
	t_dict			*found;
	int				n;
}					t_write;

int				ft_strlen(char *s);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
t_number		*parse_number(char *number);
void			free_tnumber_list(t_number *list);
void			ft_putstr(char *s);
int				write_number(t_number *nb, t_dict *variablearenommerdico);
char			*trim_zeroes(char *n);
int				ft_atoi(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strncat(char *dest, char *src, int n);
void			print_found_with_space(char *found);
int				is_last_paquet(t_number *nb);
int				is_positive_integer(char *number);
void			free_t_dict(t_dict *dico);
int				handle_tens(t_dict *dico, t_write *w);
int				handle_hundreds(t_dict *dico, t_write *w);
t_write			*init_t_write(t_number *nb);
t_number		*init_number(t_number *nb, char **number);
t_dict			*find_in_dico(char *nb_dg, t_dict *dico);
void			print_error(char *str);
char			*str_cat(char *s1, char *s2, int size);
char			**split_semicolon(char *str);
char			*strdup_pos(char *str, int start, int end);
char			*str_cat(char *s1, char *s2, int size);
int				str_len(char *str);
void			semi_trim_spaces(t_dict *dico);
void			fix_plus(t_dict *dico);

#endif