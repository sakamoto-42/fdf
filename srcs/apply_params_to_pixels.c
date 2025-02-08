/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_params_to_pixels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:06:08 by julien            #+#    #+#             */
/*   Updated: 2025/02/08 15:00:03 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_apply_color_to_pixel(t_data *data,
	t_pixel *pixel_1, t_pixel *pixel_2)
{
	int	min_z;
	int	max_z;

	min_z = ft_get_min_z(&data->map);
	max_z = ft_get_max_z(&data->map);
	if (pixel_1->z == min_z && pixel_2->z == min_z)
		pixel_1->color = (unsigned int)(mlx_get_color_value(data->mlx_ptr,
					data->render.color));
	else if (pixel_1->z == max_z && pixel_2->z == max_z)
		pixel_1->color = (unsigned int)(mlx_get_color_value(data->mlx_ptr,
					data->render.opposite_color));
	else
		pixel_1->color = (unsigned int)(mlx_get_color_value(data->mlx_ptr,
					ft_rgb_to_color(255, 255, 255)));
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
