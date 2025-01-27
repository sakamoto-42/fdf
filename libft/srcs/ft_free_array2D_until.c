/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array2D_until.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:02:38 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/27 14:05:19 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// free a 2D array of ints until n (not included)
int	**ft_free_array2D_until(int **array2D, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(array2D[i]);
		i++;
	}
	free(array2D);
	return (NULL);
}