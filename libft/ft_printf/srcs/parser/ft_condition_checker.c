/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:47:17 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/23 17:54:48 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// spots the numbers in flags string and matches with width or precision

void	ft_numbers_in_flags(t_flags *flags)
{
	if (*(flags->substr) == '.')
	{
		flags->substr++;
		if (ft_isdigit(*(flags->substr)) == 1)
			flags->dot_num = ft_atoi(flags->substr);
		else if (ft_isdigit(*(flags->substr) == 0))
			flags->dot_num = 0;
	}
	else if (*(flags->substr) != '.')
	{
		if (ft_isdigit(*(flags->substr)) == 1)
			flags->number = ft_atoi(flags->substr);
	}
}

// assigns variables values according to flags

void	ft_flags_conditions(t_flags *flags)
{
	if (*(flags->substr) == '-')
		flags->zemin = 1;
	else if ((*(flags->substr) == '0' && ft_isdigit(*(flags->substr - 1))
			!= 1 && flags->zemin != 1)
		|| (flags->substr[0] == '0' && flags->zemin != 1))
		flags->zemin = -1;
	else if (*(flags->substr) == ' ' && flags->spaplus != 1)
		flags->spaplus = -1;
	else if (*(flags->substr) == '+')
		flags->spaplus = 1;
	else if (*(flags->substr) == '#')
		flags->square = 1;
}
