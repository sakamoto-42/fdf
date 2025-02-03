/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:37:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/01 08:20:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_pixels(t_data *data)
{
	ft_points_to_pixels(data);
	ft_set_pixels_color(data, ft_rgb_to_color(0, 255, 0));
}

void	ft_center_map(t_data *data)
{
	if (data->render.projection == ORTHOGONAL_PROJECTION)
	{
		data->render.offset_x = (data->window.size_x
				- (data->map.cols * data->render.scale)) / 2;
		data->render.offset_y = (data->window.size_y
				- (data->map.rows * data->render.scale)) / 2;
	}
	else if (data->render.projection == ISOMETRIC_PROJECTION)
	{
		data->render.offset_x = (data->window.size_x / 2)
			- ((data->map.cols - data->map.rows) * data->render.scale) / 2;
		data->render.offset_y = (data->window.size_y / 2)
			- ((data->map.cols + data->map.rows) * data->render.scale / 2) / 2;
	}
}

void	ft_render_isometric_projection(t_point point,
	t_pixel *pixel, t_render render)
{
	ft_apply_angle_to_pixel(pixel, render);
	ft_apply_scale_z_to_pixel(point, pixel,
		render.render_isometric.scale_z);
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
			ft_apply_scale_to_pixel(data->map.points[row_count][col_count],
				&data->pixels[row_count][col_count], data->render.scale);
			if (data->render.projection == ISOMETRIC_PROJECTION)
			{
				ft_render_isometric_projection(
					data->map.points[row_count][col_count],
					&data->pixels[row_count][col_count],
					data->render);
			}
			ft_apply_offset_to_pixel(&data->pixels[row_count][col_count],
				data->render);
			col_count++;
		}
		row_count++;
	}
}

void	ft_set_pixels_color(t_data *data, int color)
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
				= (unsigned int)(mlx_get_color_value(data->mlx_ptr, color));
			col_count++;
		}
		row_count++;
	}
}
