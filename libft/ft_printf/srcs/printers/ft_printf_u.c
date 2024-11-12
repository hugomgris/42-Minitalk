/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:25:02 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:11:40 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// simple basic printing function for types i and d

void	ft_printf_u(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	while (flags.str[d.i] != '\0')
	{
		ft_putchar_fd_print(flags.str[d.i], 1, res);
		d.i++;
	}
}

// initiates the variables for the following functions

void	ft_u_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	d;

	d.ui = va_arg(args, int);
	flags.str = ft_itoa_printf_u(d.ui);
	d.len = (int)ft_strlen(flags.str);
	ft_printf_u(flags, d, res);
	free (flags.str);
}
