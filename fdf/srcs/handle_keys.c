/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:25 by julien            #+#    #+#             */
/*   Updated: 2025/02/04 15:46:53 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_translation(t_data *data, int keycode)
{
	if (keycode == 65362)
	{
		//ft_printf("UP");
		ft_update_offset_y(data, data->render.offset_y - TRANSLATION_STEP);
	}
	if (keycode == 65364)
	{
		//ft_printf("DOWN");
		ft_update_offset_y(data, data->render.offset_y + TRANSLATION_STEP);
	}
	if (keycode == 65361)
	{
		//ft_printf("LEFT");
		ft_update_offset_x(data, data->render.offset_x - TRANSLATION_STEP);
	}
	if (keycode == 65363)
	{
		//ft_printf("RIGHT");
		ft_update_offset_x(data, data->render.offset_x + TRANSLATION_STEP);
	}
	
}
#include <stdio.h>

int	ft_handle_keys(int keycode, t_data *data)
{
	if (keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN || keycode == KEY_MOVE_LEFT || keycode == KEY_MOVE_RIGHT)
		ft_handle_translation(data, keycode);
	if (keycode == KEY_CLOSE)
		ft_handle_close(data);
	if (keycode == KEY_ORTHOGONAL && data->render.projection != ORTHOGONAL_PROJECTION)
		ft_update_projection(data, ORTHOGONAL_PROJECTION);
	if (keycode == KEY_ISOMETRIC && data->render.projection != ISOMETRIC_PROJECTION)
		ft_update_projection(data, ISOMETRIC_PROJECTION);
	if (keycode == KEY_CONIC && data->render.projection != ISOMETRIC_PROJECTION)
		ft_update_projection(data, ISOMETRIC_PROJECTION);
	if (keycode == KEY_CENTER)
		ft_center_map_and_update(data);
	if (keycode == KEY_MIRROR)
		ft_update_scale(data, -data->render.scale);
	if (keycode == KEY_ZOOM_IN)
		ft_update_scale(data, data->render.scale + ZOOM_STEP);
	if (keycode == KEY_ZOOM_OUT)
		ft_update_scale(data, data->render.scale - ZOOM_STEP);
	if (keycode == KEY_DECREASE_X_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle_x(data, data->render.render_isometric.angle_x - ANGLE_X_STEP);
	if (keycode == KEY_INCREASE_X_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle_x(data, data->render.render_isometric.angle_x + ANGLE_X_STEP);
	if (keycode == KEY_DECREASE_Y_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle_y(data, data->render.render_isometric.angle_y - ANGLE_Y_STEP);
	if (keycode == KEY_INCREASE_Y_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle_y(data, data->render.render_isometric.angle_y + ANGLE_Y_STEP);
	if (keycode == KEY_DECREASE_Z_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle_z(data, data->render.render_isometric.angle_z - ANGLE_Z_STEP);
	if (keycode == KEY_INCREASE_Z_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle_z(data, data->render.render_isometric.angle_z + ANGLE_Z_STEP);
	if (keycode == KEY_DECREASE_SCALE_Z && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_scale_z(data, data->render.render_isometric.scale_z - (float)((float)SCALE_Z_STEP / 10));
	if (keycode == KEY_INCREASE_SCALE_Z && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_scale_z(data, data->render.render_isometric.scale_z + SCALE_Z_STEP);
	return (0);
}

int	ft_handle_close(t_data *data)
{
	ft_destroy_and_free_all(data);
	exit(0);
	return (0);
}
