/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ppointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herolle <herolle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:30:00 by herolle           #+#    #+#             */
/*   Updated: 2025/03/21 19:30:40 by herolle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_ppointer(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
		array = NULL;
	}
}
