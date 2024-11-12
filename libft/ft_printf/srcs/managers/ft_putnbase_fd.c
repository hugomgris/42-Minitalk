/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbase_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:07:16 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 11:14:02 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/* putnbr in chosen base but choose on which file descriptor it is printed */

void	ft_putnbase_cap_fd(unsigned long int n, int base, int fd, t_res *res)
{
	if (base < 2)
		return (ft_putstr_fd("Error, base too low", 1));
	if (n <= 0)
	{
		ft_putchar_fd_print('-', fd, res);
		n *= -1;
	}
	if (n >= (unsigned long int)base)
		ft_putnbase_cap_fd(n / base, base, fd, res);
	if ((n % base) <= 9)
		ft_putchar_fd_print(n % base + 48, fd, res);
	else if (n % base >= 10)
		ft_putchar_fd_print(n % base + 55, fd, res);
}

void	ft_putnbase_low_fd(unsigned long int n, int base, int fd, t_res *res)
{
	if (base < 2)
		return (ft_putstr_fd("Error, base too low", 1));
	if (n <= 0)
	{
		ft_putchar_fd_print('-', fd, res);
		n *= -1;
	}
	if (n >= (unsigned long int)base)
		ft_putnbase_low_fd(n / base, base, fd, res);
	if ((n % base) <= 9)
		ft_putchar_fd_print(n % base + 48, fd, res);
	else if (n % base >= 10)
		ft_putchar_fd_print(n % base + 87, fd, res);
}

void	ft_putnbr_fd_print_u(unsigned int n, int fd, t_res *res)
{
	if (n >= 10)
		ft_putnbr_fd_print_u(n / 10, fd, res);
	ft_putchar_fd_print(n % 10 + 48, fd, res);
}

void	ft_putnbr_fd_print(int n, int fd, t_res *res)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		res->n++;
	}
	nb = n;
	if (nb >= 10)
		ft_putnbr_fd_print(nb / 10, fd, res);
	ft_putchar_fd_print(nb % 10 + 48, fd, res);
}
