/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:11:09 by julien            #+#    #+#             */
/*   Updated: 2025/02/04 09:43:01 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_image(t_data *data)
{
	if (data->image.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	ft_init_image(data);
	ft_init_pixels(data);
	ft_draw_map(data);
}
