/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:50:27 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/05 20:12:43 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_hud(t_data *data)
{
	ft_draw_panel_hud(data, data->header_panel);
	//ft_draw_panel_hud(data, data->left_panel_1);
	//ft_draw_panel_hud(data, data->left_panel_2);
	//ft_draw_panel_hud(data, data->right_panel);
}

void	ft_draw_panel_hud(t_data *data, t_panel_hud panel_hud)
{
	int	x;
	int	y;

	y = panel_hud.offset_y;
	while (y < panel_hud.size_y)
	{
		x = panel_hud.offset_x;
		while (x < panel_hud.size_x)
		{
			ft_mlx_pixel_put(data, x, y, panel_hud.color, HUD);
			x++;
		}
		y++;
	}
}