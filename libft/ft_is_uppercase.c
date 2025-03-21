/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_uppercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:30:09 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:30:40 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_is_uppercase(char *str)
{
	printf("dans ft_is_uppercase\n");
	if (!str)
		return (0);
	while (*str)
	{
		if (*str <= 'A' || *str >= 'Z')
			return (0);
		++str;
	}
	return (1);
}
