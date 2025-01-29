/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/29 21:12:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_render(t_data *data)
{
	data->render.scale = 20;
	data->render.offset_x = (data->window.size_x
			- (data->map.cols * data->render.scale)) / 2;
	data->render.offset_y = (data->window.size_y
			- (data->map.rows * data->render.scale)) / 2;
}

static void	ft_init_pixels(t_data *data)
{
	ft_init_render(data);
	data->render.projection = 1;
	ft_points_to_pixels(data);
	ft_init_pixels_color(data);
}

void	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	ft_init_window(data);
	ft_init_image(data);
	ft_init_pixels(data);
}
