/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 02:46:39 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/19 02:46:42 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = argc;
	fd = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			printf("\033[0;91mOpen file failed!\n");
		else
		{
			line = get_next_line(fd);
			printf("The line is:\n \033[1;2;3;96m%s\033[0;39m", line);
			free(line);
			i--;
		}
	}
	return (0);
}
