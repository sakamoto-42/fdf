/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:11:09 by julien            #+#    #+#             */
/*   Updated: 2025/01/30 15:36:56 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	ft_init_image(data);
	mlx_clear_window(data->mlx_ptr, data->window.win_ptr);
	ft_init_pixels(data);
	ft_draw_map(data);
}

void	ft_update_projection(t_data *data, int projection)
{
	data->render.projection = projection;
	ft_update_image(data);
}

void	ft_update_scale(t_data *data, int scale)
{
	data->render.scale = scale;
	ft_update_image(data);
}

void	ft_update_angle(t_data *data, double angle)
{
	data->render.render_isometric.angle = angle;
	ft_update_image(data);
}

void	ft_update_scale_z(t_data *data, int scale_z)
{
	data->render.render_isometric.scale_z = scale_z;
	ft_update_image(data);
}
