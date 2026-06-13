/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:34:56 by hakama            #+#    #+#             */
/*   Updated: 2025/09/25 14:36:42 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*last;

	last = (void *) 0;
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
