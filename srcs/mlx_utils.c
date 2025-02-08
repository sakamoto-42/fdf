/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:17 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/08 22:24:25 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_rgb_to_color(t_data *data, int r, int g, int b)
{
	return ((unsigned int)(mlx_get_color_value(data->mlx_ptr,
			(r << 16) | (g << 8) | b)));
}

void	ft_mlx_pixel_put(t_data *data,
	t_pixel pixel, unsigned int color, int mode)
{
	char	*dst;
	int		y_limit_min;

	if (mode == HUD)
		y_limit_min = 0;
	else if (mode == MAP)
		y_limit_min = data->hud_height;
	if (pixel.x < 0 || pixel.x >= data->window.size_x
		|| pixel.y < y_limit_min || pixel.y >= data->window.size_y)
		return ;
	dst = data->image.data_addr
		+ (pixel.y * data->image.line_length
			+ pixel.x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
