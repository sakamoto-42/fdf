/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:25:10 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/04 15:34:31 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_projection(t_data *data, int projection)
{
	data->render.projection = projection;
	ft_update_image(data);
}

void	ft_center_map_and_update(t_data *data)
{
	ft_center_map(data);
	ft_update_image(data);
}

void	ft_update_scale(t_data *data, int scale)
{
	data->render.scale = scale;
	ft_update_image(data);
}

void	ft_update_offset_x(t_data *data, int offset_x)
{
	data->render.offset_x = offset_x;
	ft_update_image(data);
}

void	ft_update_offset_y(t_data *data, int offset_y)
{
	data->render.offset_y = offset_y;
	ft_update_image(data);
}