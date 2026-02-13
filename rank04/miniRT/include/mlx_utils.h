/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:51:16 by thitoe            #+#    #+#             */
/*   Updated: 2026/02/12 13:51:17 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
	double	img_w;
	double	img_h;
}			t_image;

#endif
