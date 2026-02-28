/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:50:24 by hakama            #+#    #+#             */
/*   Updated: 2026/02/28 15:47:05 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	insert_rgb(t_vec *rgb, unsigned char *color, char **elements)
{
	free_split(elements);
	rgb->x = color[0] / 255.0f;
	rgb->y = color[1] / 255.0f;
	rgb->z = color[2] / 255.0f;
}

int	valid_rgb(char *str, t_vec *rgb)
{
	char			**elements;
	int				i;
	int				error;
	unsigned char	color[3];

	if (!correct_commas(str))
		return (0);
	elements = ft_split(str, ',');
	if (elements == NULL)
		return (0);
	i = 0;
	while (elements[i])
		i++;
	if (i != 3)
		return (free_split(elements), 0);
	i = 0;
	error = 0;
	while (elements[i])
	{
		color[i] = ft_atoi(elements[i], &error);
		if (error == 1)
			return (free_split(elements), 0);
		i++;
	}
	return (insert_rgb(rgb, color, elements), 1);
}

int	correct_commas(char *str)
{
	char	*tmp;
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	tmp = ft_strchr(str, ',');
	while (tmp)
	{
		i++;
		if (i > 2)
			break ;
		tmp = ft_strchr(tmp + 1, ',');
	}
	if (i != 2)
		return (0);
	return (1);
}

int	valid_ncords(char *str, double *cords, t_vec *vec)
{
	char	**elements;
	int		i;
	int		error;
	double	len;

	if (!correct_commas(str))
		return (0);
	elements = ft_split(str, ',');
	if (!elements)
		return (0);
	if (count_elements(elements) != 3)
		return (free_split(elements), 0);
	i = -1;
	while (++i < 3)
	{
		error = 0;
		cords[i] = ft_atof(elements[i], &error);
		if (error || cords[i] < -1.0 || cords[i] > 1.0)
			return (free_split(elements), 0);
	}
	*vec = new_vec(cords[0], cords[1], cords[2]);
	len = veclen(*vec);
	if (len < 1e-6 || fabs(len - 1.0) > 1e-6)
		return (free_split(elements), 0);
	return (free_split(elements), 1);
}

int	valid_cords(char *str, double *cords, t_vec *vec)
{
	char	**elements;
	int		error;
	int		i;

	if (!correct_commas(str))
		return (0);
	elements = ft_split(str, ',');
	if (elements == NULL)
		return (0);
	if (count_elements(elements) != 3)
		return (free_split(elements), 0);
	i = 0;
	error = 0;
	while (elements[i])
	{
		cords[i] = ft_atof(elements[i], &error);
		if (error == 1)
			return (free_split(elements), 0);
		i++;
	}
	*vec = new_vec(cords[0], cords[1], cords[2]);
	free_split(elements);
	return (1);
}
