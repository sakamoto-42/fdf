/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array2D.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:08 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/27 13:40:19 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// free a 2D array of ints
void	ft_free_array2D(int **array2D)
{
	size_t	i;

	i = 0;
	while (array2D[i])
	{
		free(array2D[i]);
		i++;
	}
	free(array2D);
}