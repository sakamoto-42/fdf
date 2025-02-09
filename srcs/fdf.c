/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:05:12 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/09 16:19:22 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_handle_close(t_data *data)
{
	ft_destroy_and_free_all(data);
	exit(0);
	return (0);
}

int	handle_error(t_data *data, int status_code)
{
	if (status_code != SUCCESS)
	{
		ft_destroy_and_free_all(data);
		ft_putstr_fd(ft_strerror(status_code), 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status_code;

	if (argc - 1 != 1)
		return (ft_putstr_fd(
				ft_strerror(ERROR_INVALID_NUMBER_OF_ARGUMENTS), 2), 1);
	status_code = ft_check_valid_file(argv[1]);
	if (status_code != SUCCESS)
		return (ft_putstr_fd(ft_strerror(status_code), 2), 1);
	data.map.map_file = argv[1];
	status_code = ft_init_map(&data);
	if (handle_error(&data, status_code))
		return (1);
	status_code = ft_allocate_pixels(&data);
	if (handle_error(&data, status_code))
		return (1);
	status_code = ft_init(&data);
	if (handle_error(&data, status_code))
		return (1);
	mlx_hook(data.window.win_ptr, KeyPress, KeyPressMask,
		ft_handle_keypress, &data);
	mlx_hook(data.window.win_ptr, KeyRelease, KeyReleaseMask,
		ft_handle_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, ft_repeat_key_events, &data);
	mlx_loop(data.mlx_ptr);
}
