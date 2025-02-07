/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:12:43 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 16:20:34 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_radians_to_degrees(double angle)
{
	return ((int)((angle * 180.0 / M_PI) + 0.5));
}

int	ft_get_min_z(t_map *map)
{
	int	min_z;
	int	row_count;
	int	col_count;

	row_count = 0;
	min_z = map->points[0][0].z;
	while (row_count < map->rows)
	{
		col_count = 0;
		while (col_count < map->cols)
		{
			if (map->points[row_count][col_count].z < min_z)
				min_z = map->points[row_count][col_count].z;
			col_count++;
		}
		row_count++;
	}
	return (min_z);
}

int	ft_get_max_z(t_map *map)
{
	int	max_z;
	int	row_count;
	int	col_count;

	row_count = 0;
	max_z = map->points[0][0].z;
	while (row_count < map->rows)
	{
		col_count = 0;
		while (col_count < map->cols)
		{
			if (map->points[row_count][col_count].z > max_z)
				max_z = map->points[row_count][col_count].z;
			col_count++;
		}
		row_count++;
	}
	return (max_z);
}
