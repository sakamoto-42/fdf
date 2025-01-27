/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:43:40 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/27 15:21:31 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

// FOR DEBUG ONLY
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define SUCCESS 0
# define ERROR_OPEN_FILE 1
# define ERROR_EMPTY_FILE 2
# define ERROR_NOT_ENOUGH_MEMORY 3

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

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
}		t_point;

typedef struct s_map
{
	char		*map_file;
	int			rows;
	int			cols;
	t_point		**points;
}		t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	t_window	window;
	t_image		image;
	t_pixel		pixel;
	t_map		map;
}		t_data;

int		ft_init_map(t_data *data);
int		ft_allocate_points(t_data *data);
t_point	**ft_free_points_until(t_point **points, size_t n);
int		ft_set_points(t_data *data);
// DEBUG ONLY
void	ft_print_raw_map(t_data data);
//
void	init_window(t_data *data);
void	init_image(t_data *data);
int		deal_key(int keycode, void *param);
void	ft_print_map(t_data data);
int		rgb_to_color(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data);
void	init_window(t_data *data);
void	init_image(t_data *data);

#endif