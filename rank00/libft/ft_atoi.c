/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:06:38 by thitoe            #+#    #+#             */
/*   Updated: 2025/03/19 18:17:20 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	skip_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\v'
		|| **str == '\f' || **str == '\r')
		(*str)++;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = skip_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		digit = (*str - '0');
		if (result > (LLONG_MAX - digit) / 10)
		{
			if (sign == 1)
				return ((int)LLONG_MAX);
		}
		else if (-result < (LLONG_MIN + digit) / 10)
			return ((int)LLONG_MIN);
		result = result * 10 + digit;
		str++;
	}
	return ((int)(sign * result));
}
