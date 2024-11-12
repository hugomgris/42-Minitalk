/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:05:26 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:24:56 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printf_c_bonus(t_flags flags, t_char c, t_res *res)
{
	c.i = 0;
	if (flags.number == 0)
		ft_putchar_fd_print(c.c, 1, res);
	else if (flags.number != 0 && flags.zemin != 1)
	{
		while (c.i++ < flags.number - 1)
			ft_putchar_fd_print(' ', 1, res);
		ft_putchar_fd_print(c.c, 1, res);
	}
	else if (flags.number != 0 && flags.zemin == 1)
	{
		ft_putchar_fd_print(c.c, 1, res);
		while (c.i++ < flags.number - 1)
			ft_putchar_fd_print(' ', 1, res);
	}
}

void	ft_c_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	c;

	if (flags.param == '%')
	{
		ft_putchar_fd_print('%', 1, res);
		return ;
	}
	c.c = va_arg(args, int);
	ft_printf_c_bonus(flags, c, res);
}
