/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:03 by thitoe            #+#    #+#             */
/*   Updated: 2026/06/14 00:12:32 by thitoe           ###   ########.fr       */
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
		return (ft_lstclear(&env->scene.objs, free_content), NULL);
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

int	main(int argc, char *argv[])
{
	t_env	env;

	if (!init_env(&env, argc, argv))
		return (EXIT_FAILURE);
	init_window(&env.window, WINDOW_WIDTH, WINDOW_HEIGHT, "MINIRT");
	set_window_hooks(&env);
	render_loop(&env);
	destroy_env(&env);
	return (EXIT_SUCCESS);
}
