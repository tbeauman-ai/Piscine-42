/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:39:23 by nmauvari          #+#    #+#             */
/*   Updated: 2024/09/01 14:34:01 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	free_tbuf_segments(t_buf **strt)
{
	t_buf	*nxt;
	t_buf	*p;

	p = *strt;
	while (p)
	{
		nxt = p->next;
		if (p->p)
			free(p->p);
		free(p);
		p = nxt;
	}
	*strt = NULL;
}

int	add_segment(t_buf **last)
{
	t_buf	*p;

	p = malloc(sizeof(t_buf));
	if (!p)
		return (ERR_MALLOC);
	p->next = NULL;
	p->p = malloc(BUF_SZ);
	if (!p->p)
	{
		free(p);
		return (ERR_MALLOC);
	}
	p->p[0] = 0;
	*last = p;
	return (0);
}

int	has_linebrk(char *str, ssize_t len)
{
	while (len--)
		if (str[len] == '\n')
			return (1);
	return (0);
}

t_buf	**get_last(t_buf **prev)
{
	t_buf	*last;

	if (*prev)
	{
		last = *prev;
		while (last->next)
			last = last->next;
		return (&(last->next));
	}
	return (prev);
}

int	get_line(int fd, t_buf **prev)
{
	int		ret;
	ssize_t	red;
	t_buf	**last;

	last = get_last(prev);
	red = 1;
	while (red > 0)
	{
		last = get_last(last);
		ret = add_segment(last);
		if (ret)
			break ;
		red = read(fd, (*last)->p, BUF_SZ);
		(*last)->len = red * (red >= 0);
		(*last)->i = 0;
		if (has_linebrk((*last)->p, (*last)->len) || \
			((*last)->len < BUF_SZ && red >= 0))
			break ;
	}
	if (ret > 0)
		free_tbuf_segments(prev);
	return (!!ret * ERR_MALLOC | \
			(red < 0) * ERR_FREAD | \
			(red == 0) * ERR_DONE);
}
