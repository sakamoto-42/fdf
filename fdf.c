/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:39:34 by julien            #+#    #+#             */
/*   Updated: 2025/01/24 17:11:31 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compile with gcc -Wall -Wextra -Werror fdf.c -L./minilibx -lmlx -lXext -lX11

#include "minilibx/mlx.h"
#include "fdf.h"
#include "libft/includes/libft.h"
#include <fcntl.h>

// FOR DEBUG ONLY
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

int	rgb_to_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_pixel_put(t_data *data)
{
	char			*dst;

	dst = data->image.data_addr
		+ (data->pixel.y * data->image.line_length
			+ data->pixel.x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = data->pixel.color;
}

void	init_window(t_data *data)
{
	data->window.size_x = 800;
	data->window.size_y = 600;
	data->window.title = "fdf";
	data->window.win_ptr = mlx_new_window(data->mlx_ptr, data->window.size_x,
			data->window.size_y, data->window.title);

}

void	init_image(t_data *data)
{
	data->image.img_ptr = mlx_new_image(data->mlx_ptr,
			data->window.size_x, data->window.size_y);
	data->image.data_addr = mlx_get_data_addr(data->image.img_ptr,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*map;
	int		fd;
	char	*str;
	//char	**strs;
	char	**s;

	if (argc - 1 != 1)
		return (1);
	map = argv[1];
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	int	x;
	s = ft_split(str, ' ');
	x = 0;
	while (s[x])
		x++;
	//free(s);
	int y = 0;
	while (str)
	{
		y++;
		str = get_next_line(fd);
	}
	close(fd);
	//printf("x : %d\n", x);
	//printf("y : %d", y);
	//strs = (char **)calloc((y + 1), sizeof(char *));
	//strs[y + 1] = NULL;

	int i = 0;
	int j = 0;
	int	**mapd;
	mapd = (int **)calloc((y), sizeof(int *));
	while (i < x)
	{
		mapd[i] = (int *)calloc((x), sizeof(int));
		i++;
	}
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (i < y)
	{
		s = ft_split(str, ' ');
		j = 0;
		while (j < x)
		{
			mapd[i][j] = atoi(s[j]);
			j++;
		}
		str = get_next_line(fd);
		i++;
	}
	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("%d", mapd[i][j]);
			if (mapd[i][j] >= 10 || mapd[i][j] < 0)
				printf("  ");
			else
				printf("   ");
			j++;
		}
		printf("\n");
		i++;
	}

	data.mlx_ptr = mlx_init();
	init_window(&data);
	init_image(&data);

	data.pixel.x = 0;
	data.pixel.y = 0;
	int offset_x = data.window.size_x / x;

	int m;
	int	l;

	int offset_y = data.window.size_y / y;
	l = 0;
	while (l <= y)
	{
		m = 0;
		while (m <= x)
		{
			data.pixel.color = (unsigned int)(mlx_get_color_value(data.mlx_ptr,
						rgb_to_color(0, 255, 0)));
			my_mlx_pixel_put(&data);
			data.pixel.x = m * offset_x;
			m++;
		}
		data.pixel.y = l * offset_y;
		l++;
	}
	//printf("%d", m);
	mlx_put_image_to_window(data.mlx_ptr,
		data.window.win_ptr, data.image.img_ptr, 0, 0);
	mlx_key_hook(data.window.win_ptr, deal_key, (void *)&data);
	//mlx_loop(data.mlx_ptr);
}
