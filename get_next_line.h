/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:40:20 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/16 19:40:22 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
char	*ft_create_line(char *stack);
char	*update_stack(char *stack);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
