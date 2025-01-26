/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:43:40 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/26 11:00:44 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
#include <fcntl.h>
# include <mlx.h>

// FOR DEBUG ONLY
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_window
{
	void	*win_ptr;
	char	*title;
	int		size_x;
	int		size_y;
}	t_window;

typedef struct s_image
{
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}		t_pixel;

typedef struct s_data
{
	void		*mlx_ptr;
	t_window	window;
	t_image		image;
	t_pixel		pixel;
}		t_data;

#endif