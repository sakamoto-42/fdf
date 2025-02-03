/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/01 08:20:44 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_default_settings(t_data *data)
{
	data->window.size_x = 800;
	data->window.size_y = 600;
	data->window.title = "fdf";
	data->render.projection = ISOMETRIC_PROJECTION;
	data->render.scale = 20;
	data->render.render_isometric.angle = M_PI / 6;
	data->render.render_isometric.scale_z = 5;
}

void	ft_init(t_data *data)
{
	ft_init_default_settings(data);
	data->mlx_ptr = mlx_init();
	ft_init_window(data);
	ft_center_map(data);
	ft_render_map(data);
}
