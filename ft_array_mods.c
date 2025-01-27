/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_mods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:59:58 by amhernandez       #+#    #+#             */
/*   Updated: 2025/01/27 15:19:22 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void ***array)
{
	void	**ptr;

	if (!array || !*array)
		return ;
	ptr = *array;
	while (*ptr)
		free(*ptr++);
	free(*array);
	*array = NULL;
}

void ft_rotate_array(void ***array)
{
    void *element;
    size_t len;

    len = ft_memlen(*array);
    if (!array || !(*array) || len < 2)
        return ;
    element = (*array)[0];
    ft_memmove(*array, *array + 1, sizeof(void *) * (len - 1));
    (*array)[len - 1] = element;
}

void	ft_rotate_rev_array(void ***array)
{
    void *element;
    size_t len;

    len = ft_memlen(*array);
    if (!array || !(*array) || len < 2)
        return ;
    element = (*array)[len - 1];
    ft_memmove(*array + 1, *array, sizeof(void *) * (len - 1));
    (*array)[0] = element;
}

void	ft_append_array(void ***array, void *new_element)
{
	size_t	len;
	void	**new_array;

    if (!array || !(*array) || !new_element)
        return ;
	len = ft_memlen(*array);
	new_array = ft_realloc(*array, (len + 1) * sizeof(void *));
	if (!new_array)
		return ;
	*array = new_array;
	(*array)[len] = new_element;
}
