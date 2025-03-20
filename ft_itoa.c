/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:27:55 by alejhern          #+#    #+#             */
/*   Updated: 2024/06/26 13:47:14 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	long	nb_long;
	size_t	digits;
	char	*str;

	nb_long = nb;
	digits = ft_nblen(nb_long);
	str = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb_long < 0)
		nb_long *= -1;
	while (digits--)
	{
		str[digits] = nb_long % 10 + '0';
		nb_long /= 10;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}
