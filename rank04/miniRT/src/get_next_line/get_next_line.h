/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:28:23 by thitoe            #+#    #+#             */
/*   Updated: 2025/03/20 03:15:27 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

void		my_bzero_gnl(void *s, size_t n);
int			my_getchar(int fd);
void		*my_memcpy_gnl(void *dest, const void *src, size_t n);
int			my_putc(t_string *str, char c);
char		*get_next_line(int fd);

#endif
