/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:45:29 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/27 15:19:26 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->window.win_ptr);
		exit(0);
	}
	return (0);
}

void	ft_print_map(t_data data)
{
	int	row_count;
	int	col_count;
	int	offset_x;
	int	offset_y;

	data.pixel.x = 0;
	data.pixel.y = 0;
	offset_x = data.window.size_x / data.map.cols;
	offset_y = data.window.size_y / data.map.rows;
	row_count = 0;
	while (row_count <= data.map.rows)
	{
		col_count = 0;
		while (col_count <= data.map.cols)
		{
			data.pixel.color = (unsigned int)(mlx_get_color_value(data.mlx_ptr,
						rgb_to_color(0, 255, 0)));
			my_mlx_pixel_put(&data);
			data.pixel.x = col_count * offset_x;
			col_count++;
		}
		data.pixel.y = row_count * offset_y;
		row_count++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status_code;

	if (argc - 1 == -1)
		return (perror("Error : invalid number of arguments"), 1);
	data.map.map_file = argv[1];
	status_code = ft_init_map(&data);
	if (status_code == ERROR_OPEN_FILE)
		return (perror("Error : could not open map file"), 1);
	if (status_code == ERROR_EMPTY_FILE)
		return (perror("Error : empty map file"), 1);
	if (status_code == ERROR_NOT_ENOUGH_MEMORY)
		return (perror("Error : not enough memory"), 1);
	ft_print_raw_map(data);
	data.mlx_ptr = mlx_init();
	init_window(&data);
	init_image(&data);
	ft_print_map(data);
	mlx_put_image_to_window(data.mlx_ptr,
		data.window.win_ptr, data.image.img_ptr, 0, 0);
	mlx_key_hook(data.window.win_ptr, deal_key, (void *)&data);
	mlx_loop(data.mlx_ptr);
}
