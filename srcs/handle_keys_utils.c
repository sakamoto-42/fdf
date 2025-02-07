/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:30:33 by julien            #+#    #+#             */
/*   Updated: 2025/02/07 17:44:09 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_keys_translation(t_data *data, int keycode)
{
	if (keycode == KEY_MOVE_UP)
		data->render.offset_y = data->render.offset_y - TRANSLATION_STEP;
	if (keycode == KEY_MOVE_DOWN)
		data->render.offset_y = data->render.offset_y + TRANSLATION_STEP;
	if (keycode == KEY_MOVE_LEFT)
		data->render.offset_x = data->render.offset_x - TRANSLATION_STEP;
	if (keycode == KEY_MOVE_RIGHT)
		data->render.offset_x = data->render.offset_x + TRANSLATION_STEP;
}

void	ft_handle_keys_isometric_projection(t_data *data, int keycode)
{
	if (keycode == KEY_DECREASE_X_ANGLE)
		data->render.render_isometric.angle_x
			= data->render.render_isometric.angle_x - ANGLE_X_STEP;
	if (keycode == KEY_INCREASE_X_ANGLE)
		data->render.render_isometric.angle_x
			= data->render.render_isometric.angle_x + ANGLE_X_STEP;
	if (keycode == KEY_DECREASE_Y_ANGLE)
		data->render.render_isometric.angle_y
			= data->render.render_isometric.angle_y - ANGLE_Y_STEP;
	if (keycode == KEY_INCREASE_Y_ANGLE)
		data->render.render_isometric.angle_y
			= data->render.render_isometric.angle_y + ANGLE_Y_STEP;
	if (keycode == KEY_DECREASE_Z_ANGLE)
		data->render.render_isometric.angle_z
			= data->render.render_isometric.angle_z - ANGLE_Z_STEP;
	if (keycode == KEY_INCREASE_Z_ANGLE)
		data->render.render_isometric.angle_z
			= data->render.render_isometric.angle_z + ANGLE_Z_STEP;
	if (keycode == KEY_DECREASE_SCALE_Z)
		data->render.render_isometric.scale_z
			= data->render.render_isometric.scale_z
			- (float)((float)SCALE_Z_STEP / 10);
	if (keycode == KEY_INCREASE_SCALE_Z)
		data->render.render_isometric.scale_z
			= data->render.render_isometric.scale_z + SCALE_Z_STEP;
}

void	ft_handle_keys_change_projection(t_data *data, int keycode)
{
	if (keycode == KEY_ORTHOGONAL
		&& data->render.projection != ORTHOGONAL_PROJECTION)
		data->render.projection = ORTHOGONAL_PROJECTION;
	if (keycode == KEY_ISOMETRIC
		&& data->render.projection != ISOMETRIC_PROJECTION)
		data->render.projection = ISOMETRIC_PROJECTION;
	if (keycode == KEY_CONIC
		&& data->render.projection != CONIC_PROJECTION)
		data->render.projection = CONIC_PROJECTION;
}

void	ft_handle_keys_common(t_data *data, int keycode)
{
	if (keycode == KEY_CENTER)
		ft_center_map(data);
	if (keycode == KEY_MIRROR)
		data->render.scale = -data->render.scale;
	if (keycode == KEY_ZOOM_IN)
		data->render.scale = data->render.scale + ZOOM_STEP;
	if (keycode == KEY_ZOOM_OUT)
		data->render.scale = data->render.scale - ZOOM_STEP;
}

void	ft_change_color(t_data *data)
{
	static int	color_index = 1;

	if (color_index >= 7)
		color_index = 0;
	data->render.color = data->colors[color_index];
	color_index++;
}
