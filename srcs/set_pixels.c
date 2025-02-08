/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:37:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/08 21:55:42 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_points_to_pixels(t_data *data)
{
	int		row_count;
	int		col_count;
	t_point	point;
	t_pixel	*pixel;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			point = data->map.points[row_count][col_count];
			pixel = &data->pixels[row_count][col_count];
			pixel->z = point.z;
			pixel->color = ft_get_color_for_pixel(data, pixel);
			ft_apply_scale_to_pixel(point, pixel, data->render.scale);
			if (data->render.projection == ISOMETRIC_PROJECTION)
				ft_render_isometric_projection(point, pixel, data->render);
			ft_apply_offset_to_pixel(pixel, data->render);
			col_count++;
		}
		row_count++;
	}
}
