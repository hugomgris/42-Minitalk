/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_functions_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:56:23 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 13:56:15 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_di_001(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (d.ct < 0)
		ft_putchar_fd_print('-', 1, res);
	if (flags.spaplus != 0 && d.ct >= 0)
		ft_spaplus(flags, d, flags.dot_num, res);
	if (flags.dot == 1)
		ft_padding(0, d.i, (flags.dot_num - d.len), res);
	ft_printf_di(flags, d, res);
}

void	ft_di_100_1m10(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (d.ct < 0)
		flags.number--;
	if (flags.spaplus != 0 && d.ct > 0)
		flags.number--;
	if (flags.zemin != -1)
	{
		ft_padding(1, d.i, (flags.number - d.len), res);
		if (d.ct < 0)
			ft_putchar_fd_print('-', 1, res);
		if (flags.spaplus != 0 && d.ct > 0)
			ft_spaplus(flags, d, d.i, res);
	}
	else if (flags.zemin == -1)
	{
		if (flags.spaplus != 0 && d.ct > 0)
			ft_spaplus(flags, d, d.i, res);
		if (d.ct < 0)
			ft_putchar_fd_print('-', 1, res);
		ft_padding(0, d.i, (flags.number - d.len), res);
	}
	ft_printf_di(flags, d, res);
}

void	ft_di_110(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (d.ct < 0)
	{
		ft_putchar_fd_print('-', 1, res);
		flags.number -= (d.len + 1);
	}
	else if (d.ct >= 0)
	{
		if (flags.spaplus != 0)
			flags.number = ft_spaplus(flags, d, flags.dot_num, res);
		flags.number -= d.len;
	}
	ft_printf_di(flags, d, res);
	ft_padding(1, d.i, flags.number, res);
}

void	ft_di_111(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (d.ct < 0)
	{
		ft_putchar_fd_print('-', 1, res);
		flags.number--;
	}
	else if (d.ct >= 0)
		flags.number = ft_spaplus(flags, d, flags.number, res);
	if (flags.dot_num > d.len)
	{
		ft_padding(0, d.i, (flags.dot_num - d.len), res);
		flags.number -= flags.dot_num;
	}
	else if (flags.dot_num <= d.len)
		flags.number -= d.len;
	ft_printf_di(flags, d, res);
	ft_padding(1, d.i, flags.number, res);
}

void	ft_di_101(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (d.ct < 0)
		flags.number--;
	else if (d.ct >= 0 && flags.spaplus != 0)
		flags.number--;
	if (flags.dot_num > d.len)
		ft_padding(1, d.i, (flags.number - flags.dot_num), res);
	else if (flags.dot_num <= d.len)
		ft_padding(1, d.i, (flags.number - d.len), res);
	if (d.ct < 0)
		ft_putchar_fd_print('-', 1, res);
	else if (d.ct >= 0)
		ft_spaplus(flags, d, d.j, res);
	ft_padding(0, d.i, (flags.dot_num - d.len), res);
	ft_printf_di(flags, d, res);
}
