/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:45:29 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/04 16:43:14 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		status_code;

	if (argc - 1 != 1)
		return (ft_putstr_fd(ft_strerror(INVALID_NUMBER_OF_ARGUMENTS), 2), 1);
	data.map.map_file = argv[1];
	status_code = ft_init_map(&data);
	if (status_code != SUCCESS)
		return (perror(ft_strerror(status_code)), 1);
	status_code = ft_allocate_pixels(&data);
	if (status_code != SUCCESS)
		return (perror(ft_strerror(status_code)), 1);
	ft_init(&data);
	mlx_key_hook(data.window.win_ptr, ft_handle_keys, &data);
	mlx_hook(data.window.win_ptr, DestroyNotify,
		StructureNotifyMask, ft_handle_close, &data);
	mlx_loop(data.mlx_ptr);
}