/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:21:03 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/12 14:17:54 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_center_map_orthogonal(t_data *data)
{
	data->render.offset_x = (data->window.size_x / 2)
		- (data->render.map_center_x * data->render.scale)
		+ data->render.scale * 9;
	data->render.offset_y = (data->window.size_y / 2)
		- (data->render.map_center_y * data->render.scale)
		+ data->render.scale * 9 - data->hud_height / 2;
	data->need_redraw = 2;
}

static void	ft_center_map_isometric(t_data *data)
{
	data->render.offset_x = (data->window.size_x / 2)
		- ((data->render.map_center_x - data->render.map_center_y)
			* data->render.scale * (double)cos(45 * (M_PI / 180)))
		+ data->render.scale * 3;
	data->render.offset_y = (data->window.size_y / 2)
		- ((data->render.map_center_y)
			* data->render.scale * (double)sin(45 * (M_PI / 180)))
		+ data->render.scale * 3;
	data->need_redraw = 2;
}

static void	ft_center_map_conic(t_data *data)
{
	data->render.offset_x = (data->window.size_x / 2)
		- ((data->render.map_center_x - data->render.map_center_y)
			* data->render.scale * 0.8) + data->render.scale * 2;
	data->render.offset_y = (data->window.size_y / 2)
		- ((data->render.map_center_x + data->render.map_center_y)
			* data->render.scale * 0.8) + data->render.scale * 2;
}

void	ft_center_map(t_data *data)
{
	if (data->render.projection == ORTHOGONAL_PROJECTION)
		ft_center_map_orthogonal(data);
	else if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_center_map_isometric(data);
	else if (data->render.projection == CONIC_PROJECTION)
		ft_center_map_conic(data);
}
