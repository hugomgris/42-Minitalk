/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:10:01 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/23 17:58:32 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/* assigns values to struct i according to flags */

void	ft_flag_manager(va_list args, t_flags flags, t_res *res)
{
	while (ft_check_char(*flags.substr) != 0)
	{
		if (*flags.substr == '.')
		{
			flags.dot = 1;
			if (ft_isdigit(*(flags.substr + 1)) == 1)
			{
				ft_numbers_in_flags(&flags);
				while (ft_isdigit(*(flags.substr + 1)) == 1)
					flags.substr++;
			}
		}
		else if (ft_isdigit(*flags.substr) == 1 && *flags.substr != '0')
		{
			ft_numbers_in_flags(&flags);
			while (ft_isdigit(*(flags.substr + 1)) == 1)
				flags.substr++;
		}
		else
			ft_flags_conditions(&flags);
		flags.substr++;
	}
	flags.param = *flags.substr;
	ft_starter(flags, args, res);
}

// initiates the structure to store flags values

void	ft_struct_init(char *str, va_list args, t_res *res)
{
	t_flags	flags;

	flags.substr = str;
	flags.dot = 0;
	flags.number = 0;
	flags.zemin = 0;
	flags.spaplus = 0;
	flags.param = 0;
	flags.square = 0;
	flags.dot_num = 0;
	ft_flag_manager(args, flags, res);
}

/* copies flags to a new string in order to manage them through fction */

void	ft_get_flags(const char *c, int len, va_list args, t_res *res)
{
	t_char	l;

	l.i = 0;
	if (len > 0)
		l.str = (char *)malloc(sizeof(char) * (len + 1));
	else if (len == 0)
		l.str = (char *)malloc(sizeof(char) * 2);
	if (!l.str)
		return ;
	while (l.i <= len)
	{
		l.str[l.i] = c[l.i];
		l.i++;
	}
	l.str[l.i] = '\0';
	ft_struct_init(l.str, args, res);
	free(l.str);
}

/* goes through the string and sends flags bits to management fction */

void	ft_parse_str(const char *c, va_list args, t_res *res)
{
	t_char	n;

	while (*c != '\0')
	{
		n.ct = 0;
		if (*c == '%')
		{
			c++;
			while (ft_check_all(*c) == 0 && ft_check_char(*c) != 0)
			{
				n.ct++;
				c++;
			}
			ft_get_flags((c - n.ct), (n.ct), args, res);
		}
		else
		{
			ft_putchar_fd_print(*c, 1, res);
		}
		c++;
	}
}
