/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_angles_to_pixels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:35:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/10 16:39:40 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	ft_apply_angle_x_to_pixel(t_pixel *pixel, t_render render)
{
	int	y;
	int	z;

	y = pixel->y;
	z = pixel->z;
	printf("%f\n", cos(render.render_isometric.angle_x));
	pixel->y = ((double)y * cos(render.render_isometric.angle_x)
			- (double)z * sin(render.render_isometric.angle_x));
	pixel->z = (double)y * sin(render.render_isometric.angle_x)
		+ (double)z * cos(render.render_isometric.angle_x);
}

void	ft_apply_angle_y_to_pixel(t_pixel *pixel, t_render render)
{
	int	x;
	int	z;

	x = pixel->x;
	z = pixel->z;
	pixel->x = ((double)x * cos(render.render_isometric.angle_y)
			- (double)z * sin(render.render_isometric.angle_y));
	pixel->z = (double)(-x) * sin(render.render_isometric.angle_y)
		+ (double)z * cos(render.render_isometric.angle_y);
}

void	ft_apply_angle_z_to_pixel(t_pixel *pixel, t_render render)
{
	int	x;
	int	y;

	x = pixel->x;
	y = pixel->y;
	pixel->x = ((double)x * cos(render.render_isometric.angle_z)
			- (double)y * sin(render.render_isometric.angle_z));
	pixel->y = (double)x * sin(render.render_isometric.angle_z)
		+ (double)y * cos(render.render_isometric.angle_z);
}
