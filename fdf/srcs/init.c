/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 13:48:11 by juduchar         ###   ########.fr       */
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
	ft_points_to_pixels(data);
}

void	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	ft_init_window(data);
	ft_init_image(data);
	ft_init_pixels(data);
}
