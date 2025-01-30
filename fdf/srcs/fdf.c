/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:45:29 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/30 12:15:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	ft_init_image(data);
	mlx_clear_window(data->mlx_ptr, data->window.win_ptr);
	ft_init_pixels(data);
	ft_draw_lines_between_pixels(data);
}

int	ft_deal_key(int keycode, t_data *data)
{
	ft_printf("%d", keycode);
	if (keycode == 65307)
	{
		ft_printf("ECHAP");
		ft_handle_close(data);
	}
	if (keycode == 111 && data->render.projection != ORTHOGONAL_PROJECTION)
	{
		ft_printf("o");
		data->render.projection = ORTHOGONAL_PROJECTION;
		ft_update_image(data);
	}
	if (keycode == 105 && data->render.projection != ISOMETRIC_PROJECTION)
	{
		ft_printf("i");
		data->render.projection = ISOMETRIC_PROJECTION;
		ft_update_image(data);
	}
	if (keycode == 109)
	{
		ft_printf("m");
		data->render.scale = -data->render.scale;
		ft_update_image(data);
	}
	if (keycode == 91 && data->render.projection == ISOMETRIC_PROJECTION)
	{
		ft_printf("[");
		data->render.render_isometric.angle -= 0.1;
		ft_update_image(data);
	}
	if (keycode == 93 && data->render.projection == ISOMETRIC_PROJECTION)
	{
		ft_printf("]");
		data->render.render_isometric.angle += 0.1;
		ft_update_image(data);
	}
	if (keycode == 57 && data->render.projection == ISOMETRIC_PROJECTION)
	{
		ft_printf("(");
		data->render.render_isometric.scale_z -= 0.1;
		ft_update_image(data);
	}
	if (keycode == 48 && data->render.projection == ISOMETRIC_PROJECTION)
	{
		ft_printf(")");
		data->render.render_isometric.scale_z += 1;
		ft_update_image(data);
	}
	if (keycode == 61)
	{
		ft_printf("+");
		data->render.scale += 1;
		ft_update_image(data);
	}
	if (keycode == 45)
	{
		ft_printf("-");
		data->render.scale -= 1;
		ft_update_image(data);
	}
	if (keycode == 65362)
	{
		ft_printf("UP");
	}
	if (keycode == 65364)
	{
		ft_printf("DOWN");
	}
	if (keycode == 65361)
	{
		ft_printf("LEFT");
	}
	if (keycode == 65363)
	{
		ft_printf("RIGHT");
	}
	return (0);
}

void	ft_free_all(t_data *data)
{
	if (data->image.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	if (data->window.win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->window.win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map.points)
		ft_free_points(data);
	if (data->pixels)
		ft_free_pixels(data);
}

int	ft_handle_close(t_data *data)
{
	ft_free_all(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status_code;

	if (argc - 1 != 1)
		return (ft_putstr_fd(ft_strerror(INVALID_NUMBER_OF_ARGUMENTS), 2), 1);
	data.map.map_file = argv[1];
	status_code = ft_init_map(&data);
	if (status_code != SUCCESS)
		return (perror(ft_strerror(status_code)), 1);
	status_code = ft_allocate_pixels(&data);
	if (status_code != SUCCESS)
		return (perror(ft_strerror(status_code)), 1);
	ft_print_raw_map(data);
	ft_init(&data);
	mlx_key_hook(data.window.win_ptr, ft_deal_key, &data);
	mlx_hook(data.window.win_ptr, DestroyNotify,
		StructureNotifyMask, ft_handle_close, &data);
	mlx_loop(data.mlx_ptr);
}
