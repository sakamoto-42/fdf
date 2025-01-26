/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:56:37 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/05 09:22:21 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for a digit (0 through 9)
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}