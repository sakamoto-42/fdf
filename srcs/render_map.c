/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:14 by julien            #+#    #+#             */
/*   Updated: 2025/02/11 20:40:05 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_render_map(t_data *data)
{
	int	status_code;

	status_code = ft_init_image(data);
	if (status_code != SUCCESS)
		return (status_code);
	ft_points_to_pixels(data);
	ft_draw_hud(data);
	ft_draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->window.win_ptr, data->image.img_ptr, 0, 0);
	ft_write_hud_infos(data);
	return (SUCCESS);
}
