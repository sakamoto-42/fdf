/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:57:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 17:43:15 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_window(t_data *data)
{
	data->window.size_x = 800;
	data->window.size_y = 600;
	data->window.title = "fdf";
	data->window.win_ptr = mlx_new_window(data->mlx_ptr, data->window.size_x,
			data->window.size_y, data->window.title);
}

void	ft_init_image(t_data *data)
{
	data->image.img_ptr = mlx_new_image(data->mlx_ptr,
			data->window.size_x, data->window.size_y);
	data->image.data_addr = mlx_get_data_addr(data->image.img_ptr,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
}
