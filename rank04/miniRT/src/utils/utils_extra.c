/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:04:52 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 01:04:52 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_valid_end(char c)
{
	return (c == '\0' || c == '\n' || is_space(c));
}

void	skip_spaces(const char *str, int *i)
{
	if (!str || !i)
		return ;
	while (is_space(str[*i]))
		(*i)++;
}

int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (!str || !i)
		return (1);
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}
