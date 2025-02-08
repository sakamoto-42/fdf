/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_sets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:51:36 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/08 16:32:55 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_opposite_color(t_data *data, unsigned int color)
{
	int	r;
	int	g;
	int	b;

	r = 255 - ((color >> 16) & 0xFF);
	g = 255 - ((color >> 8) & 0xFF);
	b = 255 - (color & 0xFF);
	return (ft_rgb_to_color(data, r, g, b));
}

int	ft_init_color_sets(t_data *data)
{
	int	nb_color_sets;

	nb_color_sets = 9;
	data->colors = (unsigned int *)ft_calloc(nb_color_sets, sizeof(int));
	if (!data->colors)
		return (0);
	data->colors[0] = ft_rgb_to_color(data, 0, 255, 0);
	data->colors[1] = ft_rgb_to_color(data, 255, 87, 51);
	data->colors[2] = ft_rgb_to_color(data, 51, 255, 87);
	data->colors[3] = ft_rgb_to_color(data, 51, 87, 255);
	data->colors[4] = ft_rgb_to_color(data, 255, 215, 0);
	data->colors[5] = ft_rgb_to_color(data, 255, 51, 161);
	data->colors[6] = ft_rgb_to_color(data, 0, 255, 255);
	data->colors[7] = ft_rgb_to_color(data, 255, 165, 0);
	data->colors[8] = ft_rgb_to_color(data, 128, 0, 128);
	if (!ft_init_opposite_color_sets(data, data->colors, nb_color_sets))
	{
		free(data->colors);
		return (0);
	}
	return (1);
}

int	ft_init_opposite_color_sets(t_data *data, unsigned int *colors, int nb_color_sets)
{
	int	i;

	data->opposite_colors = (unsigned int *)ft_calloc(nb_color_sets, sizeof(int));
	if (!data->opposite_colors)
		return (0);
	i = 0;
	while (i < nb_color_sets)
	{
		data->opposite_colors[i] = ft_get_opposite_color(data, colors[i]);
		i++;
	}
	return (1);
}
