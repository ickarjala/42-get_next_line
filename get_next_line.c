/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:45:37 by ikarjala          #+#    #+#             */
/*   Updated: 2022/02/10 19:41:47 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strclen(const char* str, int c)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		if (*str++ == c)
			break ;
		len++;
	}
	return (len);
}

int	get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	size_t		i_nl;
	ssize_t		bytes;

	if (!fd || !line)
		return (RET_ERROR);
	bytes = 0;
	if (!buf[BUFF_SIZE - 1])
		bytes = read(fd, buf, BUFF_SIZE);
	if (bytes == 0)
		return (RET_EOF);
	i_nl = ft_strclen(buf, '\n');
	if (*line)
		free(*line);
	*line = ft_strsub(buf, 0, i_nl);
	return (RET_READL);
}

// TODO: need a way to find where we left off if buffer is not empty
// gist: change each nl to null as we go
