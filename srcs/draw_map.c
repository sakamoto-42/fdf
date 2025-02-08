/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:36:48 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/08 14:52:25 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_bres_sx_sy(t_bresenham *bres, t_line line)
{
	if (line.pixel_1.x < line.pixel_2.x)
		bres->sx = 1;
	else
		bres->sx = -1;
	if (line.pixel_1.y < line.pixel_2.y)
		bres->sy = 1;
	else
		bres->sy = -1;
}

void	ft_draw_line(t_data *data, t_line line)
{
	t_bresenham	bres;

	bres.dx = ft_abs(line.pixel_2.x - line.pixel_1.x);
	bres.dy = ft_abs(line.pixel_2.y - line.pixel_1.y);
	ft_set_bres_sx_sy(&bres, line);
	bres.err = bres.dx - bres.dy;
	while (!(line.pixel_1.x == line.pixel_2.x
			&& line.pixel_1.y == line.pixel_2.y))
	{
		ft_apply_color_to_pixel(data, &line.pixel_1, &line.pixel_2);
		ft_mlx_pixel_put(data, line.pixel_1, line.pixel_1.color, MAP);
		bres.e2 = bres.err * 2;
		if (bres.e2 > -bres.dy)
		{
			bres.err -= bres.dy;
			line.pixel_1.x += bres.sx;
		}
		if (bres.e2 < bres.dx)
		{
			bres.err += bres.dx;
			line.pixel_1.y += bres.sy;
		}
	}
	ft_mlx_pixel_put(data, line.pixel_1, line.pixel_1.color, MAP);
}

void	ft_draw_map(t_data *data)
{
	t_line	line;
	int		row_count;
	int		col_count;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			line.pixel_1 = data->pixels[row_count][col_count];
			if (col_count < data->map.cols - 1)
			{
				line.pixel_2 = data->pixels[row_count][col_count + 1];
				ft_draw_line(data, line);
			}
			if (row_count < data->map.rows - 1)
			{
				line.pixel_2 = data->pixels[row_count + 1][col_count];
				ft_draw_line(data, line);
			}
			col_count++;
		}
		row_count++;
	}
}
