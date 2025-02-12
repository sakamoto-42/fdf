/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:51:53 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/12 14:39:23 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_points_datas(t_data *data, char **cols,
	int row_count, int *col_count)
{
	data->pixels[row_count][*col_count].x = *col_count;
	data->pixels[row_count][*col_count].y = row_count;
	data->pixels[row_count][*col_count].z = ft_atoi(cols[*col_count]) / 5;
	(*col_count)++;
}

static int	ft_get_points_from_file(t_data *data, int fd, char *current_row)
{
	int		row_count;
	int		col_count;
	char	**cols;

	row_count = 0;
	while (row_count < data->map.rows)
	{
		cols = ft_split(current_row, ' ');
		if (!cols)
			return (free(current_row), ERROR_NOT_ENOUGH_MEMORY);
		col_count = 0;
		while (col_count < data->map.cols)
			ft_set_points_datas(data, cols, row_count, &col_count);
		ft_free_strs(cols);
		free(current_row);
		current_row = get_next_line(fd);
		row_count++;
	}
	return (SUCCESS);
}

int	ft_set_points(t_data *data)
{
	int		fd;
	char	*current_row;
	int		status_code;

	fd = open(data->map.map_file, O_RDONLY);
	if (fd == -1)
		return (ERROR_CANNOT_OPEN_FILE);
	current_row = get_next_line(fd);
	if (!current_row)
		return (close(fd), ERROR_EMPTY_FILE);
	status_code = ft_get_points_from_file(data, fd, current_row);
	if (status_code != SUCCESS)
		return (status_code);
	return (close(fd), SUCCESS);
}
