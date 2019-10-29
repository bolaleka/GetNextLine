/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolaleka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:01:36 by bolaleka          #+#    #+#             */
/*   Updated: 2019/06/23 12:36:30 by bolaleka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	**line;
	int		gnlret;
	int		linecount;

	linecount = 0;
	gnlret = 1;
	fd = open(argv[1], O_RDONLY);
	printf("Argc: %d\n", argc);
	printf("File to open: %s\n", argv[1]);
	line = ft_memalloc(sizeof(char **));
	printf("BUFF_SIZE: %d\n\n", BUFF_SIZE);
	if (fd >= 0)
		printf("fd_len: %d\n", fd);
	while ((get_next_line(fd, line)) > 0)
	{
		printf("linecount : %d ", linecount);
		printf("%s\n", *line);
		linecount++;
	}
	printf("Line count: %d\n", linecount);
	printf("Finished\n\n");
	close(fd);
	return (0);
}
