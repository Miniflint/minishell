/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:32:40 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:32:41 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	char	*psrc;

	psrc = (char *)src;
	i = 0;
	if (destsize == 0)
		return (ft_strlen(psrc));
	while (psrc[i] && i < (destsize - 1))
	{
		dest[i] = psrc[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(psrc));
}
