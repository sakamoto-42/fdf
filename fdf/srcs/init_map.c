/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:15:28 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/27 15:19:33 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	ft_set_map_cols_and_rows_number(t_data *data)
{
	int		fd;
	char	**cols;
	char	*current_row;

	fd = open(data->map.map_file, O_RDONLY);
	if (fd == -1)
		return (ERROR_OPEN_FILE);
	current_row = get_next_line(fd);
	if (!current_row)
		return (close(fd), ERROR_EMPTY_FILE);
	cols = ft_split(current_row, ' ');
	if (!cols)
		return (free(current_row), ERROR_NOT_ENOUGH_MEMORY);
	data->map.cols = 0;
	while (cols[data->map.cols])
		data->map.cols++;
	free(cols);
	data->map.rows = 0;
	while (current_row)
	{
		data->map.rows++;
		free(current_row);
		current_row = get_next_line(fd);
	}
	return (close(fd), SUCCESS);
}

int	ft_init_map(t_data *data)
{
	int	status_code;

	status_code = ft_set_map_cols_and_rows_number(data);
	if (status_code != SUCCESS)
		return (status_code);
	status_code = ft_allocate_points(data);
	status_code = ft_set_points(data);
	return (status_code);
}
