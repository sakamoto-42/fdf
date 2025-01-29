/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:36:11 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/29 22:35:56 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strerror(int errnum)
{
	if (errnum == INVALID_NUMBER_OF_ARGUMENTS)
		return ("Error : invalid number of arguments\n");
	if (errnum == ERROR_OPEN_FILE)
		return ("Error : could not open map file");
	if (errnum == ERROR_EMPTY_FILE)
		return ("Error : empty map file");
	if (errnum == ERROR_NOT_ENOUGH_MEMORY)
		return ("Error : not enough memory");
	return (NULL);
}
