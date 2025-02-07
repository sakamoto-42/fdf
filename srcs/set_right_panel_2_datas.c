/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_right_panel_2_datas.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:43:05 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 16:19:47 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_right_panel_2_offset_x(t_data *data,
	t_panel_hud *right_panel_2)
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
	if (right_panel_2->texts[1].text)
		free(right_panel_2->texts[1].text);
	right_panel_2->texts[1].text = offset_x_display;
}

void	ft_set_right_panel_2_offset_y(t_data *data,
	t_panel_hud *right_panel_2)
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
	if (right_panel_2->texts[2].text)
		free(right_panel_2->texts[2].text);
	right_panel_2->texts[2].text = offset_y_display;
}

void	ft_set_right_panel_2_scale(t_data *data,
	t_panel_hud *right_panel_2)
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
	if (right_panel_2->texts[3].text)
		free(right_panel_2->texts[3].text);
	right_panel_2->texts[3].text = scale_display;
}

void	ft_set_right_panel_2_angle_x(t_data *data,
	t_panel_hud *right_panel_2)
{
	char	*angle_x;
	char	*angle_x_display;

	angle_x = ft_itoa(ft_radians_to_degrees(
				data->render.render_isometric.angle_x));
	if (!angle_x)
		return ;
	angle_x_display = ft_strjoin("Angle x : ", angle_x);
	free(angle_x);
	if (!angle_x_display)
		return ;
	if (right_panel_2->texts[4].text)
		free(right_panel_2->texts[4].text);
	right_panel_2->texts[4].text = angle_x_display;
}

void	ft_set_right_panel_2_angle_y(t_data *data,
	t_panel_hud *right_panel_2)
{
	char	*angle_y;
	char	*angle_y_display;

	angle_y = ft_itoa(ft_radians_to_degrees(
				data->render.render_isometric.angle_y));
	if (!angle_y)
		return ;
	angle_y_display = ft_strjoin("Angle y : ", angle_y);
	free(angle_y);
	if (!angle_y_display)
		return ;
	if (right_panel_2->texts[5].text)
		free(right_panel_2->texts[5].text);
	right_panel_2->texts[5].text = angle_y_display;
}
