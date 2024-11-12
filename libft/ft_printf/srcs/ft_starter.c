/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:56:56 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/23 18:00:51 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* redirects to the proper function according to the char given */

void	ft_starter(t_flags flags, va_list args, t_res *res)
{
	if (flags.param == 'c' || flags.param == '%')
		ft_c_setup(flags, args, res);
	else if (flags.param == 's')
		ft_s_setup(flags, args, res);
	else if (flags.param == 'x' || flags.param == 'X')
		ft_x_setup(flags, args, res);
	else if (flags.param == 'u')
		ft_u_setup(flags, args, res);
	else if (flags.param == 'p')
		ft_p_setup(flags, args, res);
	else if (flags.param == 'd' || flags.param == 'i')
		ft_di_setup(flags, args, res);
}
