/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_right_panel_hud.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:11:28 by julien            #+#    #+#             */
/*   Updated: 2025/02/07 12:55:09 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_right_panel(t_data *data, t_panel_hud *right_panel)
{
	right_panel->texts_count = 10;
	if (!ft_allocate_panel_texts(right_panel))
		return (0);
	ft_set_panel_texts_offset_y(right_panel,
		(data->header_panel.texts_count + 1) * HUD_TEXT_HEIGHT);
	ft_set_right_panel_display(data, right_panel);
	ft_set_right_panel_texts(right_panel);
	return (1);
}

void	ft_set_right_panel_display(t_data *data, t_panel_hud *right_panel)
{
	right_panel->size_x = 200;
	right_panel->size_y = (right_panel->texts_count + 1)
		* HUD_TEXT_HEIGHT;
	right_panel->offset_x = data->window.size_x - right_panel->size_x;
	right_panel->offset_y = (data->header_panel.texts_count + 1)
		* HUD_TEXT_HEIGHT;
	right_panel->color = ft_rgb_to_color(255, 0, 0);
}

void	ft_set_right_panel_texts(t_panel_hud *right_panel)
{
	right_panel->texts[0].text = "TRANSFORMATIONS : ";
	right_panel->texts[0].offset_x = right_panel->offset_x
	+ (right_panel->size_x - 6
			* ft_strlen(right_panel->texts[0].text)) / 2;
	right_panel->texts[2].text = "";
	right_panel->texts[3].text = "";
	right_panel->texts[4].text = "";
	right_panel->texts[5].text = "";
	right_panel->texts[6].text = "";
	right_panel->texts[7].text = "";
	right_panel->texts[8].text = "";
	right_panel->texts[9].text = "";
	ft_set_panel_texts_offset_x(right_panel, right_panel->offset_x + HUD_TEXT_OFFSET_X, 1);
	ft_set_panel_texts_color(right_panel, ft_rgb_to_color(255, 255, 255), 0);
}

int	ft_radians_to_degrees(double angle)
{
	return (angle * 180.0 / M_PI);
}

void	ft_set_right_panel_dynamic_texts(t_data *data,
	t_panel_hud *right_panel)
{
	char	*offset_x;
	char	*offset_x_display;

	offset_x = ft_itoa(data->render.offset_x);
	if (!offset_x)
		return ;
	offset_x_display = ft_strjoin("Offset x : ", offset_x);
	free(offset_x);
	if (!offset_x_display)
		return ;
	if (right_panel->texts[1].text)
		free(right_panel->texts[1].text);	
	right_panel->texts[1].text = offset_x_display;
	
	/*
	free(offset_x);
	if (!offset_x_display)
		return ;
	if (right_panel->texts[1].text && ft_strncmp(right_panel->texts[1].text, "Offset x : ", 11) != 0)
		free(right_panel->texts[1].text);
	right_panel->texts[1].text = offset_x_display;
	free(offset_x_display);
	*/
	/*right_panel->texts[2].text = "Offset y : ";
	right_panel->texts[2].text = ft_strjoin(right_panel->texts[2].text, ft_itoa(data->render.offset_y));
	right_panel->texts[3].text = "Scale : ";
	right_panel->texts[3].text = ft_strjoin(right_panel->texts[3].text, ft_itoa(data->render.scale));
	right_panel->texts[4].text = "Angle x : ";
	right_panel->texts[4].text = ft_strjoin(right_panel->texts[4].text, ft_itoa(ft_radians_to_degrees(data->render.render_isometric.angle_x)));
	right_panel->texts[5].text = "Angle y : ";
	right_panel->texts[5].text = ft_strjoin(right_panel->texts[5].text, ft_itoa(data->render.render_isometric.angle_y));
	right_panel->texts[6].text = "Angle z : ";
	right_panel->texts[6].text = ft_strjoin(right_panel->texts[6].text, ft_itoa(data->render.render_isometric.angle_z));
	right_panel->texts[7].text = "Scale z : ";
	right_panel->texts[7].text = ft_strjoin(right_panel->texts[7].text, ft_itoa(data->render.render_isometric.scale_z));
	right_panel->texts[8].text = "Offset z : ";
	right_panel->texts[8].text = ft_strjoin(right_panel->texts[8].text, ft_itoa(data->render.render_isometric.offset_z));
	right_panel->texts[9].text = "Mirror mode : ";*/
	//right_panel->texts[9].text = ft_strjoin(right_panel->texts[9].text, ft_itoa(data->render.offset_y));
}