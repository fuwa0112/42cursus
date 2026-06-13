/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:59:30 by hakama            #+#    #+#             */
/*   Updated: 2025/07/28 21:11:51 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*last;

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
