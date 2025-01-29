/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:37:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/29 22:50:48 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_apply_scale_to_pixel(t_point point, t_pixel *pixel, int scale)
{
	pixel->x = point.x * scale;
	pixel->y = point.y * scale;
}

void	ft_apply_offset_to_pixel(t_pixel *pixel, t_render render)
{
	pixel->x += render.offset_x;
	pixel->y += render.offset_y;
}

void ft_apply_angle_to_pixel(t_pixel *pixel, t_render render)
{
	int	x;
	int	y;

	x = pixel->x;
	y = pixel->y;

	pixel->x = (x - y) * cos(render.render_isometric.angle);
	pixel->y = (x + y) * sin(render.render_isometric.angle);
}

void ft_apply_scale_z_to_pixel(t_point point, t_pixel *pixel, int scale_z)
{
	pixel->y = pixel->y - point.z * scale_z;
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
			ft_apply_scale_to_pixel(data->map.points[row_count][col_count], &data->pixels[row_count][col_count], data->render.scale);
			if (data->render.projection == ISOMETRIC_PROJECTION)
			{
				ft_apply_angle_to_pixel(&data->pixels[row_count][col_count], data->render);
				ft_apply_scale_z_to_pixel(data->map.points[row_count][col_count], &data->pixels[row_count][col_count], data->render.render_isometric.scale_z);
			}
			// TODO WITH ISOMETRIC PROJECTION
			ft_set_offset(data);
			ft_apply_offset_to_pixel(&data->pixels[row_count][col_count], data->render);
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
