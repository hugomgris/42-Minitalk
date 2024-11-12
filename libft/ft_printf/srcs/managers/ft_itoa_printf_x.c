/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:56:16 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 11:05:31 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/* converts an int to its char representation */

static int	ft_n_size_x(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_itoa_printf_x(unsigned int n, t_char d, t_flags flags)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * (ft_n_size_x(n) + 1));
	if (!str)
		return (NULL);
	d.j = ft_n_size_x(n);
	str[d.j] = '\0';
	d.j--;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		if ((n % 16) < 10)
			str[d.j] = (n % 16) + 48;
		else if ((n % 16) >= 10 && flags.param == 'x')
			str[d.j] = (n % 16) + 87;
		else if ((n % 16) >= 10 && flags.param == 'X')
			str[d.j] = (n % 16) + 55;
		n /= 16;
		d.j--;
	}
	return (str);
}

static int	ft_n_size_p(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_itoa_printf_p(unsigned long int n, t_char d, t_flags flags)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * (ft_n_size_p(n) + 1));
	if (!str)
		return (NULL);
	d.j = ft_n_size_p(n);
	str[d.j] = '\0';
	d.j--;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		if ((n % 16) < 10)
			str[d.j] = (n % 16) + 48;
		else if ((n % 16) >= 10 && flags.param == 'p')
			str[d.j] = (n % 16) + 87;
		n /= 16;
		d.j--;
	}
	return (str);
}
