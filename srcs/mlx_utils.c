/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:17 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/05 19:15:37 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_rgb_to_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color, int mode)
{
	char	*dst;
	int		y_limit_min;

	if (mode == HUD)
		y_limit_min = 0;
	else if (mode == MAP)
		y_limit_min = data->hud_height;
	if (x < 0 || x >= data->window.size_x || y < y_limit_min || y >= data->window.size_y)
		return ;
	dst = data->image.data_addr
		+ (y * data->image.line_length
			+ x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
