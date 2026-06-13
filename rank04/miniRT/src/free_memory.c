/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:14:25 by thitoe            #+#    #+#             */
/*   Updated: 2026/04/22 20:33:35 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"

void	free_content(void *content)
{
	free(content);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_scene(t_scene *scene)
{
	if (scene->light)
		free(scene->light);
	if (scene->surfaces)
		free(scene->surfaces);
	ft_lstclear(&(scene->objs), &free_content);
}
