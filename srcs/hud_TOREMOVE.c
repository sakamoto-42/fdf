/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_TOREMOVE.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:59:59 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/06 11:11:23 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	ft_write_infos_header_text_hud(t_data *data, int *offset_y)
{
	ft_draw_commands_title_hud(data, "COMMANDS :", offset_y);
	*offset_y += 40;
	ft_draw_commands_general_hud(data, "Exit : ESCAPE", offset_y);
	*offset_y += 20;
	ft_draw_commands_general_hud(data, "Move up : UP ARROW", offset_y);
	*offset_y += 20;
	ft_draw_commands_general_hud(data, "Move down : DOWN ARROW", offset_y);
	*offset_y += 20;
	ft_draw_commands_general_hud(data, "Move left : LEFT ARROW", offset_y);
	*offset_y += 20;
	ft_draw_commands_general_hud(data, "Move right : RIGHT ARROW", offset_y);
	offset_y += 20;
	if (data->render.projection != ORTHOGONAL_PROJECTION)
	{
		ft_draw_commands_general_hud(
			data, "Orthogonal projection : 1", offset_y);
		offset_y += 20;
	}
	if (data->render.projection != ISOMETRIC_PROJECTION)
	{
		ft_draw_commands_general_hud(data, "Isometric projection : 2", offset_y);
		offset_y += 20;
	}
	if (data->render.projection != CONIC_PROJECTION)
	{
		ft_draw_commands_general_hud(data, "Conic projection : 3", offset_y);
		offset_y += 20;
	}
}

void	ft_write_left_panel_title_hud(t_data *data, char *text, int offset_y)
{
	int		text_x = HUD_OFFSET_X;
	int		text_y = 20 + offset_y;
	mlx_string_put(data->mlx_ptr,
		data->window.win_ptr, text_x, text_y, ft_rgb_to_color(0, 255, 0), text);
}

void	ft_write_left_panel_general_infos_hud(t_data *data,
	char *text, int offset_y)
{
	int		text_x = HUD_OFFSET_X;
	int		text_y = 20 + offset_y;
	mlx_string_put(data->mlx_ptr, data->window.win_ptr,
		text_x, text_y, ft_rgb_to_color(0, 255, 0), text);
}

void	ft_write_left_panel_specific_infos_hud(t_data *data,
	char *text, int offset_y)
{
	int		text_x = HUD_OFFSET_X + 200;
	int		text_y = 20 + offset_y;
	mlx_string_put(data->mlx_ptr, data->window.win_ptr,
		text_x, text_y, ft_rgb_to_color(0, 255, 0), text);
}
*/
