/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_left_panel_2_hud.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:42 by julien            #+#    #+#             */
/*   Updated: 2025/02/08 16:36:28 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_left_panel_2(t_data *data, t_panel_hud *left_panel_2)
{
	left_panel_2->texts_count = 9;
	if (!ft_allocate_panel_texts(left_panel_2))
		return (0);
	ft_set_panel_texts_offset_y(left_panel_2,
		(data->header_panel.texts_count + 1) * HUD_TEXT_HEIGHT);
	ft_set_left_panel_2_display(data, left_panel_2);
	ft_set_left_panel_2_texts(data, left_panel_2);
	return (1);
}

void	ft_set_left_panel_2_display(t_data *data, t_panel_hud *left_panel_2)
{
	left_panel_2->size_x = 200;
	left_panel_2->size_y = (left_panel_2->texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_2->offset_x = 200;
	left_panel_2->offset_y = (data->header_panel.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_2->color = ft_rgb_to_color(data, 255, 0, 0);
}

void	ft_set_left_panel_2_texts(t_data *data, t_panel_hud *left_panel_2)
{
	left_panel_2->texts[0].text = "ISOMETRIC PROJECTION COMMANDS :";
	left_panel_2->texts[0].offset_x = left_panel_2->offset_x
		+ (left_panel_2->size_x - 6
			* ft_strlen(left_panel_2->texts[0].text)) / 2;
	left_panel_2->texts[1].text = "Decrease x angle : Q";
	left_panel_2->texts[2].text = "Increase x angle : E";
	left_panel_2->texts[3].text = "Decrease y angle : A";
	left_panel_2->texts[4].text = "Increase y angle : D";
	left_panel_2->texts[5].text = "Decrease z angle : W";
	left_panel_2->texts[6].text = "Increase z angle : S";
	left_panel_2->texts[7].text = "Decrease z scale : [";
	left_panel_2->texts[8].text = "Increase z scale : ]";
	ft_set_panel_texts_offset_x(left_panel_2, left_panel_2->offset_x
		+ HUD_TEXT_OFFSET_X, 1);
	ft_set_panel_texts_color(left_panel_2,
		ft_rgb_to_color(data, 255, 255, 255), 0);
}
