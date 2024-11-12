/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pustr_fd_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:15:46 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 11:16:41 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/* putstr with a given file descriptor */

void	ft_putstr_fd_print(char *s, int fd, size_t len, t_res *res)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd_print(*s, fd, res);
		i++;
		s++;
	}
}
