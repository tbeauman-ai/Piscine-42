/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:30:28 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/02 12:33:34 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 8192

typedef struct s_map
{
	int			height;
	int			width;
	char		**grid;
	char		obst;
	char		empty;
	char		full;
}				t_map;

typedef struct s_solver
{
	int			*grid;
	int			i;
	int			j;
	int			prev;
	int			tmp;
	int			max[3];

}				t_solver;

typedef struct s_grid_coords
{
	int			**grid;
	int			y;
	int			x;
}				t_grid_coords;

unsigned int	ft_bsq_atoi(char *str);

char			free_map(t_map *map, int i);
char			free_maps(t_map **maps, int size);
char			free_grid(char **grid, int size);
char			clear_file(int fd, char *line);
char			rfree(void *ptr);

int				ft_strlen(char *str);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char *s1, char *s2);
void			print_grid(t_map *map);
void			print_final_grid(t_map *map, int size, int x, int y);

void			ft_putstr(char *s);
int				ft_puterr(char *s);
char			*ft_strchr(const char *s, int c);
int				*ft_gridnew(size_t size);

char			*ft_strdup(char *src);
int				get_next_line(int fd, char **line);

int				init_map(t_map **ret, char *fline);

void			*ft_memmove(void *dst, const void *src, size_t len);
void			*bsq_memcpy(void *dst, const void *src, size_t n, t_map *map);

t_map			*parse_file(char *filename);
t_map			*parse_stdin(void);

int				solve(t_map *map);
void			print_grid(t_map *map);

#endif
