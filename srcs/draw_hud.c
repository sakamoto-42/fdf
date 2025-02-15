/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:50:27 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/10 01:07:56 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_hud(t_data *data)
{
	ft_draw_panel_hud(data, data->header_panel);
	ft_draw_panel_hud(data, data->left_panel_1);
	if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_draw_panel_hud(data, data->left_panel_2_isometric);
	if (data->render.projection == CONIC_PROJECTION)
		ft_draw_panel_hud(data, data->left_panel_2_conic);
	ft_draw_panel_hud(data, data->right_panel_2);
	ft_draw_panel_hud(data, data->right_panel_1);
}

void	ft_draw_panel_hud(t_data *data, t_panel_hud panel_hud)
{
	t_pixel	pixel;

	pixel.y = panel_hud.offset_y;
	while (pixel.y < panel_hud.size_y + panel_hud.offset_y)
	{
		pixel.x = panel_hud.offset_x;
		while (pixel.x < panel_hud.size_x + panel_hud.offset_x)
		{
			ft_mlx_pixel_put(data, pixel, panel_hud.color, HUD);
			pixel.x++;
		}
		pixel.y++;
	}
}
