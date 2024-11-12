/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:40:45 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:55:34 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printf_p(t_flags flags, t_res *res)
{
	int	i;

	i = 0;
	while (flags.str[i] != '\0')
	{
		ft_putchar_fd_print(flags.str[i], 1, res);
		i++;
	}
}

void	ft_p_starter(t_flags flags, t_char d, t_res *res)
{
	if ((flags.number == 0 && flags.zemin == 0 && flags.dot == 0)
		|| (flags.number == 0 && flags.zemin != 0 && flags.dot == 0))
		ft_p_001(flags, d, res);
	else if ((flags.number == 0 && flags.zemin == 0 && flags.dot == 1)
		|| (flags.number != 0 && flags.zemin == 1
			&& flags.dot == 1 && flags.dot_num > flags.number))
		ft_p_001(flags, d, res);
	else if (flags.number == 0 && flags.zemin == -1 && flags.dot == 1)
		ft_p_100_1m10(flags, d, res);
	else if ((flags.number != 0 && flags.zemin == 0 && flags.dot == 0)
		|| (flags.number != 0 && flags.zemin == -1 && flags.dot == 0))
		ft_p_100_1m10(flags, d, res);
	else if (flags.number == 0 && flags.zemin == 1 && flags.dot == 1)
		ft_p_110(flags, d, res);
	else if (flags.number != 0 && flags.zemin == 1 && flags.dot == 0)
		ft_p_110(flags, d, res);
	else if (flags.number != 0 && flags.zemin == 1 && flags.dot == 1)
		ft_p_110(flags, d, res);
	else if (flags.number != 0 && flags.zemin != 1 && flags.dot == 1)
		ft_p_100_1m10(flags, d, res);
}

// initiates the variables for the following functions

void	ft_p_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	d;

	d.lui = va_arg(args, unsigned long int);
	if (d.lui == 0)
	{
		flags.str = malloc(sizeof(char) * 6);
		ft_strlcpy(flags.str, "(nil)", 6);
		ft_s_starter(flags, res);
		free(flags.str);
	}
	else
	{
		flags.str = ft_itoa_printf_p(d.lui, d, flags);
		d.len = (int)ft_strlen(flags.str);
		ft_p_starter(flags, d, res);
		free (flags.str);
	}
}
