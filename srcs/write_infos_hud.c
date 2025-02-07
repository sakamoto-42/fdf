/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_infos_hud.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:52:26 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 12:17:50 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_write_hud_infos(t_data *data)
{
	ft_set_header_panel_dynamic_texts(data, &data->header_panel);
	ft_write_infos(data, &data->header_panel);
	ft_set_left_panel_1_dynamic_texts(data, &data->left_panel_1);
	ft_write_infos(data, &data->left_panel_1);
	if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_write_infos(data, &data->left_panel_2);
	ft_set_right_panel_dynamic_texts(data, &data->right_panel);
	ft_write_infos(data, &data->right_panel);
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
