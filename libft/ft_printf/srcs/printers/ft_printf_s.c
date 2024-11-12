/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:12:54 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:12:23 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printf_s(t_flags flags, t_res *res)
{
	t_char	c;

	c.i = 0;
	while (c.i < (int)ft_strlen(flags.str))
	{
		ft_putchar_fd_print(flags.str[c.i], 1, res);
		c.i++;
	}
}

void	ft_s_setup(t_flags flags, va_list args, t_res *res)
{
	flags.str = va_arg(args, char *);
	if (!flags.str)
	{
		flags.str = malloc(sizeof(char) * 7);
		ft_strlcpy(flags.str, "(null)", 7);
		ft_printf_s(flags, res);
		free(flags.str);
	}
	else
		ft_printf_s(flags, res);
}
