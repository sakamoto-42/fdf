/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:36:11 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/28 13:48:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

const char	*ft_strerror(int errnum)
{
	if (errnum == ERROR_OPEN_FILE)
		return ("Error : could not open map file");
	if (errnum == ERROR_EMPTY_FILE)
		return ("Error : empty map file");
	if (errnum == ERROR_NOT_ENOUGH_MEMORY)
		return ("Error : not enough memory");
	return (NULL);
}
