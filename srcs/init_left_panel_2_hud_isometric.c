/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_left_panel_2_hud_isometric.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:42 by julien            #+#    #+#             */
/*   Updated: 2025/02/12 14:38:09 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_left_panel_2_isometric(t_data *data,
	t_panel_hud *left_panel_2_isometric)
{
	left_panel_2_isometric->texts_count = 7;
	if (!ft_allocate_panel_texts(left_panel_2_isometric))
		return (0);
	ft_set_panel_texts_offset_y(left_panel_2_isometric,
		(data->header_panel.texts_count + 1) * HUD_TEXT_HEIGHT);
	ft_set_left_panel_2_display_isometric(data, left_panel_2_isometric);
	ft_set_left_panel_2_texts_isometric(left_panel_2_isometric);
	return (1);
}

void	ft_set_left_panel_2_display_isometric(t_data *data,
	t_panel_hud *left_panel_2_isometric)
{
	left_panel_2_isometric->size_x = 200;
	left_panel_2_isometric->size_y = (left_panel_2_isometric->texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_2_isometric->offset_x = 200;
	left_panel_2_isometric->offset_y = (data->header_panel.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_2_isometric->color = ft_rgb_to_color(255, 0, 0);
}

void	ft_set_left_panel_2_texts_isometric(t_panel_hud *left_panel_2_isometric)
{
	left_panel_2_isometric->texts[0].text = "ISOMETRIC PROJECTION COMMANDS :";
	left_panel_2_isometric->texts[0].offset_x = left_panel_2_isometric->offset_x
		+ (left_panel_2_isometric->size_x - 6
			* ft_strlen(left_panel_2_isometric->texts[0].text)) / 2;
	left_panel_2_isometric->texts[1].text = "Decrease angle x : Q";
	left_panel_2_isometric->texts[2].text = "Increase angle x : E";
	left_panel_2_isometric->texts[3].text = "Decrease angle y : A";
	left_panel_2_isometric->texts[4].text = "Increase angle y : D";
	left_panel_2_isometric->texts[5].text = "Decrease angle z : W";
	left_panel_2_isometric->texts[6].text = "Increase angle z : S";
	ft_set_panel_texts_offset_x(left_panel_2_isometric,
		left_panel_2_isometric->offset_x + HUD_TEXT_OFFSET_X, 1);
	ft_set_panel_texts_color(left_panel_2_isometric,
		ft_rgb_to_color(255, 255, 255), 0);
}
