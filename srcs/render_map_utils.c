/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:05:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/11 20:45:24 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_render_isometric_projection(t_pixel *pixel, t_render render)
{
	ft_apply_angle_z_to_pixel(pixel, render);
	ft_apply_angle_x_to_pixel(pixel, render);
	ft_apply_angle_y_to_pixel(pixel, render);
}

void	ft_render_conic_projection(t_pixel *pixel, t_render render)
{
	double	z_factor;

	if (render.render_conic.distance <= 0)
		render.render_conic.distance = 1;
	pixel->x -= render.map_center_x;
	pixel->y -= render.map_center_y;
	z_factor = (pixel->z / render.render_conic.distance)
		* render.render_conic.perspective_strength;
	pixel->x = (int)((pixel->x / (1 + z_factor))
			* render.render_conic.distortion_x);
	pixel->y = (int)((pixel->y / (1 + z_factor))
			* render.render_conic.distortion_y);
	pixel->y += (int)(pixel->z * tan(render.render_conic.angle));
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
