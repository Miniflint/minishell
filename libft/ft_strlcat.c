/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:32:37 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:32:37 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dlength;
	size_t	slength;

	dlength = ft_strlen(dest);
	slength = ft_strlen(src);
	i = 0;
	if (destsize == 0)
		return (slength);
	if (destsize < dlength)
		return (destsize + slength);
	while (src[i] && dlength + i < destsize - 1)
	{
		dest[dlength + i] = src[i];
		i++;
	}
	dest[dlength + i] = 0;
	return (dlength + slength);
}
