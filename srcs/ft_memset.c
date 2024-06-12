/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:53:44 by alejhern          #+#    #+#             */
/*   Updated: 2024/06/12 22:20:12 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *s, int c, int n)
{
	int				index;
	unsigned char	*util;

	util = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		util[index] = c;
		index++;
	}
}
