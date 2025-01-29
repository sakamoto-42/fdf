/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/29 22:51:32 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_offset(t_data *data)
{
	if (data->render.projection == ISOMETRIC_PROJECTION || data->render.projection == ORTHOGONAL_PROJECTION)
	{
		data->render.offset_x = (data->window.size_x
				- (data->map.cols * data->render.scale)) / 2;
		data->render.offset_y = (data->window.size_y
				- (data->map.rows * data->render.scale)) / 2;
	}
}

static void	ft_init_pixels(t_data *data)
{
	ft_points_to_pixels(data);
	ft_set_pixels_color(data, ft_rgb_to_color(0, 255, 0));
}

void	ft_init(t_data *data)
{
	ft_init_default_settings(data);
	data->mlx_ptr = mlx_init();
	ft_init_window(data);
	ft_init_image(data);
	ft_init_pixels(data);
}

void	ft_init_default_settings(t_data *data)
{
	data->render.projection = ORTHOGONAL_PROJECTION;
	//data->render.projection = ISOMETRIC_PROJECTION;
	data->render.scale = 20;
	data->render.render_isometric.angle = M_PI / 6;
	data->render.render_isometric.scale_z = 5;
}