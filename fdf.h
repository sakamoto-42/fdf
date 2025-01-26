/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:39:39 by julien            #+#    #+#             */
/*   Updated: 2025/01/24 14:50:16 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
