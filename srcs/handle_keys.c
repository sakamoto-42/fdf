/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:25 by julien            #+#    #+#             */
/*   Updated: 2025/02/05 23:22:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_translation(t_data *data, int keycode)
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

// TO SPLIT
int	ft_handle_keys(int keycode, t_data *data)
{
	if (keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN || keycode == KEY_MOVE_LEFT || keycode == KEY_MOVE_RIGHT)
		ft_handle_translation(data, keycode);
	if (keycode == KEY_CLOSE)
		ft_handle_close(data);
	if (keycode == KEY_ORTHOGONAL && data->render.projection != ORTHOGONAL_PROJECTION)
		data->render.projection = ORTHOGONAL_PROJECTION;
	if (keycode == KEY_ISOMETRIC && data->render.projection != ISOMETRIC_PROJECTION)
		data->render.projection = ISOMETRIC_PROJECTION;
	if (keycode == KEY_CONIC && data->render.projection != ISOMETRIC_PROJECTION)
		data->render.projection = CONIC_PROJECTION;
	if (keycode == KEY_CENTER)
		ft_center_map(data);
	if (keycode == KEY_MIRROR)
		data->render.scale = -data->render.scale;
	if (keycode == KEY_ZOOM_IN)
		data->render.scale = data->render.scale + ZOOM_STEP;
	if (keycode == KEY_ZOOM_OUT)
		data->render.scale = data->render.scale - ZOOM_STEP;
	if (keycode == KEY_DECREASE_X_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		data->render.render_isometric.angle_x = data->render.render_isometric.angle_x - ANGLE_X_STEP;
	if (keycode == KEY_INCREASE_X_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		data->render.render_isometric.angle_x = data->render.render_isometric.angle_x + ANGLE_X_STEP;
	if (keycode == KEY_DECREASE_Y_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		data->render.render_isometric.angle_y = data->render.render_isometric.angle_y - ANGLE_Y_STEP;
	if (keycode == KEY_INCREASE_Y_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		data->render.render_isometric.angle_y = data->render.render_isometric.angle_y + ANGLE_Y_STEP;
	if (keycode == KEY_DECREASE_Z_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		data->render.render_isometric.angle_z = data->render.render_isometric.angle_z - ANGLE_Z_STEP;
	if (keycode == KEY_INCREASE_Z_ANGLE && data->render.projection == ISOMETRIC_PROJECTION)
		data->render.render_isometric.angle_z = data->render.render_isometric.angle_z + ANGLE_Z_STEP;
	if (keycode == KEY_DECREASE_SCALE_Z && data->render.projection == ISOMETRIC_PROJECTION)
		data->render.render_isometric.scale_z = data->render.render_isometric.scale_z - (float)((float)SCALE_Z_STEP / 10);
	if (keycode == KEY_INCREASE_SCALE_Z && data->render.projection == ISOMETRIC_PROJECTION)
		data->render.render_isometric.scale_z = data->render.render_isometric.scale_z + SCALE_Z_STEP;
	ft_update_image(data);
	return (0);
}

int	ft_handle_close(t_data *data)
{
	ft_destroy_and_free_all(data);
	exit(0);
	return (0);
}
