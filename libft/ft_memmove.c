/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:32:04 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:32:04 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*pdest;
	char	*psrc;

	psrc = (char *)src;
	pdest = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (pdest > psrc)
	{
		while (len > 0)
		{
			pdest[len - 1] = psrc[len - 1];
			len--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			pdest[i] = psrc[i];
	}
	return (pdest);
}
