/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 01:54:09 by amhernandez       #+#    #+#             */
/*   Updated: 2025/01/15 02:26:51 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *dest, const char *to_append)
{
	size_t	dest_len;
	size_t	to_append_len;
	char	*new_str;

	if (!dest && !to_append)
		return (NULL);
	if (!dest && to_append)
		return (ft_strdup(to_append));
	if (!to_append)
		return (dest);
	dest_len = ft_strlen(dest);
	to_append_len = ft_strlen(to_append);
	new_str = (char *)malloc((dest_len + to_append_len + 1) * sizeof(char));
	if (!new_str)
	{
		free(dest);
		return (NULL);
	}
	ft_strlcpy(new_str, dest, dest_len + 1);
	ft_strlcat(new_str, to_append, dest_len + to_append_len + 1);
	new_str[dest_len + to_append_len] = '\0';
	free(dest);
	return (new_str);
}
