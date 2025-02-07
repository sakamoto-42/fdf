/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_header_panel_hud.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:00:49 by julien            #+#    #+#             */
/*   Updated: 2025/02/07 10:55:13 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_header_panel(t_data *data, t_panel_hud *header_panel)
{
	header_panel->texts_count = 2;
	if (!ft_allocate_panel_texts(header_panel))
		return (0);
	ft_set_panel_texts_offset_y(header_panel, 0);
	ft_set_header_panel_display(data, header_panel);
	ft_set_header_panel_texts(data, header_panel);
	return (1);
}

void	ft_set_header_panel_display(t_data *data, t_panel_hud *header_panel)
{
	header_panel->size_x = data->window.size_x;
	header_panel->size_y = (data->header_panel.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	header_panel->offset_x = 0;
	header_panel->offset_y = 0;
	header_panel->color = ft_rgb_to_color(0, 0, 255);
}

void	ft_set_header_panel_texts(t_data *data, t_panel_hud *header_panel)
{
	header_panel->texts[0].text = data->map.map_file;
	header_panel->texts[0].offset_x = (data->window.size_x - 6
			* ft_strlen(header_panel->texts[0].text)) / 2;
	header_panel->texts[0].color = ft_rgb_to_color(255, 255, 255);
	header_panel->texts[1].text = "";
	header_panel->texts[1].offset_x = 0;
	header_panel->texts[1].color = ft_rgb_to_color(255, 255, 255);
}

void	ft_set_header_panel_dynamic_texts(t_data *data,
	t_panel_hud *header_panel)
{
	if (data->render.projection == ORTHOGONAL_PROJECTION)
		header_panel->texts[1].text = "Projection orthogonale";
	else if (data->render.projection == ISOMETRIC_PROJECTION)
		header_panel->texts[1].text = "Projection isometrique";
	else if (data->render.projection == CONIC_PROJECTION)
		header_panel->texts[1].text = "Projection conique";
	header_panel->texts[1].offset_x = (data->window.size_x - 6
			* ft_strlen(header_panel->texts[1].text)) / 2;
}
