/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_left_panel_1_hud.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:02:18 by julien            #+#    #+#             */
/*   Updated: 2025/02/06 12:55:51 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int	ft_init_left_panel_1(t_data *data, t_panel_hud *left_panel_1)
{
	left_panel_1->texts_count = 7;
	if (!ft_allocate_panel_texts(left_panel_1))
		return (0);
	ft_set_panel_texts_offset_y(left_panel_1);
	ft_set_left_panel_1_texts(data, left_panel_1);
	ft_set_left_panel_1_display(data, left_panel_1);
	return (1);
}

void	ft_set_left_panel_1_texts(t_data *data, t_panel_hud *left_panel_1)
{
	left_panel_1->texts[0].text = data->map.map_file;
	left_panel_1->texts[0].offset_x = (data->window.size_x - 6
			* ft_strlen(data->left_panel_1.texts[0].text)) / 2;
	left_panel_1->texts[0].color = ft_rgb_to_color(255, 255, 255);
	left_panel_1->texts[1].color = ft_rgb_to_color(255, 255, 255);
}

void	ft_set_left_panel_1_display(t_data *data, t_panel_hud *left_panel_1)
{
	left_panel_1->size_x = data->window.size_x;
	left_panel_1->size_y = (data->left_panel_1.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	left_panel_1->offset_x = 0;
	left_panel_1->offset_y = 0;
	left_panel_1->color = ft_rgb_to_color(255, 0, 0);
}
*/
