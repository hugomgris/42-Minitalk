/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_functions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:56:46 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 14:02:42 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_p_001(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (flags.spaplus != 0 && d.ui > 0)
		ft_spaplus(flags, d, flags.dot_num, res);
	ft_putstr_fd_print("0x", 1, 2, res);
	ft_printf_p(flags, res);
}

void	ft_p_100_1m10(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (flags.spaplus != 0 && d.ui > 0)
		flags.number--;
	if (flags.zemin != -1)
	{
		flags.number -= 2;
		ft_padding(1, d.i, (flags.number - d.len), res);
		if (flags.spaplus != 0 && d.ui > 0)
			flags.number = ft_spaplus(flags, d, d.i, res);
	}
	else if (flags.zemin == -1)
	{
		ft_putstr_fd_print("0x", 1, 2, res);
		flags.number -= 2;
		if (flags.spaplus != 0 && d.ui > 0)
			flags.number = ft_spaplus(flags, d, d.i, res);
		ft_padding(0, d.i, (flags.number - d.len), res);
	}
	if (flags.zemin != -1)
		ft_putstr_fd_print("0x", 1, 2, res);
	ft_printf_p(flags, res);
}

void	ft_p_110(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	flags.number -= d.len;
	if (d.lui != 0 && flags.spaplus == 1)
		flags.number = ft_spaplus(flags, d, flags.number, res);
	ft_putstr_fd_print("0x", 1, 2, res);
	flags.number -= 2;
	ft_printf_x(flags, d, res);
	ft_padding(1, d.i, flags.number, res);
}
