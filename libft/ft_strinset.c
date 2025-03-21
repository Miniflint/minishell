/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:32:27 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:32:27 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strinset(char *str, char *set)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (set[i] && set[i] != *str)
			i++;
		if (!set[i])
			return (1);
		str++;
	}
	return (0);
}
