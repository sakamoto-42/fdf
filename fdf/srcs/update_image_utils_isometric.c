/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image_utils_isometric.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:26:07 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/04 11:24:47 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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