/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:21:41 by julien            #+#    #+#             */
/*   Updated: 2025/02/07 15:43:25 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_panel_texts(t_panel_hud panel)
{
	int	i;

	i = 1;
	while (i < panel.texts_count)
	{
		free(panel.texts[i].text);
		i++;
	}
	free(panel.texts);
}

void	ft_free_hud_panels(t_data *data)
{
	if (data->header_panel.texts)
		free(data->header_panel.texts);
	if (data->left_panel_1.texts)
		free(data->left_panel_1.texts);
	if (data->left_panel_2.texts)
		free(data->left_panel_2.texts);
	if (data->right_panel_1.texts)
		ft_free_panel_texts(data->right_panel_1);
	if (data->right_panel_2.texts)
		ft_free_panel_texts(data->right_panel_2);
}

void	ft_destroy_and_free_all(t_data *data)
{
	if (data->image.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	if (data->window.win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->window.win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map.points)
		ft_free_points(data);
	if (data->pixels)
		ft_free_pixels(data);
	ft_free_hud_panels(data);
}
