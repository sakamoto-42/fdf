/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:12:43 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/11 15:49:26 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_radians_to_degrees(double angle)
{
	return ((int)((angle * 180.0 / M_PI) + 0.5));
}

int	ft_get_min_z(t_data *data)
{
	int	min_z;
	int	row_count;
	int	col_count;

	row_count = 0;
	min_z = data->pixels[0][0].z;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			if (data->pixels[row_count][col_count].z < min_z)
				min_z = data->pixels[row_count][col_count].z;
			col_count++;
		}
		row_count++;
	}
	return (min_z);
}

int	ft_get_max_z(t_data *data)
{
	int	max_z;
	int	row_count;
	int	col_count;

	row_count = 0;
	max_z = data->pixels[0][0].z;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			if (data->pixels[row_count][col_count].z > max_z)
				max_z = data->pixels[row_count][col_count].z;
			col_count++;
		}
		row_count++;
	}
	return (max_z);
}
