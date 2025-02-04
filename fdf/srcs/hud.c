/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:59:59 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/04 12:42:30 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_text_hud(t_data *data, char *text, int offset_y)
{
	int		text_width = 6 * ft_strlen(text);
	int		text_x = (data->window.size_x - text_width) / 2;
	int		text_y = (HUD_HEIGHT / 2) + offset_y;
	mlx_string_put(data->mlx_ptr, data->window.win_ptr, text_x, text_y, ft_rgb_to_color(255, 255, 255), text);
}

void	ft_draw_infos_hud(t_data *data)
{
	int	offset_y;
	
	offset_y = 0;
	ft_draw_text_hud(data, data->map.map_file, offset_y);
	offset_y += 20;
	if (data->render.projection == ORTHOGONAL_PROJECTION)
		ft_draw_text_hud(data, "Projection orthogonale", offset_y);
	else if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_draw_text_hud(data, "Projection isometrique", offset_y);
	
}

void	ft_draw_hud(t_data *data)
{
	int	x;
	int	y;
	int	color;

	color = ft_rgb_to_color(0, 0, 0);
	y = 0;
	while (y < HUD_HEIGHT)
	{
		x = 0;
		while (x < data->window.size_x)
		{
			ft_mlx_pixel_put(data, x, y, color, HUD);
			x++;
		}
		y++;
	}
}

