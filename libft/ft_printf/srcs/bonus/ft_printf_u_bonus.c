/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:07:09 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 15:07:21 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// simple basic printing function for types i and d

void	ft_printf_u(t_flags flags, t_char d, t_res *res)
{
	int	i;

	i = 0;
	if (flags.dot == 1 && d.ui == 0)
		return ;
	while (flags.str[i] != '\0')
	{
		ft_putchar_fd_print(flags.str[i], 1, res);
		i++;
	}
}

void	ft_u_starter(t_flags flags, t_char d, t_res *res)
{
	if ((flags.number == 0 && flags.zemin == 0 && flags.dot == 0)
		|| (flags.number == 0 && flags.zemin != 0 && flags.dot == 0))
		ft_u_001(flags, d, res);
	else if ((flags.number == 0 && flags.zemin == 0 && flags.dot == 1)
		|| (flags.number != 0 && flags.zemin == 1
			&& flags.dot == 1 && flags.dot_num > flags.number))
		ft_u_001(flags, d, res);
	else if (flags.number == 0 && flags.zemin == -1 && flags.dot == 1)
		ft_u_001(flags, d, res);
	else if ((flags.number != 0 && flags.zemin == 0 && flags.dot == 0)
		|| (flags.number != 0 && flags.zemin == -1 && flags.dot == 0))
		ft_u_100_1m10(flags, d, res);
	else if (flags.number == 0 && flags.zemin == 1 && flags.dot == 1)
		ft_u_111(flags, d, res);
	else if (flags.number != 0 && flags.zemin == 1 && flags.dot == 0)
		ft_u_110(flags, d, res);
	else if (flags.number != 0 && flags.zemin == 1 && flags.dot == 1)
		ft_u_111(flags, d, res);
	else if (flags.number != 0 && flags.zemin != 1 && flags.dot == 1)
		ft_u_101(flags, d, res);
}

// initiates the variables for the following functions

void	ft_u_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	d;

	d.ui = va_arg(args, unsigned int);
	flags.str = ft_itoa_printf_u(d.ui);
	if (d.ui == 0 && flags.dot == 1)
		d.len = 0;
	else
		d.len = (int)ft_strlen(flags.str);
	ft_u_starter(flags, d, res);
	free (flags.str);
}
