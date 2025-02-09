/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_angles_to_pixels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:35:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/09 12:44:49 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_apply_angle_x_to_pixel(t_pixel *pixel, t_render render)
{
	int	y;
	int	z;

	y = pixel->y - render.map_center_y;
	z = pixel->z;
	pixel->y = render.map_center_y + (y * cos(render.render_isometric.angle_x)
			- z * sin(render.render_isometric.angle_x));
	pixel->z = y * sin(render.render_isometric.angle_x)
		+ z * cos(render.render_isometric.angle_x);
}

void	ft_apply_angle_y_to_pixel(t_pixel *pixel, t_render render)
{
	int	x;
	int	z;

	x = pixel->x - render.map_center_x;
	z = pixel->z;
	pixel->x = render.map_center_x + (x * cos(render.render_isometric.angle_y)
			- z * sin(render.render_isometric.angle_y));
	pixel->z = -x * sin(render.render_isometric.angle_y)
		+ z * cos(render.render_isometric.angle_y);
}

void	ft_apply_angle_z_to_pixel(t_pixel *pixel, t_render render)
{
	int	x;
	int	y;

	x = pixel->x - render.map_center_x;
	y = pixel->y - render.map_center_y;
	pixel->x = render.map_center_x + (x * cos(render.render_isometric.angle_z)
			- y * sin(render.render_isometric.angle_z));
	pixel->y = -x * sin(render.render_isometric.angle_y)
		+ y * cos(render.render_isometric.angle_z);
}
