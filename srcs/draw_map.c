/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:36:48 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/12 15:03:02 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_bres_sx_sy(t_bresenham *bres, t_line line)
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

void	ft_update_bres(t_bresenham *bres, t_pixel *pixel)
{
	if (bres->e2 > -bres->dy)
	{
		bres->err -= bres->dy;
		pixel->x += bres->sx;
	}
	if (bres->e2 < bres->dx)
	{
		bres->err += bres->dx;
		pixel->y += bres->sy;
	}
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
			if (ft_line_is_in_screen(data, &line.pixel_1, &line.pixel_2))
			{
				ft_draw_horizontal_line(data, &line, row_count, col_count);
				ft_draw_vertical_line(data, &line, row_count, col_count);
			}
			col_count++;
		}
		row_count++;
	}
}
