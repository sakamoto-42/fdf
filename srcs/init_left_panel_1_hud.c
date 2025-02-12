/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_left_panel_1_hud.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:02:18 by julien            #+#    #+#             */
/*   Updated: 2025/02/12 14:36:26 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_left_panel_1(t_data *data, t_panel_hud *left_panel_1)
{
	left_panel_1->texts_count = 16;
	if (!ft_allocate_panel_texts(left_panel_1))
		return (0);
	ft_set_panel_texts_offset_y(left_panel_1,
		(data->header_panel.texts_count + 1) * HUD_TEXT_HEIGHT);
	ft_set_left_panel_1_display(data, left_panel_1);
	ft_set_left_panel_1_texts(left_panel_1);
	return (1);
}

void	ft_set_left_panel_1_display(t_data *data, t_panel_hud *left_panel_1)
{
	left_panel_1->size_x = 200;
	left_panel_1->size_y = (left_panel_1->texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_1->offset_x = 0;
	left_panel_1->offset_y = (data->header_panel.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_1->color = ft_rgb_to_color(255, 0, 0);
}

void	ft_set_left_panel_1_texts(t_panel_hud *left_panel_1)
{
	left_panel_1->texts[0].text = "COMMANDS :";
	left_panel_1->texts[0].offset_x = left_panel_1->offset_x
		+ (left_panel_1->size_x - 6
			* ft_strlen(left_panel_1->texts[0].text)) / 2;
	left_panel_1->texts[1].text = "Exit : ESCAPE";
	left_panel_1->texts[2].text = "Move up : UP ARROW";
	left_panel_1->texts[3].text = "Move down : DOWN ARROW";
	left_panel_1->texts[4].text = "Move left : LEFT ARROW";
	left_panel_1->texts[5].text = "Move right : RIGHT ARROW";
	left_panel_1->texts[6].text = "";
	left_panel_1->texts[7].text = "";
	left_panel_1->texts[8].text = "";
	left_panel_1->texts[9].text = "Center map : C";
	left_panel_1->texts[10].text = "Mirror mode : M";
	left_panel_1->texts[11].text = "Zoom in : +";
	left_panel_1->texts[12].text = "Zoom out : -";
	left_panel_1->texts[13].text = "Change color : V";
	left_panel_1->texts[14].text = "Decrease z scale : [";
	left_panel_1->texts[15].text = "Increase z scale : ]";
	ft_set_panel_texts_offset_x(left_panel_1, left_panel_1->offset_x
		+ HUD_TEXT_OFFSET_X, 1);
	ft_set_panel_texts_color(left_panel_1,
		ft_rgb_to_color(255, 255, 255), 0);
}

void	ft_set_left_panel_1_dynamic_texts(t_data *data,
	t_panel_hud *left_panel_1)
{
	if (data->render.projection == ORTHOGONAL_PROJECTION)
	{
		left_panel_1->texts[6].text = "";
		left_panel_1->texts[7].text = "Isometric projection : 2";
		left_panel_1->texts[8].text = "Conic projection : 3";
	}
	if (data->render.projection == ISOMETRIC_PROJECTION)
	{
		left_panel_1->texts[6].text = "Orthogonal projection : 1";
		left_panel_1->texts[7].text = "";
		left_panel_1->texts[8].text = "Conic projection : 3";
	}
	if (data->render.projection == CONIC_PROJECTION)
	{
		left_panel_1->texts[6].text = "Orthogonal projection : 1";
		left_panel_1->texts[7].text = "Isometric projection : 2";
		left_panel_1->texts[8].text = "";
	}
}
