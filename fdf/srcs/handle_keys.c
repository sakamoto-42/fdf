/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:25 by julien            #+#    #+#             */
/*   Updated: 2025/02/04 10:47:34 by juduchar         ###   ########.fr       */
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
	if (keycode == 114)
	{
		//ft_printf("r");
		ft_center_map(data);
		ft_update_image(data);
	}
}
#include <stdio.h>

int	ft_handle_keys(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_handle_close(data);
	if (keycode == 111 && data->render.projection != ORTHOGONAL_PROJECTION)
		ft_update_projection(data, ORTHOGONAL_PROJECTION);
	if (keycode == 105 && data->render.projection != ISOMETRIC_PROJECTION)
		ft_update_projection(data, ISOMETRIC_PROJECTION);
	if (keycode == 109)
		ft_update_scale(data, -data->render.scale);
	if (keycode == 61)
		ft_update_scale(data, data->render.scale + ZOOM_STEP);
	if (keycode == 45)
		ft_update_scale(data, data->render.scale - ZOOM_STEP);
	if (keycode == 91 && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle(data, data->render.render_isometric.angle - ANGLE_STEP);
	if (keycode == 93 && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_angle(data, data->render.render_isometric.angle + ANGLE_STEP);
	if (keycode == 57 && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_scale_z(data, data->render.render_isometric.scale_z - (float)((float)SCALE_Z_STEP / 10));
	if (keycode == 48 && data->render.projection == ISOMETRIC_PROJECTION)
		ft_update_scale_z(data, data->render.render_isometric.scale_z + SCALE_Z_STEP);
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
