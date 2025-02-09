/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_params_to_pixels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:06:08 by julien            #+#    #+#             */
/*   Updated: 2025/02/09 10:36:02 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_get_color_for_pixel(t_data *data, t_pixel *pixel)
{
	int			min_z;
	int			max_z;
	t_gradient	gradient;

	min_z = ft_get_min_z(&data->map);
	max_z = ft_get_max_z(&data->map);
	if (pixel->z == min_z)
		return (data->render.color);
	else if (pixel->z == max_z)
		return (data->render.opposite_color);
	else
	{
		gradient.value = pixel->z ;
		gradient.min_value = min_z;
		gradient.max_value = max_z;
		gradient.lower_color = data->render.color;
		gradient.higher_color = data->render.opposite_color;
		return (ft_get_gradient_color(data, gradient));
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

void	ft_apply_scale_z_to_pixel(t_point point, t_pixel *pixel, int scale_z)
{
	pixel->y = pixel->y - point.z * scale_z;
}
