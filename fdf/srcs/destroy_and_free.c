/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:21:41 by julien            #+#    #+#             */
/*   Updated: 2025/01/30 15:21:55 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_destroy_and_free_all(t_data *data)
{
	if (data->image.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	if (data->window.win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->window.win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map.points)
		ft_free_points(data);
	if (data->pixels)
		ft_free_pixels(data);
}
