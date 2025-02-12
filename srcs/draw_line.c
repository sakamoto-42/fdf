/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:01:42 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/12 15:05:45 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_data *data, t_line line)
{
	t_bresenham				bres;
	t_gradient				gradient;
	int						steps;
	int						step_count;
	unsigned int			color;

	steps = ft_abs(line.pixel_2.x - line.pixel_1.x)
		+ ft_abs(line.pixel_2.y - line.pixel_1.y);
	step_count = 0;
	bres.dx = ft_abs(line.pixel_2.x - line.pixel_1.x);
	bres.dy = ft_abs(line.pixel_2.y - line.pixel_1.y);
	ft_set_bres_sx_sy(&bres, line);
	bres.err = bres.dx - bres.dy;
	while (!(line.pixel_1.x == line.pixel_2.x
			&& line.pixel_1.y == line.pixel_2.y))
	{
		ft_set_gradient_values(&gradient, step_count, steps, line);
		color = ft_get_gradient_color(gradient);
		ft_mlx_pixel_put(data, line.pixel_1, color, MAP);
		step_count++;
		bres.e2 = bres.err * 2;
		ft_update_bres(&bres, &line.pixel_1);
	}
	ft_mlx_pixel_put(data, line.pixel_1, line.pixel_2.color, MAP);
}

void	ft_draw_horizontal_line(t_data *data,
			t_line *line, int row_count, int col_count)
{
	if (col_count < data->map.cols - 1)
	{
		line->pixel_2 = data->pixels[row_count][col_count + 1];
		ft_draw_line(data, *line);
	}
}

void	ft_draw_vertical_line(t_data *data,
			t_line *line, int row_count, int col_count)
{
	if (row_count < data->map.rows - 1)
	{
		line->pixel_2 = data->pixels[row_count + 1][col_count];
		ft_draw_line(data, *line);
	}
}

int	ft_line_is_in_screen(t_data *data, t_pixel *pixel_1, t_pixel *pixel_2)
{
	if ((pixel_1->x < 0 && pixel_2->x < 0)
		|| (pixel_1->x >= data->window.size_x
			&& pixel_2->x >= data->window.size_x)
		|| (pixel_1->y < 0 && pixel_2->y < 0)
		|| (pixel_1->y >= data->window.size_y
			&& pixel_2->y >= data->window.size_y))
		return (0);
	return (1);
}
