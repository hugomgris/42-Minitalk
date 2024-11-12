/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:05 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 14:49:47 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// this function trims the argument to the proper size, according to
// precision's value. makes it easier to then print

char	*ft_s_trimmer(t_flags flags)
{
	char	*dotstr;

	if (!flags.str)
		return (NULL);
	dotstr = (char *)malloc(sizeof(char) * (flags.dot_num + 1));
	if (!dotstr)
		return (NULL);
	ft_strlcpy(dotstr, flags.str, (flags.dot_num + 1));
	return (dotstr);
}

// this function redirects to the proper printing function, depending
// on different cases

void	ft_s_starter(t_flags flags, t_res *res)
{
	char	*s;

	if (flags.dot == 1)
		s = ft_s_trimmer(flags);
	if (flags.number == 0)
		ft_s_number_is_zero(flags, res, s);
	else if (flags.number != 0 && flags.dot == 0 && flags.zemin == 0)
		ft_s_num_flags_0(flags, res);
	else if (flags.number != 0 && flags.dot == 0 && flags.zemin == 1)
		ft_s_num_dot_0_min_1(flags, res, s);
	else if (flags.number != 0 && flags.dot == 1 && flags.zemin == 0)
		ft_s_num_dot_1_min_0(flags, res, s);
	else if (flags.number != 0 && flags.dot == 1 && flags.zemin == 1)
		ft_s_num_dot_1_min_1(flags, res, s);
	if (flags.dot == 1)
		free(s);
}

void	ft_s_setup(t_flags flags, va_list args, t_res *res)
{
	flags.str = va_arg(args, char *);
	if (!flags.str && flags.dot && flags.dot_num <= 5
		&& !flags.zemin && !flags.spaplus && !flags.square)
		return ;
	else if (!flags.str)
	{
		flags.str = malloc(sizeof(char) * 7);
		ft_strlcpy(flags.str, "(null)", 7);
		ft_s_starter(flags, res);
		free (flags.str);
	}
	else
	{
		ft_s_starter(flags, res);
	}
}
