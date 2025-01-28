/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:39:17 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 13:49:42 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_data data)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	while (row_count < data.map.rows)
	{
		col_count = 0;
		while (col_count < data.map.cols)
		{
			data.pixels[row_count][col_count].color
				= (unsigned int)(mlx_get_color_value(data.mlx_ptr,
						ft_rgb_to_color(0, 255, 0)));
			ft_mlx_pixel_put(&data, row_count, col_count);
			col_count++;
		}
		row_count++;
	}
	mlx_put_image_to_window(data.mlx_ptr,
		data.window.win_ptr, data.image.img_ptr, 0, 0);
}
