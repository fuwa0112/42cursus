/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:03 by thitoe            #+#    #+#             */
/*   Updated: 2026/04/22 20:00:05 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEMORY_H
# define FREE_MEMORY_H
# include "scene.h"

void	free_arr(char **arr);
void	free_content(void *content);
void	free_scene(t_scene *scene);
#endif
