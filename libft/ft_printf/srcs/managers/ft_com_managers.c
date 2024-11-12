/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_managers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:31:59 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 10:46:51 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// function to add padding according to precision or width

void	ft_padding(int s, int start, int stop, t_res *res)
{
	if (start >= stop)
		return ;
	if (s == 1)
	{
		while (start < stop)
		{
			ft_putchar_fd_print(' ', 1, res);
			start++;
		}
	}
	if (s == 0)
	{
		while (start < stop)
		{
			ft_putchar_fd_print('0', 1, res);
			start++;
		}
	}
}

// function to deal with the plus and space flags

int	ft_spaplus(t_flags flags, t_char d, int i, t_res *res)
{
	if (d.ui > 0 || d.ct > 0)
	{
		if (flags.spaplus == -1)
		{
			ft_putchar_fd_print(' ', 1, res);
			return (i - 1);
		}
		else if (flags.spaplus == 1)
		{
			ft_putchar_fd_print('+', 1, res);
			return (i - 1);
		}
	}
	return (i);
}

// function to deal with square flag

int	ft_square(t_flags flags, t_char d, int i, t_res *res)
{
	if (d.lui != 0 && flags.square == 1)
	{
		if (flags.param == 'x')
		{
			ft_putstr_fd_print("0x", 1, 2, res);
			return (i - 2);
		}
		else if (flags.param == 'X')
		{
			ft_putstr_fd_print("0X", 1, 2, res);
			return (i - 2);
		}
	}
	return (i);
}
