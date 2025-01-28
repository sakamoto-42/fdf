/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:37:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 17:28:55 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_points_to_pixels(t_data *data)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			data->pixels[row_count][col_count].x
				= data->map.points[row_count][col_count].x
				* data->render.scale + data->render.offset_x;
			data->pixels[row_count][col_count].y
				= data->map.points[row_count][col_count].y
				* data->render.scale + data->render.offset_y;
			col_count++;
		}
		row_count++;
	}
}

void	ft_init_pixels_color(t_data *data)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			data->pixels[row_count][col_count].color
				= (unsigned int)(mlx_get_color_value(data->mlx_ptr,
						ft_rgb_to_color(0, 255, 0)));
			col_count++;
		}
		row_count++;
	}
}