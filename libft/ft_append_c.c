/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:58 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/11 16:12:46 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_c(char *start, char c)
{
	size_t	i;
	char	*aux;

	aux = (char *)malloc(sizeof(start) + 2);
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (start[i])
	{
		aux[i] = start[i];
		i++;
	}
	aux[i] = c;
	aux[i] = '\0';
	free(start);
	return (aux);
}
