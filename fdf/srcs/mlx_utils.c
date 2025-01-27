/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:17 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 13:47:12 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_rgb_to_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	ft_mlx_pixel_put(t_data *data, int row_count, int col_count)
{
	char			*dst;

	dst = data->image.data_addr
		+ (data->pixels[row_count][col_count].y * data->image.line_length
			+ data->pixels[row_count][col_count].x
			* (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = data->pixels[row_count][col_count].color;
}
