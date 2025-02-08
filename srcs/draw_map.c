/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:36:48 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/08 16:31:34 by juduchar         ###   ########.fr       */
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

int	ft_get_gradient_color(t_data *data, int step, int min_step, int max_step, unsigned int color_1, unsigned int color_2)
{
	double	ratio;
	int	r;
	int	g;
	int	b;
	unsigned int color;

	if (max_step == min_step)
		return (color_1);
	ratio = (double)(step - min_step) / (max_step - min_step);
	r = (int)(((color_1 >> 16) & 0xFF) + ratio * (((color_2 >> 16) & 0xFF) - ((color_1 >> 16) & 0xFF)));
	g = (int)(((color_1 >> 8) & 0xFF) + ratio * (((color_2 >> 8) & 0xFF) - ((color_1 >> 8) & 0xFF)));
	b = (int)((color_1 & 0xFF) + ratio * ((color_2 & 0xFF) - (color_1 & 0xFF)));
	color = ft_rgb_to_color(data, r, g, b);
	return (color);
}

void	ft_draw_line(t_data *data, t_line line)
{
	t_bresenham				bres;
	int						steps;
	int						step_count;
	unsigned int			color;

	steps = ft_abs(line.pixel_2.x - line.pixel_1.x) + ft_abs(line.pixel_2.y - line.pixel_1.y);
	step_count = 0;
	bres.dx = ft_abs(line.pixel_2.x - line.pixel_1.x);
	bres.dy = ft_abs(line.pixel_2.y - line.pixel_1.y);
	ft_set_bres_sx_sy(&bres, line);
	bres.err = bres.dx - bres.dy;
	while (!(line.pixel_1.x == line.pixel_2.x
			&& line.pixel_1.y == line.pixel_2.y))
	{
		color = ft_get_gradient_color(data, step_count, 0, steps, line.pixel_1.color, line.pixel_2.color);
		ft_mlx_pixel_put(data, line.pixel_1, color, MAP);
		step_count++;
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
	ft_mlx_pixel_put(data, line.pixel_1, line.pixel_2.color, MAP);
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
