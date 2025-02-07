/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_right_panel_2_datas_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:43:53 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 16:20:11 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_right_panel_2_angle_z(t_data *data,
	t_panel_hud *right_panel_2)
{
	char	*angle_z;
	char	*angle_z_display;

	angle_z = ft_itoa(ft_radians_to_degrees(
				data->render.render_isometric.angle_z));
	if (!angle_z)
		return ;
	angle_z_display = ft_strjoin("Angle z : ", angle_z);
	free(angle_z);
	if (!angle_z_display)
		return ;
	if (right_panel_2->texts[6].text)
		free(right_panel_2->texts[6].text);
	right_panel_2->texts[6].text = angle_z_display;
}

void	ft_set_right_panel_2_scale_z(t_data *data,
	t_panel_hud *right_panel_2)
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
	if (right_panel_2->texts[7].text)
		free(right_panel_2->texts[7].text);
	right_panel_2->texts[7].text = scale_z_display;
}
