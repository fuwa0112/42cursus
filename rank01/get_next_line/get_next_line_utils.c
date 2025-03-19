/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:28:20 by thitoe            #+#    #+#             */
/*   Updated: 2025/03/20 03:15:23 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	my_bzero_gnl(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = 0;
}

int	my_getchar(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			my_bzero_gnl(buf, BUFFER_SIZE);
			bufp = NULL;
			n = 0;
			return (0);
		}
		if (n == 0)
			return (EOF);
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char)*bufp++);
	return (EOF);
}

void	*my_memcpy_gnl(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

int	my_putc(t_string *str, char c)
{
	size_t	new_capa;
	char	*new_str;

	if (str->len + 1 > str->capa)
	{
		if (str->capa == 0)
			new_capa = 1;
		else
			new_capa = str->capa * 2;
		new_str = (char *)malloc(new_capa);
		if (!new_str)
			return (-1);
		if (str->str)
		{
			my_memcpy_gnl(new_str, str->str, str->len);
			free(str->str);
		}
		str->str = new_str;
		str->capa = new_capa;
	}
	str->str[str->len++] = c;
	return (0);
}
