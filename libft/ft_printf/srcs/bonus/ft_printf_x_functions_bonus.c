/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_functions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:39:43 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 14:41:34 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_x_001(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (flags.dot == 1)
		ft_padding(0, d.i, (flags.dot_num - d.len), res);
	if ((unsigned int)d.lui != 0
		&& flags.square == 1 && flags.param == 'x')
		ft_putstr_fd_print("0x", 1, 2, res);
	if ((unsigned int)d.lui != 0
		&& flags.square == 1 && flags.param == 'X')
		ft_putstr_fd_print("0X", 1, 2, res);
	ft_printf_x(flags, d, res);
}

void	ft_x_100_1m10(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (flags.zemin != -1)
	{
		if (flags.number == 1)
			flags.number -= 2;
		ft_padding(1, d.i, (flags.number - d.len), res);
	}
	else if (flags.zemin == -1)
	{
		flags.number = ft_square(flags, d, flags.number, res);
		ft_padding(0, d.i, (flags.number - d.len), res);
	}
	if (flags.zemin != -1)
		ft_square(flags, d, flags.number, res);
	ft_printf_x(flags, d, res);
}

void	ft_x_110(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	flags.number -= d.len;
	if (d.lui != 0 && flags.square == 1)
		flags.number = ft_square(flags, d, flags.number, res);
	ft_printf_x(flags, d, res);
	ft_padding(1, d.i, flags.number, res);
}

void	ft_x_111(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (flags.dot_num > d.len)
	{
		if (flags.square == 1)
			flags.number = ft_square(flags, d, flags.number, res);
		ft_padding(0, d.i, (flags.dot_num - d.len), res);
		flags.number -= flags.dot_num;
	}
	else if (flags.dot_num <= d.len)
	{
		if (flags.square == 1)
			flags.number = ft_square(flags, d, flags.number, res);
		flags.number -= d.len;
	}
	ft_printf_x(flags, d, res);
	ft_padding(1, d.i, flags.number, res);
}

void	ft_x_101(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (d.lui != 0 && flags.square == 1)
		flags.number -= 2;
	if (flags.dot_num > d.len)
		ft_padding(1, d.i, (flags.number - flags.dot_num), res);
	else if (flags.dot_num <= d.len)
		ft_padding(1, d.i, (flags.number - d.len), res);
	ft_square(flags, d, flags.number, res);
	ft_padding(0, d.i, (flags.dot_num - d.len), res);
	ft_printf_x(flags, d, res);
}
