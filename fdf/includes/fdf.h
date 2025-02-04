/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:43:40 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/04 10:47:11 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <stdio.h>
# include <math.h>

# define TRANSLATION_STEP 20
# define SCALE_Z_STEP 1
# define ANGLE_STEP 0.1
# define ZOOM_STEP 1

# define SUCCESS 0
# define INVALID_NUMBER_OF_ARGUMENTS 1
# define ERROR_OPEN_FILE 2
# define ERROR_EMPTY_FILE 3
# define ERROR_NOT_ENOUGH_MEMORY 4
# define ORTHOGONAL_PROJECTION 5
# define ISOMETRIC_PROJECTION 6

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

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}		t_bresenham;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
}		t_point;

typedef struct s_isometric
{
	double	angle;
	int		scale_z;
	int		offset_z;

}		t_render_isometric;

typedef struct s_render
{
	int					projection;
	int					scale;
	int					offset_x;
	int					offset_y;
	t_render_isometric	render_isometric;
}		t_render;

typedef struct s_map
{
	char		*map_file;
	int			rows;
	int			cols;
	t_point		**points;
}		t_map;

typedef struct s_data
{
	void			*mlx_ptr;
	t_window		window;
	t_image			image;
	t_pixel			**pixels;
	t_map			map;
	t_render		render;
}		t_data;

char		*ft_strerror(int errnum);
void		ft_init(t_data *data);
void		ft_init_default_settings(t_data *data);
int			ft_init_map(t_data *data);
void		ft_init_window(t_data *data);
void		ft_init_image(t_data *data);
int			ft_rgb_to_color(int r, int g, int b);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_allocate_points(t_data *data);
t_point		**ft_free_points_until(t_point **points, size_t n);
t_pixel		**ft_free_points(t_data *data);
int			ft_allocate_pixels(t_data *data);
t_pixel		**ft_free_pixels_until(t_pixel **pixels, size_t n);
t_pixel		**ft_free_pixels(t_data *data);
int			ft_set_points(t_data *data);
void		ft_init_pixels(t_data *data);
void		ft_set_pixels_color(t_data *data, int color);
void		ft_points_to_pixels(t_data *data);
void		ft_render_map(t_data *data);
void		ft_render_isometric_projection(t_point point,
				t_pixel *pixel, t_render render);
void		ft_center_map(t_data *data);
void		ft_destroy_and_free_all(t_data *data);
void		ft_draw_map(t_data *data);
void		ft_draw_line(t_data *data, t_pixel pix1, t_pixel pix2);
void		ft_apply_scale_to_pixel(t_point point, t_pixel *pixel, int scale);
void		ft_apply_offset_to_pixel(t_pixel *pixel, t_render render);
void		ft_apply_angle_to_pixel(t_pixel *pixel, t_render render);
void		ft_apply_scale_z_to_pixel(t_point point,
				t_pixel *pixel, int scale_z);
void		ft_update_image(t_data *data);
void		ft_update_projection(t_data *data, int projection);
void		ft_update_scale(t_data *data, int scale);
void		ft_update_angle(t_data *data, double angle);
void		ft_update_scale_z(t_data *data, int scale_z);
void		ft_update_offset_x(t_data *data, int offset_x);
void		ft_update_offset_y(t_data *data, int offset_y);
int			ft_handle_close(t_data *data);
int			ft_handle_keys(int keycode, t_data *data);
void		ft_handle_translation(t_data *data, int keycode);

void		ft_print_raw_map(t_data data);

#endif
