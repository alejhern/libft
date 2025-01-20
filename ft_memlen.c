/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:43:10 by amhernandez       #+#    #+#             */
/*   Updated: 2025/01/17 21:44:00 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memlen(const void *ptr)
{
	size_t		len;
	const void	**arr;

	len = 0;
	arr = (const void **)ptr;
	while (arr[len])
		len++;
	return (len);
}
