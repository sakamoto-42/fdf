/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_right_panel_1_datas.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:10:12 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 16:11:48 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_right_panel_1_map_width(t_data *data,
	t_panel_hud *right_panel_1)
{
	char	*map_width;
	char	*map_width_display;

	map_width = ft_itoa(data->map.cols);
	if (!map_width)
		return ;
	map_width_display = ft_strjoin("Map width : ", map_width);
	free(map_width);
	if (!map_width_display)
		return ;
	right_panel_1->texts[1].text = map_width_display;
}

void	ft_set_right_panel_1_map_height(t_data *data,
	t_panel_hud *right_panel_1)
{
	char	*map_height;
	char	*map_height_display;

	map_height = ft_itoa(data->map.rows);
	if (!map_height)
		return ;
	map_height_display = ft_strjoin("Map height : ", map_height);
	free(map_height);
	if (!map_height_display)
		return ;
	right_panel_1->texts[2].text = map_height_display;
}

void	ft_set_right_panel_1_total_points(t_data *data,
	t_panel_hud *right_panel_1)
{
	char	*total_points;
	char	*total_points_display;

	total_points = ft_itoa(data->map.cols * data->map.rows);
	if (!total_points)
		return ;
	total_points_display = ft_strjoin("Total points : ", total_points);
	free(total_points);
	if (!total_points_display)
		return ;
	right_panel_1->texts[3].text = total_points_display;
}

void	ft_set_right_panel_1_min_z(t_data *data,
	t_panel_hud *right_panel_1)
{
	char	*min_z;
	char	*min_z_display;

	min_z = ft_itoa(ft_get_min_z(&data->map));
	if (!min_z)
		return ;
	min_z_display = ft_strjoin("Min z : ", min_z);
	free(min_z);
	if (!min_z_display)
		return ;
	right_panel_1->texts[4].text = min_z_display;
}

void	ft_set_right_panel_1_max_z(t_data *data,
	t_panel_hud *right_panel_1)
{
	char	*max_z;
	char	*max_z_display;

	max_z = ft_itoa(ft_get_max_z(&data->map));
	if (!max_z)
		return ;
	max_z_display = ft_strjoin("Max z : ", max_z);
	free(max_z);
	if (!max_z_display)
		return ;
	right_panel_1->texts[5].text = max_z_display;
}
