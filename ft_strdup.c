/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:41:28 by alejhern          #+#    #+#             */
/*   Updated: 2024/06/19 22:37:13 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*dup;

	if (!str)
		return (NULL);
	size = ft_strlen(str) + 1;
	dup = (char *)ft_calloc(size, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, size);
	return (dup);
}

char	*ft_safe_strdup(const char *str)
{
	char	*dup;

	if (!str)
		return (NULL);
	dup = ft_strdup(str);
	if (!dup)
		ft_perror_exit("can't allocate memory");
	return (dup);
}
