/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:20:17 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/08 22:25:29 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_get_gradient_color(t_data *data, t_gradient gradient)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	if (gradient.max_value == gradient.min_value)
		return (gradient.lower_color);
	ratio = (double)(gradient.value - gradient.min_value)
		/ (gradient.max_value - gradient.min_value);
	r = (int)(((gradient.lower_color >> 16) & 0xFF)
			+ ratio * (((gradient.higher_color >> 16) & 0xFF)
				- ((gradient.lower_color >> 16) & 0xFF)));
	g = (int)(((gradient.lower_color >> 8) & 0xFF)
			+ ratio * (((gradient.higher_color >> 8) & 0xFF)
				- ((gradient.lower_color >> 8) & 0xFF)));
	b = (int)((gradient.lower_color & 0xFF)
			+ ratio * ((gradient.higher_color & 0xFF)
				- (gradient.lower_color & 0xFF)));
	return (ft_rgb_to_color(data, r, g, b));
}

void	ft_set_gradient_values(t_gradient *gradient, int value,
			int max_value, t_line line)
{
	gradient->value = value;
	gradient->min_value = 0;
	gradient->max_value = max_value;
	gradient->lower_color = line.pixel_1.color;
	gradient->higher_color = line.pixel_2.color;
}
