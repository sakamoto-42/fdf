/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:25 by julien            #+#    #+#             */
/*   Updated: 2025/02/10 10:45:04 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_handle_keypress(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		data->input.keys[keycode] = 1;
	if (keycode == KEY_CENTER)
		ft_center_map(data);
	if (keycode == KEY_MIRROR)
		data->render.scale = -data->render.scale;
	if (data->input.keys[KEY_ORTHOGONAL]
		|| data->input.keys[KEY_ISOMETRIC] || data->input.keys[KEY_CONIC])
		ft_handle_keys_change_projection(data);
	return (0);
}

int	ft_handle_keyrelease(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		data->input.keys[keycode] = 0;
	return (0);
}

int	ft_repeat_key_events(t_data *data)
{
	if (data->input.keys[KEY_CENTER] || data->input.keys[KEY_MIRROR]
		|| data->input.keys[KEY_ORTHOGONAL]
		|| data->input.keys[KEY_ISOMETRIC] || data->input.keys[KEY_CONIC])
		return (0);
	if (data->input.keys[KEY_MOVE_UP] || data->input.keys[KEY_MOVE_DOWN]
		|| data->input.keys[KEY_MOVE_LEFT] || data->input.keys[KEY_MOVE_RIGHT])
		ft_handle_keys_translation(data);
	if (data->input.keys[KEY_DECREASE_SCALE_Z])
		data->render.render_isometric.scale_z
			= data->render.render_isometric.scale_z
			- (float)((float)SCALE_Z_STEP / 10);
	if (data->input.keys[KEY_INCREASE_SCALE_Z])
		data->render.render_isometric.scale_z
			= data->render.render_isometric.scale_z + SCALE_Z_STEP;
	if (data->input.keys[KEY_CLOSE])
		ft_handle_close(data);
	if (data->input.keys[KEY_ZOOM_IN] || data->input.keys[KEY_ZOOM_IN_2]
		|| data->input.keys[KEY_ZOOM_OUT] || data->input.keys[KEY_ZOOM_OUT_2])
		ft_handle_keys_zoom(data);
	if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_handle_keys_isometric_projection(data);
	if (data->input.keys[KEY_CHANGE_COLOR])
		ft_change_color(data);
	ft_update_image(data);
	usleep(20000);
	return (0);
}
