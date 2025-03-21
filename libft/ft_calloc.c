/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:30:01 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:30:40 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s1;

	s1 = (char *)malloc(count * size);
	if (!s1)
		return (NULL);
	ft_bzero(s1, count * size);
	return (s1);
}
