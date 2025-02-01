/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:36:48 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/30 15:14:33 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_bres_sx_sy(t_bresenham *bres, t_pixel pix1, t_pixel pix2)
{
	if (pix1.x < pix2.x)
		bres->sx = 1;
	else
		bres->sx = -1;
	if (pix1.y < pix2.y)
		bres->sy = 1;
	else
		bres->sy = -1;
}

void	ft_draw_line(t_data *data, t_pixel pix1, t_pixel pix2)
{
	t_bresenham	bres;

	bres.dx = ft_abs(pix2.x - pix1.x);
	bres.dy = ft_abs(pix2.y - pix1.y);
	ft_set_bres_sx_sy(&bres, pix1, pix2);
	bres.err = bres.dx - bres.dy;
	while (!(pix1.x == pix2.x && pix1.y == pix2.y))
	{
		ft_mlx_pixel_put(data, pix1.x, pix1.y, pix1.color);
		bres.e2 = bres.err * 2;
		if (bres.e2 > -bres.dy)
		{
			bres.err -= bres.dy;
			pix1.x += bres.sx;
		}
		if (bres.e2 < bres.dx)
		{
			bres.err += bres.dx;
			pix1.y += bres.sy;
		}
	}
	ft_mlx_pixel_put(data, pix1.x, pix1.y, pix1.color);
}

void	ft_draw_map(t_data *data)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		col_count = 0;
		while (col_count < data->map.cols)
		{
			if (col_count < data->map.cols - 1)
				ft_draw_line(data, data->pixels[row_count][col_count],
					data->pixels[row_count][col_count + 1]);
			if (row_count < data->map.rows - 1)
				ft_draw_line(data, data->pixels[row_count][col_count],
					data->pixels[row_count + 1][col_count]);
			col_count++;
		}
		row_count++;
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->window.win_ptr, data->image.img_ptr, 0, 0);
}
