/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:20:17 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/12 14:33:04 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_get_gradient_color(t_gradient gradient)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	if (gradient.max_value == gradient.min_value)
		return (gradient.lower_color);
	ratio = (double)(gradient.value - gradient.min_value)
		/ (gradient.max_value - gradient.min_value);
	r = (gradient.lower_color >> 16) & 0xFF;
	g = (gradient.lower_color >> 8) & 0xFF;
	b = gradient.lower_color & 0xFF;
	r = (float)r + ratio * ((float)((gradient.higher_color >> 16) & 0xFF)
			- (float)r);
	g = (float)g + ratio * ((float)((gradient.higher_color >> 8) & 0xFF)
			- (float)g);
	b = (float)b + ratio * ((float)(gradient.higher_color & 0xFF)
			- (float)b);
	return (ft_rgb_to_color(r, g, b));
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
