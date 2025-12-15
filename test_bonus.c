/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:53:46 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/15 19:25:16 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "get_next_line_bonus.h"

int	main(int argc, char *argv[])
{
	int		fd[argc - 1];
	char	*line;
	int		i;

	i = 0;
	if (argc < 2)
	{
		printf("Please provide a file name.");
		return (0);
	}
	printf("%i\n", OPEN_MAX);
	while (i + 1 < argc)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
	i = 0;
	while (i + 1 < argc)
	{
		printf("==== Printing file %s, fd: %i ======\n", argv[i + 1], fd[i]);
		while ((line = get_next_line(fd[i])))
		{
			printf("%s", line);
			free(line);
		}
		printf("%s", line);
		free(line);
		printf("==== Finished printing file %s ======\n", argv[i + 1]);
		i++;
	}
	i = 0;
	while (i + 1 < argc)
	{
		close(fd[i]);
		i++;
	}
}
