/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:37:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/29 21:02:55 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_apply_isometric_projection(t_render *render,
	t_point point, t_pixel *pixel)
{
	int	x;
	int	y;

	render->angle = M_PI / 6;
	render->scale_z = 5;
	x = pixel->x;
	y = pixel->y;
	pixel->x = (x - y) * cos(render->angle) + render->offset_x;
	pixel->y = (x + y) * sin(render->angle) - point.z
		* render->scale_z + render->offset_y;
}

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
				* data->render.scale;
			data->pixels[row_count][col_count].y
				= data->map.points[row_count][col_count].y
				* data->render.scale;
			if (data->render.projection != 1)
			{
				data->pixels[row_count][col_count].x
					+= data->render.offset_x;
				data->pixels[row_count][col_count].y
					+= data->render.offset_y;
			}
			else if (data->render.projection == 1)
			{
				ft_apply_isometric_projection(&data->render,
					data->map.points[row_count][col_count],
					&data->pixels[row_count][col_count]);
			}
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
