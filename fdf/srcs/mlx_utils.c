/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:17 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/27 15:21:05 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb_to_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_pixel_put(t_data *data)
{
	char			*dst;

	dst = data->image.data_addr
		+ (data->pixel.y * data->image.line_length
			+ data->pixel.x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = data->pixel.color;
}
