/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakama <hakama@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:21:56 by hakama            #+#    #+#             */
/*   Updated: 2025/09/25 14:23:08 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->prev = NULL;
	(*lst)->prev = new;
	*lst = new;
}
