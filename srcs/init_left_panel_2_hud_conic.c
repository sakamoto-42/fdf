/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_left_panel_2_hud_conic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:42 by julien            #+#    #+#             */
/*   Updated: 2025/02/10 01:21:53 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_left_panel_2_conic(t_data *data, t_panel_hud *left_panel_2_conic)
{
	left_panel_2_conic->texts_count = 11;
	if (!ft_allocate_panel_texts(left_panel_2_conic))
		return (0);
	ft_set_panel_texts_offset_y(left_panel_2_conic,
		(data->header_panel.texts_count + 1) * HUD_TEXT_HEIGHT);
	ft_set_left_panel_2_display_conic(data, left_panel_2_conic);
	ft_set_left_panel_2_texts_conic(data, left_panel_2_conic);
	return (1);
}

void	ft_set_left_panel_2_display_conic(t_data *data,
	t_panel_hud *left_panel_2_conic)
{
	left_panel_2_conic->size_x = 200;
	left_panel_2_conic->size_y = (left_panel_2_conic->texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_2_conic->offset_x = 200;
	left_panel_2_conic->offset_y = (data->header_panel.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_2_conic->color = ft_rgb_to_color(data, 255, 0, 0);
}

void	ft_set_left_panel_2_texts_conic(t_data *data,
	t_panel_hud *left_panel_2_conic)
{
	left_panel_2_conic->texts[0].text = "CONIC PROJECTION COMMANDS :";
	left_panel_2_conic->texts[0].offset_x = left_panel_2_conic->offset_x
		+ (left_panel_2_conic->size_x - 6
			* ft_strlen(left_panel_2_conic->texts[0].text)) / 2;
	left_panel_2_conic->texts[1].text = "Decrease angle : Q";
	left_panel_2_conic->texts[2].text = "Increase angle : E";
	left_panel_2_conic->texts[3].text = "Decrease distance : A";
	left_panel_2_conic->texts[4].text = "Increase distance : D";
	left_panel_2_conic->texts[5].text = "Decrease distortion x : W";
	left_panel_2_conic->texts[6].text = "Increase distortion x : S";
	left_panel_2_conic->texts[7].text = "Decrease distortion y : Z";
	left_panel_2_conic->texts[8].text = "Increase distortion y : X";
	left_panel_2_conic->texts[9].text = "Decrease perspective : [";
	left_panel_2_conic->texts[10].text = "Increase perspective : ]";
	ft_set_panel_texts_offset_x(left_panel_2_conic, left_panel_2_conic->offset_x
		+ HUD_TEXT_OFFSET_X, 1);
	ft_set_panel_texts_color(left_panel_2_conic,
		ft_rgb_to_color(data, 255, 255, 255), 0);
}
