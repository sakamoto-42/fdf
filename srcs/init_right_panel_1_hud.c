/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_right_panel_1_hud.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:48:11 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/08 16:34:07 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_right_panel_1(t_data *data, t_panel_hud *right_panel_1)
{
	right_panel_1->texts_count = 6;
	if (!ft_allocate_panel_texts(right_panel_1))
		return (0);
	ft_set_panel_texts_offset_y(right_panel_1,
		(data->header_panel.texts_count + 1) * HUD_TEXT_HEIGHT);
	ft_set_right_panel_1_display(data, right_panel_1);
	ft_set_right_panel_1_texts(data, right_panel_1);
	return (1);
}

void	ft_set_right_panel_1_display(t_data *data, t_panel_hud *right_panel_1)
{
	right_panel_1->size_x = 200;
	right_panel_1->size_y = (right_panel_1->texts_count + 1)
		* HUD_TEXT_HEIGHT;
	right_panel_1->offset_x = data->window.size_x - right_panel_1->size_x
		- data->right_panel_1.size_x;
	right_panel_1->offset_y = (data->header_panel.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	right_panel_1->color = ft_rgb_to_color(data, 255, 0, 0);
}

void	ft_set_right_panel_1_texts(t_data *data, t_panel_hud *right_panel_1)
{
	right_panel_1->texts[0].text = "MAP INFOS :";
	right_panel_1->texts[0].offset_x = right_panel_1->offset_x
		+ (right_panel_1->size_x - 6
			* ft_strlen(right_panel_1->texts[0].text)) / 2;
	ft_set_right_panel_1_map_width(data, right_panel_1);
	ft_set_right_panel_1_map_height(data, right_panel_1);
	ft_set_right_panel_1_total_points(data, right_panel_1);
	ft_set_right_panel_1_min_z(data, right_panel_1);
	ft_set_right_panel_1_max_z(data, right_panel_1);
	ft_set_panel_texts_offset_x(right_panel_1, right_panel_1->offset_x
		+ HUD_TEXT_OFFSET_X, 1);
	ft_set_panel_texts_color(right_panel_1,
		ft_rgb_to_color(data, 255, 255, 255), 0);
}
