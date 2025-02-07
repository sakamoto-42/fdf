/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:37:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 17:34:27 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_pixels(t_data *data)
{
	ft_points_to_pixels(data);
	ft_set_pixels_color(data, data->render.color);
}

void	ft_points_to_pixels(t_data *data)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			ft_apply_scale_to_pixel(data->map.points[row_count][col_count],
				&data->pixels[row_count][col_count], data->render.scale);
			if (data->render.projection == ISOMETRIC_PROJECTION)
			{
				ft_render_isometric_projection(
					data->map.points[row_count][col_count],
					&data->pixels[row_count][col_count],
					data->render);
			}
			ft_apply_offset_to_pixel(&data->pixels[row_count][col_count],
				data->render);
			col_count++;
		}
		row_count++;
	}
}
