/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:12 by huaydin           #+#    #+#             */
/*   Updated: 2025/08/12 19:59:38 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_and_exit_with_message(t_stacks *s, char *msg, int i)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->join_args != NULL)
			free(s->join_args);
		if (s != NULL)
			free(s);
	}
	exit(i);
}

static void	validate_arguments(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	if (argc < 2)
		free_and_exit_with_message(NULL, "", 1);
	i = 0;
	while (++i < argc)
	{
		if (!argv[i][0] || argv[i][0] == ' ')
			free_and_exit_with_message(NULL, "Error\n", 1);
		j = -1;
		while (argv[i][++j])
		{
			c = argv[i][j];
			if ((!ft_isdigit(c) && c != ' ' && c != '-' && c != '+')
				|| ((c == '-' || c == '+')
					&& (!argv[i][j + 1] || argv[i][j + 1] == ' ')))
				free_and_exit_with_message(NULL, "Error\n", 1);
		}
	}
}

static void	join_args(int argc, char **argv, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = ft_strdup(tmp);
	if (s->join_args == NULL)
		free_and_exit_with_message(s, "Error\n", 1);
	if (tmp)
		free(tmp);
}

static void	start_s(t_stacks *s)
{
	if (s == NULL)
	{
		write(2, "Error/n", 6);
		exit(1);
	}
	s->a = NULL;
	s->b = NULL;
	s->join_args = NULL;
	s->a_size = 0;
	s->b_size = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	validate_arguments(argc, argv);
	s = malloc(sizeof * s);
	start_s(s);
	initialize_stacks(argc, argv, s);
	join_args(argc, argv, s);
	parse_numbers(s);
	exit_if_sorted_or_has_duplicate(s, 0);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size >= 4 && s->a_size <= 5)
		sort_four_to_five_elements(s);
	else
		radix_sort(s);
	exit_if_sorted_or_has_duplicate(s, 1);
	free_and_exit_with_message(s, "Errorrr\n", 1);
	return (1);
}
