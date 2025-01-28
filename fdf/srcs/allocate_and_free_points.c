/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_and_free_points.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:53:01 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 14:03:28 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_allocate_points(t_data *data)
{
	int	i;

	i = 0;
	data->map.points = (t_point **) ft_calloc(data->map.rows,
			sizeof(t_point *));
	if (!data->map.points)
		return (ERROR_NOT_ENOUGH_MEMORY);
	while (i < data->map.rows)
	{
		data->map.points[i] = (t_point *) ft_calloc(data->map.cols,
				sizeof(t_point));
		if (!data->map.points[i])
			return (ft_free_points_until(data->map.points, i),
				ERROR_NOT_ENOUGH_MEMORY);
		i++;
	}
	return (SUCCESS);
}

t_point	**ft_free_points_until(t_point **points, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(points[i]);
		i++;
	}
	free(points);
	return (NULL);
}

t_pixel	**ft_free_points(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
	{
		free(data->map.points[i]);
		i++;
	}
	free(data->map.points);
	return (NULL);
}