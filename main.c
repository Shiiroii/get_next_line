/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:40:44 by liulm             #+#    #+#             */
/*   Updated: 2024/11/05 16:08:58 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror ("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
