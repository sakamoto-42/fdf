/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image_utils_isometric.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:26:07 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/04 15:35:28 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_angle_x(t_data *data, double angle_x)
{
	data->render.render_isometric.angle_x = angle_x;
	ft_update_image(data);
}

void	ft_update_angle_y(t_data *data, double angle_y)
{
	data->render.render_isometric.angle_y = angle_y;
	ft_update_image(data);
}

void	ft_update_angle_z(t_data *data, double angle_z)
{
	data->render.render_isometric.angle_z = angle_z;
	ft_update_image(data);
}

void	ft_update_scale_z(t_data *data, int scale_z)
{
	data->render.render_isometric.scale_z = scale_z;
	ft_update_image(data);
}