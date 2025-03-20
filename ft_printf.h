/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:17:35 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/16 21:35:25 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		bl_mayus;
	char	*prefix;
}	t_flags;

t_flags	init_flags(int bl_mayus);
t_flags	parse_flags(const char **str);
void	ft_printf_pad(char pad_char, int pad_len, int *len);
void	ft_printf_nbr_flags(int nb, t_flags flags, int total_len, int *len);
void	ft_printf_char(char c, t_flags flags, int *len);	
void	ft_printf_str(char *str, t_flags flags, int *len);
void	ft_printf_nbr(int nb, char *str, t_flags flags, int *len);
void	ft_printf_nbr_hex(unsigned int nb, char *str, t_flags flags, int *len);
void	ft_printf_float(double num, t_flags flags, int *len);
void	ft_printf_ptr(void *ptr, t_flags flags, int *len);

#endif
