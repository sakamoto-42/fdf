/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:30:33 by julien            #+#    #+#             */
/*   Updated: 2025/02/10 11:27:10 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_keys_translation(t_data *data)
{
	if (data->input.keys[KEY_MOVE_UP])
		data->render.offset_y -= TRANSLATION_STEP;
	if (data->input.keys[KEY_MOVE_DOWN])
		data->render.offset_y += TRANSLATION_STEP;
	if (data->input.keys[KEY_MOVE_LEFT])
		data->render.offset_x -= TRANSLATION_STEP;
	if (data->input.keys[KEY_MOVE_RIGHT])
		data->render.offset_x += TRANSLATION_STEP;
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
