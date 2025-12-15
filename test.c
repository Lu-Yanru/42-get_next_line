/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:53:46 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/15 15:36:04 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test3.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	printf("%s", line);
	free(line);
	close(fd);
}
