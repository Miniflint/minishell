/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:32:06 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:32:07 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t size)
{
	char	*mypointer;
	size_t	i;

	mypointer = pointer;
	i = 0;
	while (i < size)
	{
		mypointer[i] = value;
		i++;
	}
	return (mypointer);
}
