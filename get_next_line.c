/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:49:17 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/12 17:09:24 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_rest(char *stash)
{
	char	*rest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	rest = malloc(((ft_strlen(stash) - i) + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

static char	*fill_line(char *stash)
{
	char	*line;
	size_t	len;
	size_t	i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	len = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	line = malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_buf(int fd, char *stash)
{
	char	*buf;
	int		bytes_rd;

	bytes_rd = 1;
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (bytes_rd > 0)
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd < 0 || (bytes_rd == 0 && stash == NULL))
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes_rd] = '\0';
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n') != NULL)
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = read_buf(fd, stash);
	if (!stash)
		return (NULL);
	line = fill_line(stash);
	stash = get_rest(stash);
	return (line);
}
