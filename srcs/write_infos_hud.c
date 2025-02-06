/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_infos_hud.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:52:26 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/06 11:14:46 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_dynamic_infos(t_data *data)
{
	if (data->render.projection == ORTHOGONAL_PROJECTION)
		data->header_panel.texts[1].text = "Projection orthogonale";
	else if (data->render.projection == ISOMETRIC_PROJECTION)
		data->header_panel.texts[1].text = "Projection isometrique";
	else if (data->render.projection == CONIC_PROJECTION)
		data->header_panel.texts[1].text = "Projection conique";
	data->header_panel.texts[1].offset_x = (data->window.size_x - 6
			* ft_strlen(data->header_panel.texts[1].text)) / 2;
}

// TO ADD
//ft_write_infos(data, &data->left_panel_1);
//ft_write_infos(data, &data->left_panel_2);
//ft_write_infos(data, &data->right_panel);
void	ft_write_hud_infos(t_data *data)
{
	ft_set_dynamic_infos(data);
	ft_write_infos(data, &data->header_panel);
}

void	ft_write_infos(t_data *data, t_panel_hud *panel)
{
	int	i;

	i = 0;
	while (i < panel->texts_count)
	{
		mlx_string_put(data->mlx_ptr,
			data->window.win_ptr, panel->texts[i].offset_x,
			panel->texts[i].offset_y,
			panel->texts[i].color,
			panel->texts[i].text);
		i++;
	}
}

/*
void	ft_write_infos_hud(t_data *data)
{
	t_text_hud	text_hud;

	text_hud.offset_y = 0;
	ft_write_infos_left_panel_general(data, &text_hud);

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
		ft_draw_commands_isometric_hud(data,
			"COMMANDS FOR ISOMETRIC PROJECTION :", offset_y);
		offset_y += 40;
		ft_draw_commands_isometric_hud(data, "Decrease x angle : Q", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Increase x angle : E", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Decrease y angle : A", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Increase y angle : D", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Decrease z angle : W", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Increase z angle : S", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Decrease z scale : [", offset_y);
		offset_y += 20;
		ft_draw_commands_isometric_hud(data, "Increase z scale : ]", offset_y);
	}
}
*/
