FDF_NAME = fdf
LIBFT = libft.a
FT_PRINTF = libftprintf.a
MLX = libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -lX11 -lXext
MATH_FLAG = -lm

FDF_HEADER_DIR = includes
FDF_SRCS_DIR = srcs
FDF_OBJS_DIR = objs

LIBFT_DIR = ./libft
LIBFT_HEADER_DIR = $(LIBFT_DIR)/includes
LIBFT_SRCS_DIR = ./srcs

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_HEADER_DIR = $(FT_PRINTF_DIR)/includes
FT_PRINTF_SRCS_DIR = ./srcs

MLX_DIR = ./minilibx
MLX_HEADER_DIR = $(MLX_DIR)
MLX_SRCS_DIR = ./srcs

FDF_INCLUDES = -I$(FDF_HEADER_DIR) -I$(LIBFT_HEADER_DIR) -I$(FT_PRINTF_HEADER_DIR) -I$(MLX_HEADER_DIR)
FDF_LIBRARIES = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) $(MLX_FLAGS) $(MATH_FLAG)

FDF_SRCS_FILES = \
		allocate_and_free_pixels.c \
		allocate_and_free_points.c \
		apply_angles_to_pixels.c \
		apply_params_to_pixels.c \
		destroy_and_free.c \
		draw_hud.c \
		draw_map.c \
		error_msg.c \
		fdf.c \
		gradient.c \
		handle_keys_utils.c \
		handle_keys.c \
		init_color_sets.c \
		init_header_panel_hud.c \
		init_hud.c \
		init_left_panel_1_hud.c \
		init_left_panel_2_hud.c \
		init_map.c \
		init_right_panel_1_hud.c \
		init_right_panel_2_hud.c \
		init.c \
		mlx_init.c \
		mlx_utils.c \
		render_map_utils.c \
		render_map.c \
		set_pixels.c \
		set_points.c \
		set_right_panel_1_datas.c \
		set_right_panel_2_datas.c \
		set_right_panel_2_datas_2.c \
		update_image.c \
		utils.c \
		write_infos_hud.c \

FDF_OBJS = $(addprefix $(FDF_OBJS_DIR)/, $(FDF_SRCS_FILES:.c=.o))

all: $(LIBFT) $(FT_PRINTF) $(MLX) $(FDF_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(FDF_NAME): $(FDF_OBJS)
	$(CC) $(CFLAGS) $(FDF_INCLUDES) $(FDF_OBJS) $(FDF_LIBRARIES) -o $(FDF_NAME)

$(FDF_OBJS_DIR)/%.o: $(FDF_SRCS_DIR)/%.c
	@mkdir -p $(FDF_OBJS_DIR)
	$(CC) $(CFLAGS) $(FDF_INCLUDES) -c $< -o $@

clean:
	rm -f $(FDF_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(FDF_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
