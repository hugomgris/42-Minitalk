/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:42:29 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/23 17:46:34 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/* checks if a given string matches the char -> libprntf.h */

int	ft_check_char(char c)
{
	t_char	i;

	i.i = 0;
	while (CHARS[i.i])
	{
		if (CHARS[i.i] == c)
		{
			return (0);
		}
		i.i++;
	}
	return (-1);
}

/* checks if a given string matches the flags -> libprntf.h */

int	ft_check_flag(char c)
{
	t_char	j;

	j.i = 0;
	while (FLAGS[j.i])
	{
		if (FLAGS[j.i] == c)
		{
			return (0);
		}
		j.i++;
	}
	return (-1);
}

/* checks if a given string matches numbers from 1-9 -> libprntf.h */

int	ft_check_number(char c)
{
	t_char	j;

	j.i = 0;
	while (NUMBERS[j.i])
	{
		if (NUMBERS[j.i] == c)
		{
			return (0);
		}
		j.i++;
	}
	return (-1);
}

// checks if a given string matches all diff flags and numbers -> libprntf.h

int	ft_check_all(char c)
{
	t_char	j;

	j.i = 0;
	while (ALL[j.i])
	{
		if (ALL[j.i] == c)
		{
			return (0);
		}
		j.i++;
	}
	return (-1);
}
