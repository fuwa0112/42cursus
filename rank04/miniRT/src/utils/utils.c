/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshein <lshein@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:00:10 by hthant            #+#    #+#             */
/*   Updated: 2025/07/23 13:38:35 by lshein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int			is_space(char c);
int			is_valid_end(char c);
void		skip_spaces(const char *str, int *i);
int			handle_sign(const char *str, int *i);
void		error_message(void);

static int	ft_skip_whitespace(const char *str, int start)
{
	int	i;

	if (!str)
		return (start);
	i = start;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static int	ft_parse_integer_part(const char *str, int *i, double *result,
		int *digit_found)
{
	*result = 0.0;
	*digit_found = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
		*digit_found = 1;
	}
	return (1);
}

static int	ft_parse_fractional_part(const char *str, int *i, double *result,
		int *digit_found)
{
	double	frac;
	double	decimal_place;

	if (str[*i] != '.')
		return (1);
	frac = 0.0;
	decimal_place = 1.0;
	(*i)++;
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		return (0);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		frac = frac * 10 + (str[*i] - '0');
		decimal_place *= 10.0;
		(*i)++;
		*digit_found = 1;
	}
	frac /= decimal_place;
	*result += frac;
	return (1);
}

int	ft_atof_vali(const char *str, double *result)
{
	int	i;
	int	negative;
	int	digit_found;

	i = ft_skip_whitespace(str, 0);
	*result = 0.0;
	negative = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	if (!ft_parse_integer_part(str, &i, result, &digit_found))
		return (0);
	if (!ft_parse_fractional_part(str, &i, result, &digit_found))
		return (0);
	if (!digit_found)
		return (0);
	i = ft_skip_whitespace(str, i);
	if (str[i] != '\0')
		return (0);
	if (negative)
		*result = -*result;
	return (1);
}

int	arg_count(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i][0] != '\n')
		i++;
	return (i);
}
