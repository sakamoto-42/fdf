/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_params_to_pixels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:06:08 by julien            #+#    #+#             */
/*   Updated: 2025/02/08 16:30:55 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_apply_color_to_pixel(t_data *data, t_pixel *pixel)
{
	int	min_z;
	int	max_z;

	min_z = ft_get_min_z(&data->map);
	max_z = ft_get_max_z(&data->map);
	if (pixel->z == min_z)
		pixel->color = data->render.color;
	else if (pixel->z == max_z)
		pixel->color = data->render.opposite_color;
	else
	{
		double	ratio;
		int	r, r1, r2, g, g1, g2, b, b1, b2;
		ratio = (double)(pixel->z - min_z) / (max_z - min_z);
		r1 = (data->render.color >> 16) & 0xFF;
		g1 = (data->render.color >> 8) & 0xFF;
		b1 = data->render.color & 0xFF;
		r2 = (data->render.opposite_color >> 16) & 0xFF;
		g2 = (data->render.opposite_color >> 8) & 0xFF;
		b2 = data->render.opposite_color & 0xFF;
		r = (int)(r1 + ratio * (r2 - r1));
		g = (int)(g1 + ratio * (g2 - g1));
		b = (int)(b1 + ratio * (b2 - b1));
		pixel->color = ft_rgb_to_color(data, r, g, b);
	}
}

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

void	ft_apply_angle_x_to_pixel(t_pixel *pixel, t_render render)
{
	int	x;
	int	y;

	x = pixel->x;
	y = pixel->y;
	pixel->x = (x - y) * cos(render.render_isometric.angle_x);
	pixel->y = (x + y) * sin(render.render_isometric.angle_x);
}

void	ft_apply_scale_z_to_pixel(t_point point, t_pixel *pixel, int scale_z)
{
	pixel->y = pixel->y - point.z * scale_z;
}
