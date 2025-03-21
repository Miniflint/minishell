/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:32:34 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:32:34 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*ret;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	ret = str;
	if (!str)
		return (0);
	if (s1)
		while (*s1)
			*(str++) = *(s1++);
	if (s2)
		while (*s2)
			*(str++) = *(s2++);
	*str = 0;
	return (ret);
}
