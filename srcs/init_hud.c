/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:53:11 by julien            #+#    #+#             */
/*   Updated: 2025/02/08 16:30:00 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_panel_texts_offset_x(t_panel_hud *panel, int offset_x, int start)
{
	int	i;

	i = start;
	while (i < panel->texts_count)
	{
		panel->texts[i].offset_x = offset_x;
		i++;
	}
}

void	ft_set_panel_texts_color(t_panel_hud *panel, unsigned int color, int start)
{
	int	i;

	i = start;
	while (i < panel->texts_count)
	{
		panel->texts[i].color = color;
		i++;
	}
}

int	ft_allocate_panel_texts(t_panel_hud *panel)
{
	panel->texts = (t_text_hud *)ft_calloc(panel->texts_count,
			sizeof(t_text_hud));
	if (!panel->texts)
		return (0);
	return (1);
}

void	ft_set_panel_texts_offset_y(t_panel_hud *panel, int start)
{
	int	i;

	i = 0;
	while (i < panel->texts_count)
	{
		panel->texts[i].offset_y = start + ((i + 1) * HUD_TEXT_HEIGHT);
		i++;
	}
}

int	ft_init_hud(t_data *data)
{
	if (!ft_init_header_panel(data, &data->header_panel))
		return (0);
	if (!ft_init_left_panel_1(data, &data->left_panel_1))
		return (0);
	if (!ft_init_left_panel_2(data, &data->left_panel_2))
		return (0);
	if (!ft_init_right_panel_1(data, &data->right_panel_1))
		return (0);
	if (!ft_init_right_panel_2(data, &data->right_panel_2))
		return (0);
	data->hud_height = data->header_panel.size_y + data->left_panel_1.size_y;
	return (1);
}
