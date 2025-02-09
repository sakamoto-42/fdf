/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:05:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/09 12:32:32 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center_map(t_data *data)
{
	if (data->render.projection == ORTHOGONAL_PROJECTION)
	{
		data->render.offset_x = (data->window.size_x / 2)
			- (data->render.map_center_x * data->render.scale)
			+ data->render.scale * 9;
		data->render.offset_y = (data->window.size_y / 2)
			- (data->render.map_center_y * data->render.scale)
			+ data->render.scale * 9 - data->hud_height / 2;
	}
	else if (data->render.projection == ISOMETRIC_PROJECTION)
	{
		data->render.offset_x = (data->window.size_x / 2)
			- ((data->render.map_center_x - data->render.map_center_y)
				* data->render.scale * (double)cos(M_PI / 6))
			+ data->render.scale * 3;
		data->render.offset_y = (data->window.size_y / 2)
			- ((data->render.map_center_x + data->render.map_center_y)
				* data->render.scale * (double)sin(M_PI / 6))
			+ data->render.scale * 3;
	}
}

void	ft_render_isometric_projection(t_point point,
	t_pixel *pixel, t_render render)
{
	pixel->x -= render.map_center_x;
	pixel->y -= render.map_center_y;
	ft_apply_angle_x_to_pixel(pixel, render);
	ft_apply_angle_y_to_pixel(pixel, render);
	ft_apply_angle_z_to_pixel(pixel, render);
	ft_apply_scale_z_to_pixel(point, pixel,
		render.render_isometric.scale_z);
	pixel->x += render.map_center_x;
	pixel->y += render.map_center_y;
}

void	ft_set_pixels_color(t_data *data, unsigned int color)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			data->pixels[row_count][col_count].color = color;
			col_count++;
		}
		row_count++;
	}
}
