/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:18:49 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/10 16:08:03 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_keys_isometric_projection(t_data *data)
{
	if (data->input.keys[KEY_DECREASE_X_ANGLE])
		data->render.render_isometric.angle_x -= ANGLE_X_STEP;
	if (data->input.keys[KEY_INCREASE_X_ANGLE])
		data->render.render_isometric.angle_x += ANGLE_X_STEP;
	if (data->input.keys[KEY_DECREASE_Y_ANGLE])
		data->render.render_isometric.angle_y -= ANGLE_Y_STEP;
	if (data->input.keys[KEY_INCREASE_Y_ANGLE])
		data->render.render_isometric.angle_y += ANGLE_Y_STEP;
	if (data->input.keys[KEY_DECREASE_Z_ANGLE])
		data->render.render_isometric.angle_z -= ANGLE_Z_STEP;
	if (data->input.keys[KEY_INCREASE_Z_ANGLE])
		data->render.render_isometric.angle_z += ANGLE_Z_STEP;
	data->need_redraw = 1;
}

void	ft_handle_keys_conic_projection(t_data *data)
{
	if (data->input.keys[KEY_DECREASE_ANGLE])
		data->render.render_conic.angle -= ANGLE_STEP;
	if (data->input.keys[KEY_INCREASE_ANGLE])
		data->render.render_conic.angle += ANGLE_STEP;
	if (data->input.keys[KEY_DECREASE_DISTANCE])
		data->render.render_conic.distance -= DISTANCE_STEP;
	if (data->input.keys[KEY_INCREASE_DISTANCE])
		data->render.render_conic.distance += DISTANCE_STEP;
	if (data->input.keys[KEY_DECREASE_DISTORTION_X])
		data->render.render_conic.distortion_x -= DISTORTION_X_STEP;
	if (data->input.keys[KEY_INCREASE_DISTORTION_X])
		data->render.render_conic.distortion_x += DISTORTION_X_STEP;
	if (data->input.keys[KEY_DECREASE_DISTORTION_Y])
		data->render.render_conic.distortion_y -= DISTORTION_Y_STEP;
	if (data->input.keys[KEY_INCREASE_DISTORTION_Y])
		data->render.render_conic.distortion_y += DISTORTION_Y_STEP;
	if (data->input.keys[KEY_DECREASE_PERSPECTIVE])
		data->render.render_conic.perspective_strength -= PERSPECTIVE;
	if (data->input.keys[KEY_INCREASE_PERSPECTIVE])
		data->render.render_conic.perspective_strength += PERSPECTIVE;
	data->need_redraw = 1;
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
	data->need_redraw = 1;
}
