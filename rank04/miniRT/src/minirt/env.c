/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:16:45 by hakama            #+#    #+#             */
/*   Updated: 2026/06/13 21:23:15 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_env(t_env *env, int argc, char **argv)
{
	ft_memset(env, 0, sizeof(t_env));
	if (argc != 2)
	{
		show_error("Usage: ./miniRT <file>");
		return (NULL);
	}
	if (!is_valid_input(argv[1], &env->scene))
		return (NULL);
	parse_elements(&env->scene);
	return (env);
}

void	*destroy_env(t_env *env)
{
	destroy_window(&env->window);
	free_scene(&env->scene);
	env = NULL;
	return (NULL);
}
