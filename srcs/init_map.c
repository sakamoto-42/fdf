/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:15:28 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/11 15:56:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_set_map_cols_and_rows_number(t_data *data, int fd)
{
	char	**cols;
	char	*current_row;

	current_row = get_next_line(fd);
	if (!current_row)
		return (close(fd), ERROR_EMPTY_FILE);
	cols = ft_split(current_row, ' ');
	if (!cols)
		return (free(current_row), close(fd), ERROR_NOT_ENOUGH_MEMORY);
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

static int	ft_check_valid_file(const char *file, int *fd)
{
	char	*extension;

	if (!file)
		return (ERROR_INVALID_FILE);
	extension = ft_strrchr(file, '.');
	if (!extension || extension == file)
		return (ERROR_INVALID_FILE);
	if (ft_strlen(extension) != 4 || ft_strncmp(extension, ".fdf", 4) != 0)
		return (ERROR_INVALID_FILE);
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (ERROR_CANNOT_OPEN_FILE);
	return (SUCCESS);
}

int	ft_parse_map(t_data *data)
{
	int	fd;
	int	status_code;

	status_code = ft_check_valid_file(data->map.map_file, &fd);
	if (status_code != SUCCESS)
		return (status_code);
	status_code = ft_set_map_cols_and_rows_number(data, fd);
	if (status_code != SUCCESS)
		return (status_code);
	return (SUCCESS);
}

int	ft_init_map(t_data *data)
{
	int	status_code;

	status_code = ft_parse_map(data);
	if (status_code != SUCCESS)
		return (status_code);
	data->render.map_center_x = (data->map.cols - 1) / 2;
	data->render.map_center_y = (data->map.rows - 1) / 2;
	status_code = ft_allocate_pixels(data);
	status_code = ft_set_points(data);
	return (status_code);
}
