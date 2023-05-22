/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:34:50 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/16 19:34:52 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_line(char *stack)
{
	char	*line;
	int		i;

	if (!stack || !*stack)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
			i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	char	*new_stack;
	char	*tmp;
	int		i;

	tmp = ft_strchr(stack, '\n');
	if (!tmp)
	{
		free(stack);
		return (NULL);
	}
	tmp++;
	new_stack = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!new_stack)
		return (NULL);
	i = 0;
	while (*tmp != '\0')
	{
		new_stack[i] = *tmp;
		i++;
		tmp++;
	}
	new_stack[i] = '\0';
	free(stack);
	return (new_stack);
}

char	*join_and_free(char *stack, char *tmp)
{
	char	*aux;

	if (!stack)
	{
		stack = malloc(1);
		stack[0] = '\0';
	}
	if (!stack)
		return (NULL);
	aux = ft_strjoin(stack, tmp);
	free (stack);
	return (aux);
}

//ssize_t Used for a count of bytes or error indication.
char	*get_next_line(int fd)
{
	static char	*stack;
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readbytes = 1;
	while (!(ft_strchr(stack, '\n')) && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(stack), stack = NULL, NULL);
		tmp[readbytes] = '\0';
		stack = join_and_free(stack, tmp);
		if (!stack)
			return (NULL);
	}
	line = ft_create_line(stack);
	stack = update_stack(stack);
	return (line);
}
