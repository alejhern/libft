/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:45:34 by amhernandez       #+#    #+#             */
/*   Updated: 2025/01/26 22:07:36 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pos	ft_pos_add(t_pos a, t_pos b)
{
	return ((t_pos){a.x + b.x, a.y + b.y});
}

t_pos	ft_pos_sub(t_pos a, t_pos b)
{
	return ((t_pos){a.x - b.x, a.y - b.y});
}

int	ft_pos_cmp(t_pos a, t_pos b)
{
	return (a.x == b.x && a.y == b.y);
}

int	ft_pos_distance(t_pos a, t_pos b)
{
	return (abs(a.x - b.x) + abs(a.y - b.y));
}
