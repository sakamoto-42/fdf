/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:14 by julien            #+#    #+#             */
/*   Updated: 2025/02/04 12:34:07 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_render_map(t_data *data)
{
	ft_init_image(data);
	ft_init_pixels(data);
	ft_draw_hud(data);
	ft_draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->window.win_ptr, data->image.img_ptr, 0, 0);
	ft_draw_infos_hud(data);
}
