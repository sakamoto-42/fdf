/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 17:38:22 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_screen_size(void *mlx_ptr, int *size_x, int *size_y)
{
	*size_x = 800;
	*size_y = 600;
	mlx_get_screen_size(mlx_ptr, size_x, size_y);
}

void	ft_init_default_settings(t_data *data)
{
	ft_get_screen_size(data->mlx_ptr,
		&data->window.size_x, &data->window.size_y);
	data->window.title = "fdf";
	data->render.projection = ISOMETRIC_PROJECTION;
	data->render.scale = 20;
	data->render.color = data->colors[0];
	data->render.render_isometric.angle_x = M_PI / 6;
	data->render.render_isometric.angle_y = 0;
	data->render.render_isometric.angle_z = 0;
	data->render.render_isometric.scale_z = 5;
}

int	ft_init_color_sets(t_data *data)
{
	data->colors = (int *) ft_calloc(9, sizeof(int));
	if (!data->colors)
		return (0);
	data->colors[0] = ft_rgb_to_color(0, 255, 0);
	data->colors[1] = ft_rgb_to_color(255, 87, 51);
	data->colors[2] = ft_rgb_to_color(51, 255, 87);
	data->colors[3] = ft_rgb_to_color(51, 87, 255);
	data->colors[4] = ft_rgb_to_color(255, 215, 0);
	data->colors[5] = ft_rgb_to_color(255, 51, 161);
	data->colors[6] = ft_rgb_to_color(0, 255, 255);
	data->colors[7] = ft_rgb_to_color(255, 165, 0);
	data->colors[8] = ft_rgb_to_color(128, 0, 128);
	return (1);
}

int	ft_init(t_data *data)
{
	int	status_code;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ERROR_MLX_INIT_FAILED);
	if (!ft_init_color_sets(data))
		return (ERROR_NOT_ENOUGH_MEMORY);
	ft_init_default_settings(data);
	if (!ft_init_window(data))
		return (ERROR_MLX_WINDOW_INIT_FAILED);
	if (!ft_init_hud(data))
		return (ERROR_NOT_ENOUGH_MEMORY);
	ft_center_map(data);
	status_code = ft_render_map(data);
	if (status_code != SUCCESS)
		return (status_code);
	return (SUCCESS);
}
