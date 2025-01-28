/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_and_free_pixels.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:30:01 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 14:03:34 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_allocate_pixels(t_data *data)
{
	int	i;

	i = 0;
	data->pixels = (t_pixel **) ft_calloc(data->map.rows,
			sizeof(t_pixel *));
	if (!data->pixels)
		return (ERROR_NOT_ENOUGH_MEMORY);
	while (i < data->map.rows)
	{
		data->pixels[i] = (t_pixel *) ft_calloc(data->map.cols,
				sizeof(t_pixel));
		if (!data->pixels[i])
			return (ft_free_pixels_until(data->pixels, i),
				ERROR_NOT_ENOUGH_MEMORY);
		i++;
	}
	return (SUCCESS);
}

t_pixel	**ft_free_pixels_until(t_pixel **pixels, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(pixels[i]);
		i++;
	}
	free(pixels);
	return (NULL);
}

t_pixel	**ft_free_pixels(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
	{
		free(data->pixels[i]);
		i++;
	}
	free(data->pixels);
	return (NULL);
}