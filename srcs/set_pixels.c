/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:37:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/10 16:30:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_process_pixel(t_data *data, t_point *point, t_pixel *pixel)
{
	pixel->z = point->z;
	pixel->color = ft_get_color_for_pixel(data, pixel);
	ft_apply_scale_to_pixel(*point, pixel, data->render.scale);
	if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_render_isometric_projection(pixel, data->render);
	else if (data->render.projection == CONIC_PROJECTION)
		ft_render_conic_projection(*point, pixel, data->render);
	ft_apply_scale_z_to_pixel(*point, pixel,
		data->render.render_isometric.scale_z);
	ft_apply_offset_to_pixel(pixel, data->render);
}

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
			point.x -= data->render.map_center_x;
			point.y -= data->render.map_center_y;
			ft_process_pixel(data, &point, pixel);
			col_count++;
		}
		row_count++;
	}
}
