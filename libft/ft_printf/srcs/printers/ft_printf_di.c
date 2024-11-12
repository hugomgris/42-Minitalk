/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:16:32 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:12:04 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printf_di(t_flags flags, t_char d, t_res *res)
{
	d.i = 0;
	if (d.ct < 0)
		ft_putchar_fd_print('-', 1, res);
	while (flags.str[d.i] != '\0')
	{
		ft_putchar_fd_print(flags.str[d.i], 1, res);
		d.i++;
	}
}

void	ft_di_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	d;

	d.ct = va_arg(args, int);
	flags.str = ft_itoa_printf(d.ct);
	d.len = (int)ft_strlen(flags.str);
	ft_printf_di(flags, d, res);
	free (flags.str);
}
