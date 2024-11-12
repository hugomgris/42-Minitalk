/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_functions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:03:08 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 14:14:36 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// applies the filters if flags.number is equal to 0.
// takes into account flags.dot flag too.

void	ft_s_number_is_zero(t_flags flags, t_res *res, char *dot)
{
	t_char	c;

	c.i = 0;
	if (flags.dot == 1)
	{
		if (flags.dot_num == 0)
		{
			return ;
		}
		while (c.i < (int)ft_strlen(dot))
		{
			ft_putchar_fd_print(dot[c.i], 1, res);
			c.i++;
		}
	}
	if (flags.dot == 0)
	{
		while (c.i < (int)ft_strlen(flags.str))
		{
			ft_putchar_fd_print(flags.str[c.i], 1, res);
			c.i++;
		}
	}
}

// (flags.number != 0 && flags.dot == 0 && flags.zemin == 0)

void	ft_s_num_flags_0(t_flags flags, t_res *res)
{
	t_char	s;

	s.i = -1;
	s.j = -1;
	if (flags.number > (int)ft_strlen(flags.str))
	{
		while (s.i++ < flags.number - ((int)ft_strlen(flags.str) + 1))
			ft_putchar_fd_print(' ', 1, res);
		while (s.i + s.j++ < (flags.number - 1))
			ft_putchar_fd_print(flags.str[s.j], 1, res);
	}
	else if (flags.number <= (int)ft_strlen(flags.str))
	{
		while (s.i++ < ((int)ft_strlen(flags.str) - 1))
			ft_putchar_fd_print(flags.str[s.i], 1, res);
	}
}

// (flags.number != 0 && flags.dot == 0 && flags.zemin == 1)

void	ft_s_num_dot_0_min_1(t_flags flags, t_res *res, char *dot)
{
	t_char	s;

	s.i = 0;
	s.j = 0;
	if (flags.number > (int)ft_strlen(flags.str))
	{
		while (s.i < (int)ft_strlen(flags.str))
		{
			ft_putchar_fd_print(flags.str[s.i], 1, res);
			s.i++;
		}
		while (s.i + s.j < flags.number)
		{
			ft_putchar_fd_print(' ', 1, res);
			s.j++;
		}
	}
	else if (flags.number <= (int)ft_strlen(flags.str))
		ft_s_number_is_zero(flags, res, dot);
}

// (flags.number != 0 && flags.dot == 1 && flags.zemin == 0)

void	ft_s_num_dot_1_min_0(t_flags flags, t_res *res, char *dot)
{
	t_char	s;

	s.i = 0;
	if (flags.number > (int)ft_strlen(dot))
	{
		while (s.i < flags.number - (int)ft_strlen(dot))
		{
			ft_putchar_fd_print(' ', 1, res);
			s.i++;
		}
		ft_s_number_is_zero(flags, res, dot);
	}
	else if (flags.zemin == 0 && flags.number <= (int)ft_strlen(dot))
		ft_s_number_is_zero(flags, res, dot);
}

// (flags.number != 0 && flags.dot == 1 && flags.zemin == 1)

void	ft_s_num_dot_1_min_1(t_flags flags, t_res *res, char *dot)
{
	t_char	s;

	s.i = 0;
	if (flags.number > (int)ft_strlen(dot))
	{
		ft_s_number_is_zero(flags, res, dot);
		while (s.i < flags.number - (int)ft_strlen(dot))
		{
			ft_putchar_fd_print(' ', 1, res);
			s.i++;
		}
	}
	else if (flags.number <= (int)ft_strlen(dot))
		ft_s_number_is_zero(flags, res, dot);
}
