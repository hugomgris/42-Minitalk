/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:05:53 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 11:06:53 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/* function to write a char on the chosen file descriptor */

void	ft_putchar_fd_print(char c, int fd, t_res *res)
{
	write (fd, &c, 1);
	res->n++;
}
