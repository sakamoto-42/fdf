/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:25 by julien            #+#    #+#             */
/*   Updated: 2025/02/07 17:08:50 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_handle_keys(int keycode, t_data *data)
{
	if (keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN
		|| keycode == KEY_MOVE_LEFT || keycode == KEY_MOVE_RIGHT)
		ft_handle_keys_translation(data, keycode);
	if (keycode == KEY_CLOSE)
		ft_handle_close(data);
	if (keycode == KEY_ORTHOGONAL
		|| keycode == KEY_ISOMETRIC || keycode == KEY_CONIC)
		ft_handle_keys_change_projection(data, keycode);
	if (keycode == KEY_CENTER || keycode == KEY_MIRROR
		|| keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
		ft_handle_keys_common(data, keycode);
	if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_handle_keys_isometric_projection(data, keycode);
	if (keycode == KEY_CHANGE_COLOR)
		ft_change_color(data);
	ft_update_image(data);
	return (0);
}
