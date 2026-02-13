/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:28:17 by thitoe            #+#    #+#             */
/*   Updated: 2025/03/20 03:51:41 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			c;
	t_string	ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;
	while (1)
	{
		c = my_getchar(fd);
		if (c == 0)
			return (free(ret.str), NULL);
		if (c == EOF)
			break ;
		if (my_putc(&ret, c) != 0)
			return (free(ret.str), NULL);
		if ((char)c == '\n')
			break ;
	}
	if (ret.len == 0 && c == EOF)
		return (free(ret.str), NULL);
	if (my_putc(&ret, '\0') != 0)
		return (free(ret.str), NULL);
	return (ret.str);
}
