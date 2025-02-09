/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:36:11 by juduchar          #+#    #+#             */
/*   Updated: 2025/02/09 14:02:11 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strerror(int errnum)
{
	if (errnum == ERROR_INVALID_NUMBER_OF_ARGUMENTS)
		return ("Error : invalid number of arguments\n");
	else if (errnum == ERROR_CANNOT_OPEN_FILE)
		return ("Error : could not open map file");
	else if (errnum == ERROR_EMPTY_FILE)
		return ("Error : empty map file");
	else if (errnum == ERROR_INVALID_FILE)
		return ("Error : invalid file");
	else if (errnum == ERROR_NOT_ENOUGH_MEMORY)
		return ("Error : not enough memory");
	else if (errnum == ERROR_MLX_INIT_FAILED)
		return ("Error : mlx initialization failed");
	else if (errnum == ERROR_MLX_WINDOW_INIT_FAILED)
		return ("Error : mlx window initialization failed");
	else if (errnum == ERROR_MLX_IMG_INIT_FAILED)
		return ("Error : mlx image initialization failed");
	else if (errnum == ERROR_MLX_GET_IMG_ADDRESS_FAILED)
		return ("Error : mlx get image address failed");
	return (NULL);
}
