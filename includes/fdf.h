/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:43:40 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/07 10:54:47 by juduchar         ###   ########.fr       */
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
# define ANGLE_X_STEP 0.1
# define ANGLE_Y_STEP 0.1
# define ANGLE_Z_STEP 0.1
# define ZOOM_STEP 1

# define SUCCESS 0
# define ERROR_INVALID_NUMBER_OF_ARGUMENTS 1
# define ERROR_CANNOT_OPEN_FILE 2
# define ERROR_EMPTY_FILE 3
# define ERROR_NOT_ENOUGH_MEMORY 4
# define ERROR_MLX_INIT_FAILED 5
# define ERROR_MLX_WINDOW_INIT_FAILED 6
# define ERROR_MLX_IMG_INIT_FAILED 7
# define ERROR_MLX_GET_IMG_ADDRESS_FAILED 7

# define ORTHOGONAL_PROJECTION 0
# define ISOMETRIC_PROJECTION 1
# define CONIC_PROJECTION 2

# define HUD 0
# define MAP 1

# define HUD_TEXT_HEIGHT 20
# define HUD_TEXT_OFFSET_X 20

# define KEY_CLOSE 65307
# define KEY_ORTHOGONAL 49
# define KEY_ISOMETRIC 50
# define KEY_CONIC 51
# define KEY_CENTER 99
# define KEY_MIRROR 109
# define KEY_ZOOM_IN 61
# define KEY_ZOOM_OUT 45
# define KEY_DECREASE_X_ANGLE 113
# define KEY_INCREASE_X_ANGLE 101
# define KEY_DECREASE_Y_ANGLE 97
# define KEY_INCREASE_Y_ANGLE 100
# define KEY_DECREASE_Z_ANGLE 119
# define KEY_INCREASE_Z_ANGLE 115
# define KEY_DECREASE_SCALE_Z 91
# define KEY_INCREASE_SCALE_Z 93
# define KEY_MOVE_UP 65362
# define KEY_MOVE_DOWN 65364
# define KEY_MOVE_LEFT 65361
# define KEY_MOVE_RIGHT 65363

typedef struct s_window
{
	void	*win_ptr;
	char	*title;
	int		size_x;
	int		size_y;
	int		hud_height;
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

typedef struct s_line
{
	t_pixel	pixel_1;
	t_pixel	pixel_2;
}		t_line;

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
	double	angle_x;
	double	angle_y;
	double	angle_z;
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

typedef struct s_text_hud
{
	char	*text;
	int		offset_x;
	int		offset_y;
	int		color;
}		t_text_hud;

typedef struct s_panel_hud
{
	int			texts_count;
	t_text_hud	*texts;
	int			size_x;
	int			size_y;
	int			offset_x;
	int			offset_y;
	int			color;
}		t_panel_hud;

typedef struct s_data
{
	void			*mlx_ptr;
	t_window		window;
	t_image			image;
	t_pixel			**pixels;
	int				hud_height;
	t_panel_hud		header_panel;
	t_panel_hud		left_panel_1;
	t_panel_hud		left_panel_2;
	t_panel_hud		right_panel;
	t_map			map;
	t_render		render;
}		t_data;

char		*ft_strerror(int errnum);
int			ft_init(t_data *data);
void		ft_init_default_settings(t_data *data);
int			ft_init_map(t_data *data);
int			ft_init_window(t_data *data);
int			ft_init_image(t_data *data);
int			ft_rgb_to_color(int r, int g, int b);
void		ft_mlx_pixel_put(t_data *data, t_pixel pixel, int color, int mode);
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
int			ft_render_map(t_data *data);
void		ft_render_isometric_projection(t_point point,
				t_pixel *pixel, t_render render);
void		ft_center_map(t_data *data);
void		ft_free_hud_panels(t_data *data);
void		ft_destroy_and_free_all(t_data *data);
void		ft_draw_map(t_data *data);
void		ft_draw_line(t_data *data, t_line line);
void		ft_apply_scale_to_pixel(t_point point, t_pixel *pixel, int scale);
void		ft_apply_offset_to_pixel(t_pixel *pixel, t_render render);
void		ft_apply_angle_x_to_pixel(t_pixel *pixel, t_render render);
void		ft_apply_angle_y_to_pixel(t_pixel *pixel, t_render render);
void		ft_apply_angle_z_to_pixel(t_pixel *pixel, t_render render);
void		ft_apply_scale_z_to_pixel(t_point point,
				t_pixel *pixel, int scale_z);
int			ft_update_image(t_data *data);
int			ft_handle_close(t_data *data);
int			ft_handle_keys(int keycode, t_data *data);
void		ft_handle_keys_translation(t_data *data, int keycode);
void		ft_handle_keys_isometric_projection(t_data *data, int keycode);
void		ft_handle_keys_change_projection(t_data *data, int keycode);
void		ft_handle_keys_common(t_data *data, int keycode);
int			ft_init_hud(t_data *data);
int			ft_allocate_panel_texts(t_panel_hud *panel);
void		ft_set_panel_texts_offset_x(t_panel_hud *panel, int offset_x, int start);
void		ft_set_panel_texts_offset_y(t_panel_hud *panel, int start);
void		ft_set_panel_texts_color(t_panel_hud *panel, int color, int start);
int			ft_init_header_panel(t_data *data, t_panel_hud *header_panel);
void		ft_set_header_panel_display(t_data *data,
				t_panel_hud *header_panel);
void		ft_set_header_panel_texts(t_data *data, t_panel_hud *header_panel);
void		ft_set_header_panel_dynamic_texts(t_data *data, t_panel_hud *header_panel);
int			ft_init_left_panel_1(t_data *data, t_panel_hud *left_panel_1);
void		ft_set_left_panel_1_display(t_data *data,
				t_panel_hud *left_panel_1);
void		ft_set_left_panel_1_texts(t_panel_hud *left_panel_1);
void		ft_set_left_panel_1_dynamic_texts(t_data *data, t_panel_hud *left_panel_1);
int			ft_init_left_panel_2(t_data *data, t_panel_hud *left_panel_2);
void		ft_set_left_panel_2_display(t_data *data,
				t_panel_hud *left_panel_2);
void		ft_set_left_panel_2_texts(t_panel_hud *left_panel_2);

int			ft_init_right_panel(t_data *data, t_panel_hud *right_panel);
void		ft_set_right_panel_display(t_data *data, t_panel_hud *right_panel);
void		ft_set_right_panel_texts(t_panel_hud *right_panel);
void		ft_set_right_panel_dynamic_texts(t_data *data, t_panel_hud *right_panel);

void		ft_draw_hud(t_data *data);
void		ft_draw_panel_hud(t_data *data, t_panel_hud panel_hud);
void		ft_write_hud_infos(t_data *data);
void		ft_write_infos(t_data *data, t_panel_hud *panel);

#endif
