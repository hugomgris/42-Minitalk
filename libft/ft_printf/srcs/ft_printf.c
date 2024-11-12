/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:03:39 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/23 17:09:40 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// receives the args and sends it to the hub

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_res	res;

	res.n = 0;
	va_start (args, str);
	ft_parse_str(str, args, &res);
	va_end (args);
	return (res.n);
}
