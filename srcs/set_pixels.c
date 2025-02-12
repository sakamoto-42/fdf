/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:37:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/12 17:01:47 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_process_pixel(t_data *data, t_pixel *pixel)
{
	if (!data->render.base_color)
		pixel->color = ft_get_color_for_pixel(data, pixel);
	ft_apply_scale_to_pixel(pixel, data->render.scale);
	ft_apply_scale_z_to_pixel(pixel, data->render.render_isometric.scale_z);
	if (data->render.projection == ISOMETRIC_PROJECTION)
		ft_render_isometric_projection(pixel, data->render);
	else if (data->render.projection == CONIC_PROJECTION)
		ft_render_conic_projection(pixel, data->render);
	ft_apply_offset_to_pixel(pixel, data->render);
}

void	ft_points_to_pixels(t_data *data)
{
	int		row_count;
	int		col_count;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			data->pixels[row_count][col_count].x -= data->render.map_center_x;
			data->pixels[row_count][col_count].y -= data->render.map_center_y;
			ft_process_pixel(data, &data->pixels[row_count][col_count]);
			col_count++;
		}
		row_count++;
	}
}
