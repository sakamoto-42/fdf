/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:45:29 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 17:36:37 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_deal_key(int keycode, void *param)
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

int	main(int argc, char **argv)
{
	t_data	data;
	int		status_code;

	if (argc - 1 != 1)
		return (perror(ft_strerror(INVALID_NUMBER_OF_ARGUMENTS)), 1);
	data.map.map_file = argv[1];
	status_code = ft_init_map(&data);
	if (status_code != SUCCESS)
		return (perror(ft_strerror(status_code)), 1);
	status_code = ft_allocate_pixels(&data);
	if (status_code != SUCCESS)
		return (perror(ft_strerror(status_code)), 1);
	ft_print_raw_map(data);
	ft_init(&data);
	ft_draw_lines_between_pixels(&data);
	mlx_key_hook(data.window.win_ptr, ft_deal_key, (void *)&data);
	mlx_loop(data.mlx_ptr);
	ft_free_points(&data);
	ft_free_pixels(&data);
}
