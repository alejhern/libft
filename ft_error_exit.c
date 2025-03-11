/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:00:53 by amhernandez       #+#    #+#             */
/*   Updated: 2025/03/11 10:02:55 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_exit(const char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_func_error_exit(const char *msg, void **param, void *(f)(void *))
{
	f(*param);
	ft_error_exit(msg);
}

void	ft_perror_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
