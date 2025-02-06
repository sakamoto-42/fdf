/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:45:29 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/06 11:31:14 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_handle_close(t_data *data)
{
	ft_destroy_and_free_all(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status_code;

	if (argc - 1 != 1)
		return (ft_putstr_fd(
				ft_strerror(ERROR_INVALID_NUMBER_OF_ARGUMENTS), 2), 1);
	data.map.map_file = argv[1];
	status_code = ft_init_map(&data);
	if (status_code != SUCCESS)
		return (ft_destroy_and_free_all(&data),
			perror(ft_strerror(status_code)), 1);
	status_code = ft_allocate_pixels(&data);
	if (status_code != SUCCESS)
		return (ft_destroy_and_free_all(&data),
			perror(ft_strerror(status_code)), 1);
	status_code = ft_init(&data);
	if (status_code != SUCCESS)
		return (ft_destroy_and_free_all(&data),
			perror(ft_strerror(status_code)), 1);
	mlx_key_hook(data.window.win_ptr, ft_handle_keys, &data);
	mlx_hook(data.window.win_ptr, DestroyNotify,
		StructureNotifyMask, ft_handle_close, &data);
	mlx_loop(data.mlx_ptr);
}

// TODO ERROR MSG
// # define ERROR_MLX_INIT_FAILED 5
// # define ERROR_WINDOW_INIT_FAILED 6
