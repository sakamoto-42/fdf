/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:22 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/05 20:19:20 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_screen_size(void *mlx_ptr, int *size_x, int *size_y)
{
	mlx_get_screen_size(mlx_ptr, size_x, size_y);
}

void	ft_init_default_settings(t_data *data)
{
	ft_get_screen_size(data->mlx_ptr, &data->window.size_x, &data->window.size_y);
	data->window.title = "fdf";
	data->render.projection = ISOMETRIC_PROJECTION;
	data->render.scale = 20;
	data->render.render_isometric.angle_x = M_PI / 6;
	data->render.render_isometric.scale_z = 5;
}

void	ft_init_hud(t_data *data)
{
	data->header_panel.texts_count = 2;
	data->header_panel.texts = ft_calloc(data->header_panel.texts_count, sizeof(t_text_hud));
	if (!data->header_panel.texts)
		return ;
	int i;
	i = 0;
	while (i < data->header_panel.texts_count)
	{
		data->header_panel.texts[i].offset_y = (i + 1) * HUD_TEXT_HEIGHT;
		i++;
	}
	data->header_panel.texts[0].text = data->map.map_file;
	data->header_panel.texts[0].offset_x = (data->window.size_x - 6 * ft_strlen(data->header_panel.texts[0].text)) / 2;
	data->header_panel.texts[0].color = ft_rgb_to_color(255, 255, 255);
	data->header_panel.texts[1].color = ft_rgb_to_color(255, 255, 255);
	data->header_panel.size_x = data->window.size_x;
	data->header_panel.size_y = (data->header_panel.texts_count + 1) * HUD_TEXT_HEIGHT;
	data->header_panel.offset_x = 0;
	data->header_panel.offset_y = 0;
	data->header_panel.color = ft_rgb_to_color(255, 0, 0);
	
	
	// TODO
	/*
	data->left_panel_1.size_x = 100;
	data->left_panel_1.size_y = 500;
	data->left_panel_2.size_x
	data->right_panel.size_x
	*/

	data->hud_height = data->header_panel.size_y;
}

void	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	ft_init_default_settings(data);
	ft_init_window(data);
	ft_init_hud(data);
	ft_center_map(data);
	ft_render_map(data);
}
