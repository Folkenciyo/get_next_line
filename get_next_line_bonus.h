/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 07:08:59 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/19 07:09:06 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef FD_MAX
#  define FD_MAX 4096

# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
// Donde se encuentra ssize_t
//(que es un tipo de dato para indicar errores) y size_t

char	*get_next_line(int fd);
char	*ft_create_line(char *stack);
char	*update_stack(char *stack);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
