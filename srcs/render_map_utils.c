/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:05:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/05 19:36:35 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	data->render.offset_y += data->hud_height;
}


void	ft_render_isometric_projection(t_point point,
	t_pixel *pixel, t_render render)
{
	ft_apply_angle_x_to_pixel(pixel, render);
	ft_apply_scale_z_to_pixel(point, pixel,
		render.render_isometric.scale_z);
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

