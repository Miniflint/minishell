/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:33:12 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:33:12 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	f_len;

	if (!s)
		return (0);
	f_len = ft_strlen(s);
	if (start >= f_len)
		return (ft_strdup(""));
	if (len > f_len - start)
		len = f_len - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
