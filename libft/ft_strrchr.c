/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:33:00 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:33:01 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slength;

	slength = (ft_strlen(s));
	while (slength >= 0)
	{
		if (s[slength] == (char)c)
			return ((char *)s + slength);
		slength--;
	}
	return (NULL);
}
