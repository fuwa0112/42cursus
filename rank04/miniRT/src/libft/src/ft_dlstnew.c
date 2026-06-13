/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:18:09 by hakama            #+#    #+#             */
/*   Updated: 2025/09/25 14:18:50 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	new = (t_dlist *) malloc(sizeof(t_dlist));
	if (!new)
		return ((void *) 0);
	new->content = content;
	new->next = (void *) 0;
	new->prev = (void *) 0;
	return (new);
}
