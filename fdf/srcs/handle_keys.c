/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:25 by julien            #+#    #+#             */
/*   Updated: 2025/02/01 08:32:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_translation(t_data *data, int keycode)
{
	if (keycode == 65362)
	{
		ft_printf("UP");
		ft_update_offset_y(data, data->render.offset_y - 20);
	}
	if (keycode == 65364)
	{
		ft_printf("DOWN");
		ft_update_offset_y(data, data->render.offset_y + 20);
	}
	if (keycode == 65361)
	{
		ft_printf("LEFT");
		ft_update_offset_x(data, data->render.offset_x - 20);
	}
	if (keycode == 65363)
	{
		ft_printf("RIGHT");
		ft_update_offset_x(data, data->render.offset_x + 20);
	}
	if (keycode == 114)
	{
		ft_printf("r");
		ft_center_map(data);
		ft_update_image(data);
	}

}

int	ft_handle_keys(int keycode, t_data *data)
{
	ft_printf("%d", keycode);
	if (keycode == 65307)
		ft_handle_close(data);
	if (keycode == 111 && data->render.projection != ORTHOGONAL_PROJECTION)
		ft_update_projection(data, ORTHOGONAL_PROJECTION);
	if (keycode == 105 && data->render.projection != ISOMETRIC_PROJECTION)
		ft_update_projection(data, ISOMETRIC_PROJECTION);
	if (keycode == 109)
		ft_update_scale(data, -data->render.scale, MIRROR);
	if (keycode == 61)
		ft_update_scale(data, data->render.scale + 1, 0);
	if (keycode == 45)
		ft_update_scale(data, data->render.scale - 1, 0);
	if (keycode == 91 && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle(data, data->render.render_isometric.angle - 0.1);
	if (keycode == 93 && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle(data, data->render.render_isometric.angle + 0.1);
	if (keycode == 57 && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_scale_z(data, data->render.render_isometric.scale_z - 0.1);
	if (keycode == 48 && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_scale_z(data, data->render.render_isometric.scale_z + 1);
	else if (keycode >= 65361 || keycode <= 65364)
		ft_handle_translation(data, keycode);
	return (0);
}

int	ft_handle_close(t_data *data)
{
	ft_destroy_and_free_all(data);
	exit(0);
	return (0);
}
