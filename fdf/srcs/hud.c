/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:59:59 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/04 16:08:07 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_header_text_hud(t_data *data, char *text, int offset_y)
{
	int		text_width = 6 * ft_strlen(text);
	int		text_x = (data->window.size_x - text_width) / 2;
	int		text_y = (HUD_HEIGHT / 2) + offset_y;
	mlx_string_put(data->mlx_ptr, data->window.win_ptr, text_x, text_y, ft_rgb_to_color(255, 255, 255), text);
}

void	ft_draw_commands_title_hud(t_data *data, char *text, int offset_y)
{
	int		text_x = HUD_OFFSET_X;
	int		text_y = (HUD_HEIGHT / 2) + offset_y;
	mlx_string_put(data->mlx_ptr, data->window.win_ptr, text_x, text_y, ft_rgb_to_color(0, 255, 0), text);
}

void	ft_draw_commands_general_hud(t_data *data, char *text, int offset_y)
{
	int		text_x = HUD_OFFSET_X;
	int		text_y = (HUD_HEIGHT / 2) + offset_y;
	mlx_string_put(data->mlx_ptr, data->window.win_ptr, text_x, text_y, ft_rgb_to_color(0, 255, 0), text);
}

void	ft_draw_commands_isometric_hud(t_data *data, char *text, int offset_y)
{
	int		text_x = HUD_OFFSET_X + 200;
	int		text_y = (HUD_HEIGHT / 2) + offset_y;
	mlx_string_put(data->mlx_ptr, data->window.win_ptr, text_x, text_y, ft_rgb_to_color(0, 255, 0), text);
}

void	ft_draw_infos_hud(t_data *data)
{
	int	offset_y;
	
	offset_y = 0;
	ft_draw_header_text_hud(data, data->map.map_file, offset_y);
	offset_y += 20;
	if (data->render.projection == ORTHOGONAL_PROJECTION)
		ft_draw_header_text_hud(data, "Projection orthogonale", offset_y);
	else if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_draw_header_text_hud(data, "Projection isometrique", offset_y);
	else if (data->render.projection == CONIC_PROJECTION)
		ft_draw_header_text_hud(data, "Projection conique", offset_y);
	offset_y += 20;
	ft_draw_commands_title_hud(data, "COMMANDS :", offset_y);
	offset_y += 40;
	ft_draw_commands_general_hud(data, "Exit : ESCAPE", offset_y);
	offset_y += 20;
	ft_draw_commands_general_hud(data, "Move up : UP ARROW", offset_y);
	offset_y += 20;
	ft_draw_commands_general_hud(data, "Move down : DOWN ARROW", offset_y);
	offset_y += 20;
	ft_draw_commands_general_hud(data, "Move left : LEFT ARROW", offset_y);
	offset_y += 20;
	ft_draw_commands_general_hud(data, "Move right : RIGHT ARROW", offset_y);
	offset_y += 20;
	if (data->render.projection != ORTHOGONAL_PROJECTION)
	{
		ft_draw_commands_general_hud(data, "Orthogonal projection : 1", offset_y);
		offset_y += 20;
	}
	if (data->render.projection != ISOMETRIC_PROJECTION)
	{
		ft_draw_commands_general_hud(data, "Isometric projection : 2", offset_y);
		offset_y += 20;
	}
	/*
	if (data->render.projection != CONIC_PROJECTION)
	{
		ft_draw_commands_general_hud(data, "Conic projection : 3", offset_y);
		offset_y += 20;
	}
	*/
	ft_draw_commands_general_hud(data, "Center : C", offset_y);
	offset_y += 20;
	ft_draw_commands_general_hud(data, "Mirror : M", offset_y);
	offset_y += 20;
	ft_draw_commands_general_hud(data, "Zoom in : +", offset_y);
	offset_y += 20;
	ft_draw_commands_general_hud(data, "Zoom out : -", offset_y);
	if (data->render.projection == ISOMETRIC_PROJECTION)
	{
		offset_y = 40;
		ft_draw_commands_isometric_hud(data, "COMMANDS FOR ISOMETRIC PROJECTION :", offset_y);
		offset_y += 40;
		ft_draw_commands_isometric_hud(data, "Decrease x angle : Q", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Increase x angle : E", offset_y);
		offset_y += 20;
		/*
		ft_draw_commands_isometric_hud(data, "Decrease y angle : A", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Increase y angle : D", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Decrease z angle : W", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Increase z angle : S", offset_y);
		offset_y += 20;
		*/
		ft_draw_commands_isometric_hud(data, "Decrease z scale : [", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Increase z scale : ]", offset_y);
	}
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

