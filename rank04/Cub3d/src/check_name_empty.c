/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:46:58 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/25 22:47:00 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_file_name(char *file_name)
{
	int		i;
	int		j;
	char	*name;

	if (ft_strlen(file_name) <= 3)
	{
		ft_putstr_fd("Error\nfile_name must final with .cub\n", 2);
		exit(1);
	}
	i = 0;
	j = 3;
	name = ".cub";
	while (file_name[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (name[j--] != file_name[i--])
		{
			ft_putstr_fd("Error\nfile_name must final with .cub\n", 2);
			exit(1);
		}
	}
}

void	check_empty_read(char *map_name)
{
	int		fd;
	char	buff[1];
	int		byte_read;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\ncan not read from the file ", 2);
		ft_putstr_fd("or the file does not exist\n", 2);
		exit(1);
	}
	byte_read = read(fd, buff, 1);
	close(fd);
	if (byte_read == 0)
	{
		ft_putstr_fd("Error\nempty file\n", 2);
		exit(1);
	}
}
