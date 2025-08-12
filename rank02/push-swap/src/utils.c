/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:04:41 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/12 20:38:50 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_if_sorted_or_has_duplicate(t_stacks *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < s->a_size)
		{
			j = i + 1;
			while (j < s->a_size)
			{
				if (s->a[i] == s->a[j])
					free_and_exit_with_message(s, "Error\n", 1);
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(s))
		free_and_exit_with_message(s, NULL, 0);
}

void	parse_numbers(t_stacks *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	i = 0;
	tmp = ft_split(s->join_args, ' ');
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		s->a[z++] = ft_atol(tmp[i++], s);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	initialize_stacks(int argc, char **argv, t_stacks *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (--argc)
	{
		if (ft_count_words(argv[i + 1], ' '))
			s->a_size += ft_count_words(argv[i + 1], ' ');
		else
			s->a_size++;
		i++;
	}
	s->a = malloc(s->a_size * sizeof * s->a);
	if (s->a == NULL)
		free_and_exit_with_message(s, "Error\n", 1);
	s->b = malloc(s->a_size * sizeof * s->b);
	if (s->b == NULL)
		free_and_exit_with_message(s, "Error\n", 1);
}

static int	skip_spaces_and_sign(const char *n, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atol(const char *n, t_stacks *s)
{
	int			i;
	int			sign;
	long long	res;
	int			digits;

	res = 0;
	digits = 0;
	i = skip_spaces_and_sign(n, &sign);
	while (n[i])
	{
		if (n[i] < '0' || n[i] > '9')
			free_and_exit_with_message(s, "Error\n", 1);
		digits++;
		if (digits > 10)
			free_and_exit_with_message(s, "Error\n", 1);
		if (res > (LONG_MAX - (n[i] - '0')) / 10)
			free_and_exit_with_message(s, "Error\n", 1);
		res = res * 10 + (n[i++] - '0');
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		free_and_exit_with_message(s, "Error\n", 1);
	return ((int)(res * sign));
}
