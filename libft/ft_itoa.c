/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:30:58 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:30:59 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

static	int	ft_count_digits_in_number(int n)
{
	int		count;
	long	nlong;

	count = 0;
	nlong = (long)n;
	if (nlong < 0)
	{
		nlong = nlong * -1;
		count++;
	}
	if (nlong == 0)
		count++;
	while (nlong > 0)
	{
		nlong = nlong / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		n_length;
	char	*str;
	long	nlong;

	n_length = ft_count_digits_in_number(n);
	str = (char *)malloc(sizeof(char) * (n_length + 1));
	if (!str)
		return (NULL);
	nlong = (long)n;
	str[n_length] = '\0';
	if (nlong < 0)
	{
		str[0] = '-';
		nlong = nlong * -1;
	}
	else if (n == 0)
		str[n_length - 1] = '0';
	while (nlong > 0)
	{
		str[n_length - 1] = (nlong % 10) + 48;
		nlong = nlong / 10;
		n_length--;
	}
	return (str);
}
