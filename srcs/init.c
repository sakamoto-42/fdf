/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/12 17:12:22 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_screen_size(void *mlx_ptr, int *size_x, int *size_y)
{
	*size_x = 800;
	*size_y = 600;
	mlx_get_screen_size(mlx_ptr, size_x, size_y);
}

void	ft_set_scale(t_data *data)
{
	int	max_dimension;

	if (data->map.cols > data->map.rows)
		max_dimension = data->map.cols;
	else
		max_dimension = data->map.rows;
	if ((data->window.size_x / max_dimension)
		< ((data->window.size_y / max_dimension) / 2.5))
		data->render.scale = data->window.size_x / max_dimension;
	else
		data->render.scale = (data->window.size_y / max_dimension) / 2.5;
}

void	ft_init_default_settings(t_data *data)
{
	ft_get_screen_size(data->mlx_ptr,
		&data->window.size_x, &data->window.size_y);
	data->need_redraw = 0;
	data->window.title = "fdf";
	data->render.projection = ISOMETRIC_PROJECTION;
	ft_set_scale(data);
	data->render.color = data->colors[0];
	data->render.opposite_color = data->opposite_colors[0];
	data->render.render_isometric.angle_x = 45 * (M_PI / 180);
	data->render.render_isometric.angle_y = 0;
	data->render.render_isometric.angle_z = 45 * (M_PI / 180);
	data->render.render_isometric.scale_z = 1;
	data->render.render_conic.distance = 1000;
	data->render.render_conic.angle = 0.2;
	data->render.render_conic.distortion_x = 1;
	data->render.render_conic.distortion_y = 1;
	data->render.render_conic.perspective_strength = 1;
	data->map.min_z = ft_get_min_z(data);
	data->map.max_z = ft_get_max_z(data);
}

int	ft_init(t_data *data)
{
	int	status_code;

	ft_memset(data->input.keys, 0, sizeof(data->input.keys));
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
