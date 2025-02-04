/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:55:45 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/27 15:20:57 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_raw_map(t_data data)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	while (row_count < data.map.rows)
	{
		col_count = 0;
		while (col_count < data.map.cols)
		{
			ft_printf("%d", data.map.points[row_count][col_count].z);
			if (data.map.points[row_count][col_count].z >= 10
				|| data.map.points[row_count][col_count].z < 0)
				ft_printf(" ");
			else
				ft_printf("  ");
			col_count++;
		}
		ft_printf("\n");
		row_count++;
	}
}
