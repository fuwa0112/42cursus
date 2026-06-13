/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:27:55 by hakama            #+#    #+#             */
/*   Updated: 2025/09/25 14:28:49 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void*))
{
	t_dlist	*last;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		last = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = last;
	}
	lst = NULL;
}
