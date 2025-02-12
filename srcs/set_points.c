/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:51:53 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/12 17:28:56 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_strtoui(char *str)
{
	unsigned int	result;
	unsigned int	digit;

	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f'))
	{
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'A' && *str <= 'F')
			digit = *str - 'A' + 10;
		else
			digit = *str - 'a' + 10;
		result = (result * 16) + digit;
		str++;
	}
	return (result);
}

static void	ft_set_pixel_color(t_data *data, char *col_str, t_pixel *pixel)
{
	char	*color_str;

	if (data->render.base_color == 0)
	{
		color_str = ft_strchr(col_str, ',');
		if (color_str && *(color_str + 1))
		{
			pixel->color = (unsigned int)ft_strtoui(color_str + 1);
			data->render.base_color--;
		}
	}
	else
		data->render.base_color = 0;
}

static void	ft_set_points_datas(t_data *data, char **cols,
	int row_count, int *col_count)
{
	data->pixels[row_count][*col_count].x = *col_count;
	data->pixels[row_count][*col_count].y = row_count;
	data->pixels[row_count][*col_count].z = ft_atoi(cols[*col_count]) / 5;
	ft_set_pixel_color(data, cols[*col_count],
		&data->pixels[row_count][*col_count]);
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
