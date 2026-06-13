/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:03 by thitoe            #+#    #+#             */
/*   Updated: 2026/04/29 11:20:39 by hakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

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
