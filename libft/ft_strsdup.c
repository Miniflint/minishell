/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:33:04 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:33:05 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char **strs)
{
	char			**ret;
	unsigned int	i;

	i = 0;
	while (strs[i])
		i++;
	ret = malloc((i + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		ret[i] = strs[i];
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
