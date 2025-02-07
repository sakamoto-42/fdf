/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_right_panel_2_hud.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:17:21 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 16:17:54 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_right_panel_2(t_data *data, t_panel_hud *right_panel_2)
{
	right_panel_2->texts_count = 8;
	if (!ft_allocate_panel_texts(right_panel_2))
		return (0);
	ft_set_panel_texts_offset_y(right_panel_2,
		(data->header_panel.texts_count + 1) * HUD_TEXT_HEIGHT);
	ft_set_right_panel_2_display(data, right_panel_2);
	ft_set_right_panel_2_texts(right_panel_2);
	return (1);
}

void	ft_set_right_panel_2_display(t_data *data, t_panel_hud *right_panel_2)
{
	right_panel_2->size_x = 200;
	right_panel_2->size_y = (right_panel_2->texts_count + 1)
		* HUD_TEXT_HEIGHT;
	right_panel_2->offset_x = data->window.size_x - right_panel_2->size_x;
	right_panel_2->offset_y = (data->header_panel.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	right_panel_2->color = ft_rgb_to_color(255, 0, 0);
}

void	ft_set_right_panel_2_texts(t_panel_hud *right_panel_2)
{
	right_panel_2->texts[0].text = "TRANSFORMATIONS : ";
	right_panel_2->texts[0].offset_x = right_panel_2->offset_x
		+ (right_panel_2->size_x - 6
			* ft_strlen(right_panel_2->texts[0].text)) / 2;
	ft_set_panel_texts_offset_x(right_panel_2,
		right_panel_2->offset_x + HUD_TEXT_OFFSET_X, 1);
	ft_set_panel_texts_color(right_panel_2, ft_rgb_to_color(255, 255, 255), 0);
}

void	ft_set_right_panel_2_dynamic_texts(t_data *data,
	t_panel_hud *right_panel_2)
{
	ft_set_right_panel_2_offset_x(data, right_panel_2);
	ft_set_right_panel_2_offset_y(data, right_panel_2);
	ft_set_right_panel_2_scale(data, right_panel_2);
	ft_set_right_panel_2_angle_x(data, right_panel_2);
	ft_set_right_panel_2_angle_y(data, right_panel_2);
	ft_set_right_panel_2_angle_z(data, right_panel_2);
	ft_set_right_panel_2_scale_z(data, right_panel_2);
}
