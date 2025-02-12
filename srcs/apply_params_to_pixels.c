/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_params_to_pixels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:06:08 by julien            #+#    #+#             */
/*   Updated: 2025/02/12 14:33:36 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_get_color_for_pixel(t_data *data, t_pixel *pixel)
{
	int			min_z;
	int			max_z;
	t_gradient	gradient;

	min_z = data->map.min_z;
	max_z = data->map.max_z;
	if (pixel->z == min_z)
		return (data->render.color);
	else if (pixel->z == max_z)
		return (data->render.opposite_color);
	else
	{
		gradient.value = pixel->z;
		gradient.min_value = min_z;
		gradient.max_value = max_z;
		gradient.lower_color = data->render.color;
		gradient.higher_color = data->render.opposite_color;
		return (ft_get_gradient_color(gradient));
	}
}

void	ft_apply_scale_to_pixel(t_pixel *pixel, int scale)
{
	pixel->x = pixel->x * scale;
	pixel->y = pixel->y * scale;
	pixel->z = pixel->z * scale;
}

void	ft_apply_offset_to_pixel(t_pixel *pixel, t_render render)
{
	pixel->x += render.offset_x;
	pixel->y += render.offset_y;
}

void	ft_apply_scale_z_to_pixel(t_pixel *pixel, int scale_z)
{
	pixel->z *= scale_z;
}
