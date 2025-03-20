/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhernandez <alejhern@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:24:00 by amhernandez       #+#    #+#             */
/*   Updated: 2025/03/20 01:44:10 by amhernandez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define DBL_EPSILON 2.2204460492503131e-16

void	ft_printf_float(double num, t_flags flags, int *len)
{
	double	decimal_part;
	int		precision;
	double	epsilon;
	int		digit;

	if (ft_putnbr_fd((int)num, 1) != -1)
		*len += ft_nblen((int)num);
	else
		*len = -1;
	ft_printf_char('.', init_flags(0), len);
	decimal_part = num - (int)num;
	if (decimal_part < 0)
		decimal_part = -decimal_part;
	precision = 0;
	epsilon = DBL_EPSILON;
	while (decimal_part > epsilon && (flags.dot == -1 || precision < flags.dot))
	{
		decimal_part *= 10;
		digit = (int)decimal_part;
		ft_printf_char(digit + '0', init_flags(0), len);
		decimal_part -= digit;
		precision++;
		epsilon *= 10;
	}
}
