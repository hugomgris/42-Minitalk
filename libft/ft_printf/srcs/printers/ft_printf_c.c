/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:01:15 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:10:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printf_c(t_char c, t_res *res)
{
	ft_putchar_fd_print(c.c, 1, res);
}

void	ft_c_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	c;

	c.i = 0;
	if (flags.param == '%')
	{
		ft_putchar_fd_print('%', 1, res);
		return ;
	}
	c.c = va_arg(args, int);
	ft_printf_c(c, res);
}
