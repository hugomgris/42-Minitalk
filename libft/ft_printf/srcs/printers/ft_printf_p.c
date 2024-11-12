/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:20:47 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:11:21 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printf_p_extra(t_flags flags, t_res *res)
{
	int	i;

	i = 0;
	while (flags.str[i])
	{
		ft_putchar_fd_print(flags.str[i], 1, res);
		i++;
	}
}

void	ft_printf_p(t_flags flags, t_res *res)
{
	ft_putstr_fd_print("0x", 1, 2, res);
	ft_printf_p_extra(flags, res);
}

void	ft_p_setup(t_flags flags, va_list args, t_res *res)
{
	t_char	d;

	d.lui = va_arg(args, unsigned long int);
	if (d.lui == 0)
	{
		flags.str = malloc(sizeof(char) * 6);
		ft_strlcpy(flags.str, "(nil)", 6);
		ft_printf_s(flags, res);
		free(flags.str);
	}
	else
	{
		flags.str = ft_itoa_printf_p(d.lui, d, flags);
		d.len = (int)ft_strlen(flags.str);
		ft_printf_p(flags, res);
		free (flags.str);
	}
}
