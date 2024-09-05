/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:37:22 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/03 17:42:06 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strdup(char *src)
{
	char	*ret;
	char	*tmp;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret)
		return (0);
	tmp = ret;
	while (*src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = 0;
	return (ret);
}

int	remplis_line(char **line, char *lignes)
{
	char	*str;
	char	tmp;

	str = ft_strchr(lignes, '\n');
	if (str)
	{
		tmp = str[1];
		str[1] = 0;
		*line = ft_strdup(lignes);
		str[1] = tmp;
		if (!*line)
			return (-1);
		if (!ft_memmove(lignes, &str[1], ft_strlen(&str[1]) + 1))
			return (-1);
		return (1);
	}
	if (ft_strlen(lignes) > 0)
	{
		*line = ft_strdup(lignes);
		if (!*line)
			return (-1);
		*lignes = 0;
		return (1);
	}
	return (0);
}

char	*join_buffers(char *buf, char **ligne)
{
	char	*tmp;

	tmp = ft_strjoin(*ligne, buf);
	free(*ligne);
	if (!tmp)
		return (0);
	*ligne = tmp;
	return (*ligne);
}

int	get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*lignes;
	int			rr;

	if (fd < 0 || fd > 255 || !line)
		return (-1);
	if (!lignes)
	{
		lignes = ft_strnew(1);
		if (!lignes)
			return (-1);
	}
	while (!ft_strchr(lignes, '\n'))
	{
		rr = read(fd, buf, BUFF_SIZE);
		if (rr < 0)
			return (-1);
		if (rr == 0)
			break ;
		buf[rr] = 0;
		if (!join_buffers(buf, &(lignes)))
			return (-1);
	}
	return (remplis_line(line, lignes));
}
