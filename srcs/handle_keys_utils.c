/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:30:33 by julien            #+#    #+#             */
/*   Updated: 2025/02/10 10:44:54 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_keys_translation(t_data *data)
{
	if (data->input.keys[KEY_MOVE_UP])
		data->render.offset_y = data->render.offset_y - TRANSLATION_STEP;
	if (data->input.keys[KEY_MOVE_DOWN])
		data->render.offset_y = data->render.offset_y + TRANSLATION_STEP;
	if (data->input.keys[KEY_MOVE_LEFT])
		data->render.offset_x = data->render.offset_x - TRANSLATION_STEP;
	if (data->input.keys[KEY_MOVE_RIGHT])
		data->render.offset_x = data->render.offset_x + TRANSLATION_STEP;
}

void	ft_handle_keys_isometric_projection(t_data *data)
{
	if (data->input.keys[KEY_DECREASE_X_ANGLE])
		data->render.render_isometric.angle_x
			= data->render.render_isometric.angle_x - ANGLE_X_STEP;
	if (data->input.keys[KEY_INCREASE_X_ANGLE])
		data->render.render_isometric.angle_x
			= data->render.render_isometric.angle_x + ANGLE_X_STEP;
	if (data->input.keys[KEY_DECREASE_Y_ANGLE])
		data->render.render_isometric.angle_y
			= data->render.render_isometric.angle_y - ANGLE_Y_STEP;
	if (data->input.keys[KEY_INCREASE_Y_ANGLE])
		data->render.render_isometric.angle_y
			= data->render.render_isometric.angle_y + ANGLE_Y_STEP;
	if (data->input.keys[KEY_DECREASE_Z_ANGLE])
		data->render.render_isometric.angle_z
			= data->render.render_isometric.angle_z - ANGLE_Z_STEP;
	if (data->input.keys[KEY_INCREASE_Z_ANGLE])
		data->render.render_isometric.angle_z
			= data->render.render_isometric.angle_z + ANGLE_Z_STEP;
}

void	ft_handle_keys_change_projection(t_data *data)
{
	if (data->input.keys[KEY_ORTHOGONAL]
		&& data->render.projection != ORTHOGONAL_PROJECTION)
		data->render.projection = ORTHOGONAL_PROJECTION;
	if (data->input.keys[KEY_ISOMETRIC]
		&& data->render.projection != ISOMETRIC_PROJECTION)
		data->render.projection = ISOMETRIC_PROJECTION;
	if (data->input.keys[KEY_CONIC]
		&& data->render.projection != CONIC_PROJECTION)
		data->render.projection = CONIC_PROJECTION;
}

void	ft_handle_keys_zoom(t_data *data)
{
	if (data->input.keys[KEY_ZOOM_IN] || data->input.keys[KEY_ZOOM_IN_2])
		data->render.scale = data->render.scale + ZOOM_STEP;
	if (data->input.keys[KEY_ZOOM_OUT] || data->input.keys[KEY_ZOOM_OUT_2])
		data->render.scale = data->render.scale - ZOOM_STEP;
}

void	ft_change_color(t_data *data)
{
	static int	color_index = 1;

	if (color_index >= 7)
		color_index = 0;
	data->render.color = data->colors[color_index];
	data->render.opposite_color = data->opposite_colors[color_index];
	color_index++;
}
