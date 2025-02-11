/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:57:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/11 20:36:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_window(t_data *data)
{
	data->window.win_ptr = mlx_new_window(data->mlx_ptr, data->window.size_x,
			data->window.size_y, data->window.title);
	if (!data->window.win_ptr)
		return (0);
	return (1);
}

int	ft_init_image(t_data *data)
{
	data->image.img_ptr = mlx_new_image(data->mlx_ptr,
			data->window.size_x, data->window.size_y);
	if (!data->image.img_ptr)
		return (ERROR_MLX_IMG_INIT_FAILED);
	data->image.data_addr = mlx_get_data_addr(data->image.img_ptr,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	if (!data->image.data_addr)
		return (ERROR_MLX_GET_IMG_ADDRESS_FAILED);
	return (SUCCESS);
}
