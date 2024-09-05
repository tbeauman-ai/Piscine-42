/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:31:52 by ande-vat          #+#    #+#             */
/*   Updated: 2024/09/01 14:32:57 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_buf	*free_segment(t_buf *seg)
{
	t_buf	*nxt;

	nxt = seg->next;
	free(seg->p);
	free(seg);
	return (nxt);
}

size_t	line_len(t_buf *segment)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (segment)
	{
		i = segment->i;
		while (i < segment->len && segment->p[i] != '\n')
			i++;
		len += i - segment->i;
		if ((i < segment->len && segment->p[i] == '\n') || \
			(i == segment->len && i < BUF_SZ))
			return (len);
		segment = segment->next;
	}
	return (0);
}

t_buf	*fill_string(size_t len, t_buf *seg, char *str)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (len)
	{
		i = seg->i;
		while (i < seg->len && seg->p[i] != '\n')
			str[j++] = seg->p[i++];
		len -= i - seg->i;
		seg->i = i + (i < seg->len && seg->p[i] == '\n');
		if (seg->i == seg->len)
			seg = free_segment(seg);
	}
	return (seg);
}

t_buf	*skip_empty_lines(t_buf *seg)
{
	while (seg && \
			(!seg->p || seg->p[seg->i] == '\n'))
	{
		while (seg->i < seg->len && \
				seg->p[seg->i] == '\n')
			seg->i++;
		if (seg->i == seg->len)
			seg = free_segment(seg);
	}
	return (seg);
}
