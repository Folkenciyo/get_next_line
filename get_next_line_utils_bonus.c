/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 07:09:21 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/19 07:09:22 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Create a line object
 * 
 * @param stack => stack to be read
 * @return char* => line read from stack
 */
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str != NULL)
		i++;
	return (i);
}

/**
 * @brief Find the first occurence of c in str
 * 
 * @param str => string to be read
 * @param c => character to be found
 * @return char* => pointer to the first occurence of c in str
 */
char	*ft_strchr(const char *str, int c)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = (char *)str;
	while (tmp && *tmp != (char)c)
	{
		if (*tmp == '\0')
			return (NULL);
		tmp++;
	}
	return (tmp);
}

/**
 * @brief Create a line object
 * 
 * @param s1 => stack to be read
 * @param s2 =>	stack to be read
 * @return char* => line read from stack
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
