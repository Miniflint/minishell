/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:31:53 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:31:53 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;
	char	c2;

	s2 = (char *)s;
	c2 = (char)c;
	i = 0;
	while (i < n)
	{
		if (s2[i] == c2)
			return (s2 + i);
		i++;
	}
	return (NULL);
}
