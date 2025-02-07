/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_right_panel_hud.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:11:28 by julien            #+#    #+#             */
/*   Updated: 2025/02/07 13:26:17 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_right_panel(t_data *data, t_panel_hud *right_panel)
{
	right_panel->texts_count = 8;
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
	ft_set_panel_texts_offset_x(right_panel, right_panel->offset_x + HUD_TEXT_OFFSET_X, 1);
	ft_set_panel_texts_color(right_panel, ft_rgb_to_color(255, 255, 255), 0);
}

int	ft_radians_to_degrees(double angle)
{
	return ((int)((angle * 180.0 / M_PI) + 0.5));
}

void	ft_set_right_panel_offset_x(t_data *data,
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
}

void	ft_set_right_panel_offset_y(t_data *data,
	t_panel_hud *right_panel)
{
	char	*offset_y;
	char	*offset_y_display;

	offset_y = ft_itoa(data->render.offset_y);
	if (!offset_y)
		return ;
	offset_y_display = ft_strjoin("Offset y : ", offset_y);
	free(offset_y);
	if (!offset_y_display)
		return ;
	if (right_panel->texts[2].text)
		free(right_panel->texts[2].text);	
	right_panel->texts[2].text = offset_y_display;
}

void	ft_set_right_panel_scale(t_data *data,
	t_panel_hud *right_panel)
{
	char	*scale;
	char	*scale_display;

	scale = ft_itoa(data->render.scale);
	if (!scale)
		return ;
	scale_display = ft_strjoin("Scale : ", scale);
	free(scale);
	if (!scale_display)
		return ;
	if (right_panel->texts[3].text)
		free(right_panel->texts[3].text);	
	right_panel->texts[3].text = scale_display;
}

void	ft_set_right_panel_angle_x(t_data *data,
	t_panel_hud *right_panel)
{
	char	*angle_x;
	char	*angle_x_display;

	angle_x = ft_itoa(ft_radians_to_degrees(data->render.render_isometric.angle_x));
	if (!angle_x)
		return ;
	angle_x_display = ft_strjoin("Angle x : ", angle_x);
	free(angle_x);
	if (!angle_x_display)
		return ;
	if (right_panel->texts[4].text)
		free(right_panel->texts[4].text);	
	right_panel->texts[4].text = angle_x_display;
}

void	ft_set_right_panel_angle_y(t_data *data,
	t_panel_hud *right_panel)
{
	char	*angle_y;
	char	*angle_y_display;

	angle_y = ft_itoa(ft_radians_to_degrees(data->render.render_isometric.angle_y));
	if (!angle_y)
		return ;
	angle_y_display = ft_strjoin("Angle y : ", angle_y);
	free(angle_y);
	if (!angle_y_display)
		return ;
	if (right_panel->texts[5].text)
		free(right_panel->texts[5].text);	
	right_panel->texts[5].text = angle_y_display;
}

void	ft_set_right_panel_angle_z(t_data *data,
	t_panel_hud *right_panel)
{
	char	*angle_z;
	char	*angle_z_display;

	angle_z = ft_itoa(ft_radians_to_degrees(data->render.render_isometric.angle_z));
	if (!angle_z)
		return ;
	angle_z_display = ft_strjoin("Angle z : ", angle_z);
	free(angle_z);
	if (!angle_z_display)
		return ;
	if (right_panel->texts[6].text)
		free(right_panel->texts[6].text);	
	right_panel->texts[6].text = angle_z_display;
}
void	ft_set_right_panel_scale_z(t_data *data,
	t_panel_hud *right_panel)
{
	char	*scale_z;
	char	*scale_z_display;

	scale_z = ft_itoa(data->render.render_isometric.scale_z);
	if (!scale_z)
		return ;
	scale_z_display = ft_strjoin("Scale z : ", scale_z);
	free(scale_z);
	if (!scale_z_display)
		return ;
	if (right_panel->texts[7].text)
		free(right_panel->texts[7].text);	
	right_panel->texts[7].text = scale_z_display;
}


void	ft_set_right_panel_dynamic_texts(t_data *data,
	t_panel_hud *right_panel)
{
	ft_set_right_panel_offset_x(data, right_panel);
	ft_set_right_panel_offset_y(data, right_panel);
	ft_set_right_panel_scale(data, right_panel);
	ft_set_right_panel_angle_x(data, right_panel);
	ft_set_right_panel_angle_y(data, right_panel);
	ft_set_right_panel_angle_z(data, right_panel);
	ft_set_right_panel_scale_z(data, right_panel);
}