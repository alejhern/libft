/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:32:19 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/16 22:06:35 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(const char *str, int fd)
{
	if (!str)
		return (-2);
	while (*str)
	{
		if (!ft_putchar_fd(*str, fd))
			return (0);
		str++;
	}
	return (1);
}
