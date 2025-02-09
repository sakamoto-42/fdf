/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:15:28 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/09 16:43:50 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_valid_file(char *file)
{
	char	*extension;
	int		fd;
	char	*line;

	if (!file)
		return (ERROR_INVALID_FILE);
	extension = ft_strrchr(file, '.');
	if (!extension || extension == file)
		return (ERROR_INVALID_FILE);
	if (ft_strncmp(extension, ".fdf", 4) != 0)
		return (ERROR_INVALID_FILE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ERROR_CANNOT_OPEN_FILE);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), ERROR_EMPTY_FILE);
	free(line);
	return (SUCCESS);
}

static int	ft_set_map_cols_and_rows_number(t_data *data)
{
	int		fd;
	char	**cols;
	char	*current_row;

	fd = open(data->map.map_file, O_RDONLY);
	current_row = get_next_line(fd);
	cols = ft_split(current_row, ' ');
	if (!cols)
		return (free(current_row), ERROR_NOT_ENOUGH_MEMORY);
	data->map.cols = 0;
	while (cols[data->map.cols])
		data->map.cols++;
	ft_free_strs(cols);
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
	data->render.map_center_x = (data->map.cols - 1) / 2;
	data->render.map_center_y = (data->map.rows - 1) / 2;
	status_code = ft_allocate_points(data);
	status_code = ft_set_points(data);
	return (status_code);
}
