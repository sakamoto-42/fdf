/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:11:09 by julien            #+#    #+#             */
/*   Updated: 2025/02/12 14:19:14 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_update_image(t_data *data)
{
	int	status_code;

	if (data->need_redraw > 0)
	{
		if (data->image.img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
		ft_set_points(data);
		status_code = ft_render_map(data);
		if (status_code != SUCCESS)
			return (status_code);
		data->need_redraw--;
	}
	return (SUCCESS);
}
