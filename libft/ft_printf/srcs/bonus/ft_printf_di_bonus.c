/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:25:49 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:34:17 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// simple basic printing function for types i and d

void	ft_printf_di(t_flags flags, t_char d, t_res *res)
{
	int	i;

	i = 0;
	if (flags.dot == 1 && d.ct == 0)
		return ;
	while (flags.str[i] != '\0')
	{
		ft_putchar_fd_print(flags.str[i], 1, res);
		i++;
	}
}

// redirects to the proper printing channel depending on the flags

void	ft_di_starter(t_flags flags, t_char d, t_res *res)
{
	if ((flags.number == 0 && flags.zemin == 0 && flags.dot == 0)
		|| (flags.number == 0 && flags.zemin != 0 && flags.dot == 0))
		ft_di_001(flags, d, res);
	else if ((flags.number == 0 && flags.zemin == 0 && flags.dot == 1)
		|| (flags.number != 0 && flags.zemin == 1
			&& flags.dot == 1 && flags.dot_num > flags.number))
		ft_di_001(flags, d, res);
	else if (flags.number == 0 && flags.zemin == -1 && flags.dot == 1)
		ft_di_001(flags, d, res);
	else if ((flags.number != 0 && flags.zemin == 0 && flags.dot == 0)
		|| (flags.number != 0 && flags.zemin == -1 && flags.dot == 0))
		ft_di_100_1m10(flags, d, res);
	else if (flags.number == 0 && flags.zemin == 1 && flags.dot == 1)
		ft_di_111(flags, d, res);
	else if (flags.number != 0 && flags.zemin == 1 && flags.dot == 0)
		ft_di_110(flags, d, res);
	else if (flags.number != 0 && flags.zemin == 1 && flags.dot == 1)
		ft_di_111(flags, d, res);
	else if (flags.number != 0 && flags.zemin != 1 && flags.dot == 1)
		ft_di_101(flags, d, res);
}

// initiates the variables for the following functions

void	ft_di_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	d;

	d.ct = va_arg(args, int);
	flags.str = ft_itoa_printf(d.ct);
	if (d.ct == 0 && flags.dot == 1)
		d.len = 0;
	else
		d.len = (int)ft_strlen(flags.str);
	ft_di_starter(flags, d, res);
	free (flags.str);
}
