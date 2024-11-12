/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:27:11 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:11:52 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printf_x(t_flags flags, t_char d, t_res *res)
{
	int	i;

	i = 0;
	if (flags.dot == 1 && d.lui == 0)
		return ;
	while (flags.str[i] != '\0')
	{
		ft_putchar_fd_print(flags.str[i], 1, res);
		i++;
	}
}

// initiates the variables for the following functions

void	ft_x_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	d;

	d.lui = va_arg(args, unsigned long int);
	flags.str = ft_itoa_printf_x(d.lui, d, flags);
	d.len = (int)ft_strlen(flags.str);
	ft_printf_x(flags, d, res);
	free (flags.str);
}
